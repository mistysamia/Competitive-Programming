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

ll DSU(ll n)
{
    init_disjoint_set(n);
    ll cost=0;
    for(int i=0; i<adj.size(); i++)
    {
        ll u=adj[i].from;
        ll v=adj[i].to;
        flag=0;
        Union(u,v);
        if(flag)
            cost++;
    }
    return cost;
}

void clr()
{
    adj.clear();
}

int main ()
{
    ll t;
    cin>>t;
    cin.ignore();

    while(t--)
    {
        clr();

        char A;
        ll n,m;
        cin>>A;
        n=A-64;
        cin.ignore();
        ll temp1,temp2;
        char s[100];
        while(gets(s))
        {
            if(s[0]=='\0')
                break;

            temp1=s[0]-64;
            temp2=s[1]-64;
            adj.push_back({temp1,temp2});
        }

        ll co=DSU(n);
        cout<<n-co<<endl;

        if(t)
            cout<<endl;
    }
}
