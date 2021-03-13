
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
    //cin>>t;
    while(cin>>t)
    {
        if(t==0)
            break;
        //map<ll,ll>mp;
        priority_queue<ll,vector<ll>,greater<ll>>pr;
        // map<ll,ll>::iterator it;
        string s,s1;
        // deque<ll>deq;
        ll lock=0,sum=0,co=0,ans=0,a=1,b=0,c=0;
        ll n,m,k,mx=-BIG,mn=BIG;

        ll fir=0,sec=0;
        for(int i=0; i<t; i++)
        {
            cin>>a;
            pr.push(a);
        }
        while(!pr.empty())
        {
            if(pr.size()!=1)
                cout<<pr.top()<<" ";
            else
                cout<<pr.top()<<endl;

            pr.pop();
        }

    }
}

