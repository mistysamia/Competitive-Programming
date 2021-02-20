#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 10000005
#define BIG 1000000000000005
#define ff first
#define ss second
typedef pair<ll, ll> pii;


ll parent[SIZE];
map<ll,ll>cou;
ll FindRepresentative(ll r)
{
    if(parent[r]==r)
        return r;

    parent[r]=FindRepresentative(parent[r]);/// path compression

    return parent[r];
}

ll Union(ll a, ll b)
{
    ll u = FindRepresentative(a);
    ll v = FindRepresentative(b);

    if(u!=v)
    {
        parent[u] = v;
        cou[v]+=cou[u];
     //   cout<<v<<" "<<cou[v]<<" "<<u<<" "<<cou[u]<<endl;
    }
    return cou[v];

}


int main ()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n;
        ll in=1;
        map<string,ll>mp;
        cou.clear();
        memset(parent,0,sizeof(parent));
        for(int i=0; i<n; i++)
        {
            string from,to;
            ll co=1;
            cin>>from>>to;
            if(mp[from]==0)
            {
                cou[in]=1;
                parent[in]=in;
                mp[from]=in++;

            }

            if(mp[to]==0)
            {
                cou[in]=1;
                parent[in]=in;
                mp[to]=in++;
            }

            cout<<Union(mp[from],mp[to])<<endl;
        }
    }
}

/*

1
3
Fred Barney
Barney Betty
Betty Wilma

*/
