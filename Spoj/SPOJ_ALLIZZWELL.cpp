#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 1e5
#define pie 3.14159265358979323
#define minuss 1e-6
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define BIG 1e13
#define N 10000

char grid[150][157];
ll row[]={0,0,1,-1,1,1,-1,-1};
ll col[]={1,-1,0,0,1,-1,1,-1};

bool outside(ll i,ll j,ll n,ll m)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return true;

    return false;
}
bool findmatch(string pat,ll n,ll m,ll x,ll y,ll level)
{
    ll l = pat.length();
    if (level == l)
        return true;

    if (outside(x,y,n,m)|| grid[x][y]=='#'|| grid[x][y]!=pat[level])
         return false;

    char temp = grid[x][y];
    grid[x][y] = '#';

    for(int i=0; i<8; i++)
    {
            ll ro=row[i]+x;
            ll co=y+col[i];
            if(findmatch(pat,n,m,ro,co,level+1))
                return true;
    }
    grid[x][y] = temp;
    return false;
}
bool checkMatch( string pat,ll n,ll m)
{
    ll l = pat.length();
    if (l > n*m)
        return false;

    for (ll i = 0; i <n; i++)
         for (ll j = 0; j <m; j++)
            if (grid[i][j] == pat[0] &&findmatch(pat,n,m,i, j, 0))
                return true;

    return false;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        cin.clear();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>grid[i][j];

        string pat="ALLIZZWELL";
        if (checkMatch(pat,n,m))
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
        memset(grid,0,sizeof(grid));
    }
}
