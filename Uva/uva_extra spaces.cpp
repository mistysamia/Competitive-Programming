
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

//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006],tra1[100006];


int main()
{
    fast_cin;
    ll t,cas=1;
    cin>>t;
    while(t--)
    {
        string s,s1;
        ll lock=0,sum=0,co=0,a=0,b=0,c=0,d=0;
        ll n,k,mx=-BIG,mn=BIG;
        ll fir=0,sec=0;
        char ch;
        cin>>n;
        cout<<"Case "<<cas++<<":"<<endl;
        cin.ignore();
        while(n--)
        {
            getline(cin,s);
            ch=s[0];
            cout<<s[0];
            for(int i=1; i<s.size(); i++)
            {
                if(ch!=' ' || s[i]!=' ')
                {
                    cout<<s[i];
                    ch=s[i];
                }
            }
            s.clear();
        }
        if(t!=0)
            cout<<endl;
    }

}
