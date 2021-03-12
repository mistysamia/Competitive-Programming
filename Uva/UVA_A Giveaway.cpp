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


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006],tra1[100006];


int main()
{
    fast_cin;
    ll t;

    while(cin>>t)
    {
        //map<ll,ll>mp;
        // map<ll,ll>::iterator it;
        if(t==0)
            break;

        string s,s1;
        // deque<ll>deq;
        ll lock=0,sum=0,co=0,ans=0,a=0,b=0,c=0;
        ll n,m,k,mx=-BIG,mn=BIG;
       // cin>>n;
        ll fir=0,sec=0;
        //ll str[n+3];
        set<ll>st= {1, 64, 729, 4096, 15625, 46656, 117649,
                    262144, 531441,1000000, 1771561, 2985984,
                    4826809, 7529536, 11390625, 16777216,
                    24137569, 34012224,47045881, 64000000,85766121};
               //ll len=s.length();

        if(st.find(t)==st.end())
            cout<<"Ordinary"<<endl;
        else
            cout<<"Special"<<endl;
    }
}
