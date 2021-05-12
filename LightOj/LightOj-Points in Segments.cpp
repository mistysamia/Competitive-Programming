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

ll n;

ll lowerBound(ll str[],ll key)
{
    ll left=0,right=n-1,index=-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(str[mid]==key)
            return mid;
        else if(str[mid]>key)
            right=mid-1;
        else
            left = mid + 1;
    }
    return left;
}
ll upperBound(ll str[],ll key)
{
    ll left=0,right=n-1,index=-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(str[mid]==key)
            return mid;
        else if(str[mid]>key)
            right=mid-1;
        else
            left = mid + 1;
    }
    return right;
}
int main()
{
    fast_cin;
    ll t;
    scanf("%lld",&t);
    ll cas=1;
    while(t--)
    {
        ll k;
        scanf("%lld%lld",&n,&k);
        ll str[n+5];
        for(int i=0; i<n; i++)
            scanf("%lld",&str[i]);

        printf("Case %lld:\n",cas);
        cas++;
        while(k--)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            ll low=lowerBound(str,a);
            ll high=upperBound(str,b);
            printf("%lld\n",high-low+1);
        }
    }
}
