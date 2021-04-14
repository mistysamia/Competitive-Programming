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
    ll t,cas=1,n;

    while(cin>>n)
    {
        map<char,ll>mp;
        map<ll,ll>mp1,mp2;
        string s,s1;
        vector<ll>adj[500];
        deque<ll>deq;
        char ch1,ch2;
        ll lock=0,sum=0,co=0,ans=0,a=0,b=0,c=0,d=0;
        ll m,k,mx=-BIG,mn=BIG;
        ll fir=0,sec=0,x=0,y=0,in=0;
        cin>>m;
        cin>>s;
        for(int i=0; i<3; i++)
        {
            if(mp.find(s[i])==mp.end())
                mp[s[i]]=in++;

            mp1[mp[s[i]]]++;
        }
        for(int i=0; i<m; i++)
        {
            cin>>ch1>>ch2;
            if(mp.find(ch1)==mp.end())
                mp[ch1]=in++;

            if(mp.find(ch2)==mp.end())
                mp[ch2]=in++;

            adj[mp[ch1]].push_back(mp[ch2]);
            adj[mp[ch2]].push_back(mp[ch1]);
        }

        for(int i=2;i<in;i++)
        {
            for(auto it=mp1.begin(); it!=mp1.end(); it++)
            {
                for(int j=0; j<adj[it->ff].size(); j++)
                {
                    if(mp1.find(adj[it->ff][j])==mp1.end())
                        mp2[adj[it->ff][j]]++;
                }
            }

            for(int j=0; j<in; j++)
            {
                if(mp2[j]>=3)
                {
                    mp1[j]++;
                    lock=1;
                }
            }
            mp2.clear();
            if(lock)
            {
                sum++;
                if(mp1.size()>=n)
                    break;
            }
            else
                break;
            lock=0;
        }

        if(mp1.size()<n)
        {
            cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
        }
        else
        {
            cout<<"WAKE UP IN, "<<sum<<", YEARS"<<endl;
        }
        //ll str[n+3];
        //ll len=s.length();
    }
}


