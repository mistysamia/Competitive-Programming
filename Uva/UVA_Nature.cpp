#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005
#define BIG 1000000000000005
#define ff first
#define ss second
typedef pair<ll, ll> pii;

struct edge
{
    ll from, to;

    edge() { }

    edge(ll a,ll b)
    {
        from= a;
        to= b;
    }
};


vector<edge>adj;
ll parent[SIZE];
ll flag;



void makeset(ll u)
{
    parent[u]=u;
}

void init_disjoint_set(ll n)
{
    for(ll i=1; i<=n; i++)
        makeset(i);
}

ll FindRepresentative(ll r)
{
    if(parent[r]==r)
        return r;

    parent[r]=FindRepresentative(parent[r]);/// path compression

    return parent[r];
}

void Union(ll a, ll b)
{
    ll u = FindRepresentative(a);
    ll v = FindRepresentative(b);

    if(u!=v)
    {
        parent[u] = v;
        flag = 1;
    }
}

void DSU(ll n)
{
    init_disjoint_set(n);
    ll cost=0;
    for(int i=0; i<adj.size(); i++)
    {
        ll u=adj[i].from;
        ll v=adj[i].to;
        flag=0;
        Union(u,v);
    }

}

void clr()
{
    adj.clear();
}

int main ()
{

    while(1)
    {
        clr();
        ll n,m;
        cin>>n>>m;
        if(n==0 && m==0)
            break;

        map<string,ll>mp;
        map<ll,ll>mp1;
        string s,s1;
        for(int i=1; i<=n; i++)
        {
            cin>>s;
            mp[s]=i;
        }
        for(int i=0; i<m; i++)
        {
            cin>>s>>s1;
            ll temp1=mp[s];
            ll temp2=mp[s1];
            adj.push_back({temp1,temp2});
        }


        DSU(n);
        ll save=-1*BIG;

        for(int i=1; i<=n; i++)
        {
            mp1[FindRepresentative(parent[i])]++;
            save=max(save, mp1[FindRepresentative(parent[i])]);
        }
        cout<<save<<endl;
    }
}

