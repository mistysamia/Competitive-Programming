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
ll str[10000000],n;
bool check(ll dif)
{
    for(int i=0; i<n; i++)
    {
        if(str[i+1]-str[i]==dif)
            dif--;
        else if(str[i+1]-str[i]<dif)
            continue;
        else
            return false;
    }
    return true;
}
void searchme(ll ind)
{
    ll left=0,right=str[n],mid;

    while(left<=right)
    {
        mid=(left+right)/2;

        if(check(mid))
        {
            right=mid-1;
        }
        else
            left = mid + 1;
    }

    cout<<"Case "<<ind<<": "<<left<<endl;
}
int main()
{
    ll t;
    cin>>t;
    ll cas=1;
    while(t--)
    {
        cin>>n;
        str[0]=0;
        for(int i=1; i<=n; i++)
            cin>>str[i];

        searchme(cas);
        cas++;
    }
}


