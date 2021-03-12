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
    cin>>t;
    ll cas=1;
    while(t--)
    {
        map<ll,ll>mp;
        map<ll,ll>::iterator it;
        string s,s1;
        // deque<ll>deq;
        ll lock=0,sum=0,co=0,ans=0,a=0,b=0,c=0;
        ll n,m,k,mx=-BIG,mn=BIG;
        cin>>n;
        ll fir=0,sec=0;
        ll str[n+3];
        for(int i=0; i<n; i++)
        {
            cin>>str[i];
            mp[str[i]]++;
        }
        ll i=0,in=0;
        while(i<n)
        {
            if(mp[in-1]>0 || mp[in+1]>0)
            {
                if(mp[in+1]>0)
                {
                    s+='(';
                    in++;
                }
                else
                {
                    s+=')';
                    in--;
                } mp[in]--;
            }
            else
            {
                lock =1;
                break;
            }
            i++;
        }
        if(lock || in!=0)
            cout<<"Case "<<cas++<<": "<<"invalid"<<endl;
        else
            cout<<"Case "<<cas++<<": "<<s<<endl;
    }
}
