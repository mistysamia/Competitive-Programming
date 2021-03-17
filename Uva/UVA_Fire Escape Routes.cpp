#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define MP make_pair
#define llu unsigned long long
#define U unsigned int
#define ff first
#define ss second
#define b(n) cout<<"bug "<<n<<endl;
#define en cout<<endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000
ll mod=1000000007;


ll parent[100006],child[100006];

void makeset(ll u)
{
    parent[u]=u;
    child[u]=1;
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
        child[v]+=child[u];
        child[u]=0;
    }
}

int main()
{
    fast_cin;
    ll t;
    cin>>t;
    while(t--)
    {
        ll lock=0,sum=0,co=1,ans=0,a=0,b=0,c=0;
        ll n,m,k,mx=-BIG,mn=BIG;
        ll fir=0,sec=0;
        cin>>n>>m;
        init_disjoint_set(n);
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            Union(a,b);
        }
        for(int i=1;i<=n;i++)
        {
            if(parent[i]==i)
            {
                sum++;
                co=((co)*(child[i]))%mod;
            }
        }
        cout<<sum<<" "<<co<<endl;
    }
}
