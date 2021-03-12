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
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006],tra1[100006];


int main()
{
    fast_cin;
    ll t;
    cin>>t;
    while(t--)
    {
        map<string,string>mp;
        map<string,string>::iterator it;
        map<string,ll>mpp;
        map<string,ll>::iterator itt;
        string s,s1;
        // deque<ll>deq;
        ll lock=0,sum=0,co=0,ans=-1,a=0,b=0;
        ll n,m,k;

        cin>>n;
        cin.ignore();
        ll fir=0,sec=0;
        for(int i=0; i<n; i++)
        {
            getline(cin,s);
            getline(cin,s1);
            mp[s]=s1;
        }

         /*for(it=mp.begin(); it!=mp.end(); it++)
         {
             cout<<it->ff<<"    "<<it->ss<<endl;
         }
         cout<<endl<<endl;*/
        cin>>m;
        cin.ignore();
        for(int i=0; i<m; i++)
        {
            getline(cin,s);
            if(mp.find(s)!=mp.end())
                mpp[s]++;
        }
        for(itt=mpp.begin(); itt!=mpp.end(); itt++)
        {
            a=itt->ss;
            if(a>ans)
            {
                ans=a;
                s=itt->ff;
            }
        }
        for(itt=mpp.begin(); itt!=mpp.end(); itt++)
        {
            if(ans==itt->ss)
                b++;
        }

        if(b>1)
            cout<<"tie"<<endl;
        else
            cout<<mp[s]<<endl;
        if(t)
            cout<<endl;
    }
}


