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
    //map<ll,ll>mp;
    // map<ll,ll>::iterator it;
    string s,s1;
    // deque<ll>deq;
    ll lock=0,sum=0,co=0,ans,a=0,b=0,c=0;
    ll n,m,k,mx=-BIG,mn=BIG;
    ll fir=0,sec=0;
    //ll str[n+3];
    //ll len=s.length();
    while(cin>>s>>t)
    {
        if(s=="0" && t==0)
            break;

        if(s[0]=='0' && s[1]=='x')
        {
            s[1]='0';
            n=stoi(s,0,16);
        }
        else if(s[0]=='0')
            n=stoi(s,0,8);
        else
            n=stoi(s,0,10);

        ans=0;
        while(t--)
        {
            string ss;
            cin>>ss>>m;
            if(ss=="i++")
            {
                if(m==n)
                    ans++;
                m+=1;
            }
            else if(ss=="++i"&& m==n+1)
                ans++;
            else if(ss=="i--")
            {
                if(m==n)
                    ans++;
                m-=1;
            }
            else if(ss=="--i" && m==n-1)
                ans++;
            else if(ss=="i" && m==n)
                ans++;
            n=m;
        }
        cout<<ans<<endl;
    }
}
