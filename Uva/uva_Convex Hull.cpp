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
deque<pii>point,up,down,hull;

ll tra[100006],tra1[100006];

//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;


ll orientation(pii p1,pii p2,pii p3)
{
    ll val=(p2.ss-p1.ss)*(p3.ff-p2.ff)-
           (p2.ff-p1.ff)*(p3.ss-p2.ss);

    if (val==0)
        return 0;// Linear
    else if(val>0)
        return 1;//Clockwise
    else
        return 2;//CounterClockwise
}

void convexHull(ll n)
{
    //sort all the point
    sort(point.begin(),point.end());

    for (int i=0; i<n; i++)
    {
        if (orientation(point[0],point[i],point[n-1])==2 || i==n-1 || i==0)
            down.push_back(point[i]);
        if(orientation(point[0],point[i],point[point.size()-1])==1)
            up.push_front(point[i]);
    }

    for(int i=0; i<down.size(); i++)
        hull.push_back(down[i]);

    for(int i=0; i<up.size(); i++)
        hull.push_back(up[i]);
}

void clr()
{
    hull.clear();
    point.clear();
    up.clear();
    down.clear();
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
        ll lock=0,sum=0,co=0,ans=0,a=0,b=0,c=0,d=0;
        ll n,m,k,mx=-BIG,mn=BIG;
        ll fir=0,sec=0,x,y;
        cin>>n;
        char ch;
        clr();
        for(int i=0; i<n; i++)
        {
            cin>>x>>y>>ch;
            if(ch=='Y')
                point.push_back({x,y});
        }

        convexHull(point.size());
        cout<<hull.size()<<endl;
        for (int i=0; i<hull.size(); i++)
            cout<<hull[i].ff<<" "<<hull[i].ss<<endl;

        // cout<<endl;
    }
}



