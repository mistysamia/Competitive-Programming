#include <bits/stdc++.h>
#include<iostream>
#include<string>
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
ll  lcm(ll a,ll b)
{
    ll GCD=__gcd(a,b);
    ll lcm=(a*b)/GCD;
    return lcm;
}
ll dp[109][100];
ll weight[1000];
ll call(ll n,ll c,ll total,ll sum)
{

    if(c==sum)
        return 1;
    if(n==total)
         return 0;


    if(dp[n][c]!=-1)
        return dp[n][c];

    ll res1=0,res2=0;

    if(weight[n]+c<=sum)
        res1=call(n+1,c+weight[n],total,sum);


    res2=call(n+1,c,total,sum);
   // cout<<res1<<" "<<res2<<" "<<n<<endl;
    dp[n][c]= (res1|res2);
    return dp[n][c];
}
int main()
{
    ll t;
    cin>>t;
    getchar();
    while(t--)
    {
        string total;
        getline(cin,total);
        stringstream ss(total);
        int sum=0,val;
        int i=0;
        while(ss>>val)
        {
            weight[i++]=val;
            sum+=val;
        }
        if(sum%2==0)
        {
            memset(dp, -1, sizeof(dp));
           sum>>=1;
           //cout<<i<<" "<<sum<<endl;
            if(call(0,0,i,sum))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;

        ss.clear();
        total.clear();
    }

    return 0;
}

