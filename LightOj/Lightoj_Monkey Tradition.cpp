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
#define all(v) (v).begin(), (v).end()
#define b(n) cout<<"bug "<<n<<endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000

ll mod=1e9+7;
ll n,M;
deque<ll>str,rem;


//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006],tra1[100006];

ll power (ll x, ll n, ll mod)
{
    x=x%mod;
    if(n==0)
        return 1;

    if(n%2==0)
    {
        ll temp=(x*x)%mod;
        return power (temp,n/2, mod);
    }
    else
    {
        ll temp= power(x,n-1,mod)*x;
        return temp%mod;
    }
}
ll inverse (ll x,ll mod)
{
    return power(x,mod-2,mod);
}

ll crt()
{
    ll a=0,b=0,sum=0;
    for(int i=0; i<n; i++)
    {
        ll res=M/str[i];
        ll temp=inverse(res,str[i]);
        //cout<<res<<" "<<temp<<endl;
        ll ans = (rem[i]*res*temp)%M;
        //cout<<ans<<" "<<x<<endl;
        sum=(sum+ans)%M;
        //cout<<x<<endl;
    }

    return sum;
}

void clr()
{
    str.clear();
    rem.clear();
    M=1;
}

int main()
{
    fast_cin;
    ll t,cas=1;
    cin>>t;
    while(t--)
    {
        //map<ll,ll>mp;
        // map<ll,ll>::iterator it;
        string s,s1;
        // deque<ll>deq;
        ll lock=0,sum=0,co=0,ans=0,a,b,c=0,d=0;
        ll m,k,mx=-BIG,mn=BIG;
        ll fir=0,sec=0,x=0,y=0;
        cin>>n;
        clr();
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            str.push_back(a);
            rem.push_back(b);
            M*=str[i];
        }
        ans=crt();
        cout<<"Case "<<cas++<<": "<<ans<<endl;


        //ll len=s.length();
    }
}


