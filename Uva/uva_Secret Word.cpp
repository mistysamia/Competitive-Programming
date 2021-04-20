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
#define N 100000

ll mod=1e9+7;

//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006],tra1[100006];
ll failure[N];
string text,pattern;

void build_failure()
{
    failure[0]=failure[1]=0;
    for(ll i=2; i<=pattern.size(); i++)
    {
        ll j=failure[i-1];
        while(1)
        {
            if(pattern[j]==pattern[i-1])
            {
                failure[i]=j+1;
                break;
            }
            if(j==0)
            {
                failure[i]=0;
                break;
            }
            j=failure[j];
        }
    }
   /* for(int i=0; i<=pattern.size(); i++)
        cout<<failure[i]<<" ";

    cout<<endl;*/
}

void clr()
{
    text.clear();
    pattern.clear();
}

int main()
{
    fast_cin;
    ll t,cas=1;
    cin>>t;
    while(t--)
    {
        string s,s1;
        clr();
        ll lock=0,sum=0,co=0,ans=0,a=0,b=0,c=0,d=0;
        ll n,m,k,mx=-BIG,mn=BIG,len=0,in=0;
        ll fir=0,sec=0,x=0,y=0;
        cin>>pattern;
        text=pattern;
        reverse(text.begin(),text.end());
        pattern+=text;

        build_failure();
       // cout<<endl<<text<<endl;
        for(int i=0; i<=pattern.size(); i++)
        {
            if(len<=failure[i])
            {
                in=i-1;
                len=failure[i];
            }
        }
        //  cout<<len<<" "<<in<<endl;
        for(int i=in; len>0; i--,len--)
            cout<<pattern[i];

        cout<<endl;
    }
}



