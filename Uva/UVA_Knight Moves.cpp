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
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)



ll sourcex, sourcey, desx, desy;
ll vis[100][100];
ll visited[100][100];
map<char,ll>mp;

#define pii pair<ll, ll>
ll fx[] = {2,2, -2,-2, 1, 1,-1,-1};
ll fy[] = {1,-1, 1,-1, 2, -2,2,-2};


ll BFS(pair<ll, ll> source)
{
    memset(vis, 0, sizeof vis);
    memset(visited, -1, sizeof visited);

    vis[source.first][source.second] = 0;
    visited[source.first][source.second]=1;

    queue<pii> q;
    q.push(source);
    while (!q.empty())
    {
        pii top = q.front();
        q.pop();


        for (int k = 0; k < 8; k++)
        {
            ll tx = top.first + fx[k];
            ll ty = top.second + fy[k];
            if (tx>=0 && tx<8 && ty>=0 && ty<8)
            {
                if (visited[tx][ty] == -1)
                {
                    visited[tx][ty]=1;
                    vis[tx][ty] = vis[top.first][top.second] + 1;
                    q.push({tx,ty});
                }
            }
            if (tx==desx && ty== desy)
                return vis[tx][ty];
        }

    }
}
void set_array()
{
    char ch='a';
    for(int i=0; i<8; i++)
        mp[ch++]=i;
}
int main()
{
    set_array();
    string a,b;
    while ((cin>>a>>b))
    {
        sourcex=mp[a[0]];
        sourcey=(a[1]-'0')-1;

        desx=mp[b[0]];
        desy=(b[1]-'0')-1;


        ll ans= BFS({sourcex, sourcey});
        cout<<"To get from "<<a<<" to "<<b;
        cout<<" takes "<<ans<<" knight moves."<<endl;
    }

    return 0;
}
