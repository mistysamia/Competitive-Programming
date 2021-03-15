#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 1000002
#define pie 3.14159265358979323
#define minuss 1e-6
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll a[1000000];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll str[n+5][1000];
        set<ll>st,st1;
        set<ll>::iterator it,it1;
        map<ll,ll>mp;
        map<ll,ll>::iterator iq;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<2; j++)
            {
                sf("%lld", &str[i][j]);
                if(j%2==0)
                    st.insert(str[i][j]);
                else
                    st1.insert(str[i][j]);
            }
        }
        it=st.begin();
        ll s=*it;
        it1=st1.end();
        ll ss=*--it1;
        int countt=1;
        int q=0;
        for(int i=0; i<n; i++)
        {
            for(int j=str[i][0]; j<=str[i][1]; j++)
            {
                a[j-1]=countt;
                q++;
            }
            countt++;
        }
        ll lock=0;
        for(int i=0; i<q; i++)
        {
            if(a[i]==0)
            {
               lock=1;
            }
            mp[a[i]]++;
        }
        ll sizz=mp.size();
        if(lock==1)
            cout<<sizz-1<<endl;
        else
            cout<<sizz<<endl;

            mp.clear();
            st.clear();
            st1.clear();
            std::fill_n(a, q, 0);
    }
}
