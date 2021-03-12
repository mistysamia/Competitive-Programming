#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pair pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define N 10000
/*
std::cout << std::fixed;
std::cout << std::setprecision(1);
std::cout << VALUE NAME<<endl;
*/
ll tra[100006],tra1[100006];

ll k,n;


ll capable(ll capacity,ll str[])
{
    ll new_capacity=capacity,contrainernum=0;
    for(int i=0; i<n; i++)
    {
        if(str[i]>capacity)
            return 0;
        else if(str[i]>new_capacity)
        {
            if(contrainernum==k-1)
                return 0;

            contrainernum++;
            new_capacity=capacity;
        }
        new_capacity-=str[i];
    }
    return 1;
}

ll binary_Search(ll str[])
{
    ll low=1,high=1000000000,mid=0,ans=0;

    while(low<=high)
    {
        mid=(high+low)/2;
        ll lock=capable(mid,str);
        if(lock!=0)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}
int main()
{
    fast_cin;
  //  ll n,k;
    while(cin>>n>>k)
    {
         ll str[n+4];
        for(int i=0; i<n; i++)
            cin>>str[i];

        ll ans=binary_Search(str);
        cout<<ans<<endl;
    }
}

