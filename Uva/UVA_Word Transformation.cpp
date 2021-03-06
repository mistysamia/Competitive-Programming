#include <bits/stdc++.h>
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

string s[1000];

ll cnt(string root, string des,ll slen)
{
    ll len,co=0;
    len=root.length();

    for(int i=0; i<len; i++)
    {
        if(root[i]!=des[i])
        {
            for(int j=0; j<slen; j++)
            {
                if(s[j].length==len && root[i]==s[j][i])
                {
                    co++;
                    break;
                }
            }
        }
    }
    return co;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string input;
        ll in=0;
        while(cin>>input)
        {
            if(input=="*")
                break;

            s[in++]=input;
        }
        string root,des;
        for(int i=0; i<2; i++)
        {
            cin>>root>>des;
            ll ans=cnt(root,des,in);
            cout<<ans<<endl;
        }


    }
    return 0;
}
