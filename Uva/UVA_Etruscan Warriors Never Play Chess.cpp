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
#define last 1000000000
/*
std::cout << std::fixed;
std::cout << std::setprecision(1);
std::cout << VALUE NAME<<endl;
*/
ll tra[100006],tra1[100006];

ll lastOccurrence(ll key)
{
    ll left=1,right=last,index=-1,mid,check;
    while(left<=right)
    {
        mid=(left+right)/2;
       // cout<<mid<<endl;
        check=(mid*(mid+1))/2;
        if(check==key)
        {
           // cout<<mid<<endl;
            return mid;
        }
        else if(check>key)
            right=mid-1;
        else
            left = mid + 1;
    }
    return left-1;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=lastOccurrence(n);
        cout<<ans<<endl;
    }
}


