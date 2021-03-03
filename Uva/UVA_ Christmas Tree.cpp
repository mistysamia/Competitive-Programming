#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define llu unsigned long long
#define U unsigned int
#define ff first
#define ss second
#define b(n) cout<<"bug "<<n<<endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[1006],tra1[100006];
deque<ll>deq[1500];
ll visited[1005];// check if the node is visited or not

ll k,sum,cou=0,tot;


ll sortt(vector<ll>&A)
{
    sum=1;
    sort(A.begin(), A.end(), greater<ll>());
    if(A.size()<k)
        return 1;

    for (int it=0; it<k; it++)
        sum+=A[it];

    return sum;
}

ll vis(ll n)
{
    vector<ll> A;
    visited[n]=-1;
    for(int i=0; i<deq[n].size(); i++)
    {
        ll a=deq[n][i];
        if(visited[a]==0)
        {
            visited[a]=-1;
            ll in=vis(a);
            A.push_back(in);
        }

    }
    return sortt(A);
}


int main()
{
    fast_cin;
    ll t;
    cin>>t;
    ll cas=1;
    while(t--)
    {
        cout<<"Case "<<cas++<<": ";
        map<ll,ll>mp;
        map<ll,ll>::iterator it;
        string s,s1;
        ll lock=0,co=0,ans=0,a=0,b=0,c=0;
        ll n,m,mx=-BIG,mn=BIG;
        cin>>n>>k;

        for(int i=0; i<1500; i++)
            deq[i].clear();

        memset(visited, 0, sizeof visited);

        ll fir=0,sec=0;
        // ll str[n+3];
        for(int i=0; i<n-1; i++)
        {
            cin>>a>>b;
            deq[a].push_back(b);
            deq[b].push_back(a);
        }

        cout<<vis(1)<<endl;

    }
}

