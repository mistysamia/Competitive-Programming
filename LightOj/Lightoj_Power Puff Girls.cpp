

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
vector<ll> adj[280];
#define pii pair<ll,ll>
ll fx[]={1,-1,0,0};
ll fy[]={0,0,1,-1};
ll cell[100][100];
ll path[100][100],vis[100][100];
ll n,m;

void BFS(ll sx,ll sy)
{
	memset(vis,0,sizeof vis);
	memset(path,0,sizeof path);
	vis[sx][sy]=1;
	queue<pii>q;
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if(tx>=0 and tx<n and ty>=0 and ty<m and cell[tx][ty]!=-1 and vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				path[tx][ty]=path[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
	}
}
int main()
{
    ll t;
    cin>>t;
    ll cas=1;
    while(t--)
    {
        memset(cell,0,sizeof cell);
        ll ax,ay,bx,by,cx,cy,hx,hy;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<m; j++)
            {
                if(s[j]=='a')
                {
                    ax=i;
                    ay=j;
                }
                else if(s[j]=='b')
                {
                    bx=i;
                    by=j;
                }
                else if(s[j]=='c')
                {
                    cx=i;
                    cy=j;
                }
                else if(s[j]=='h')
                {
                    hx=i;
                    hy=j;
                }
                else if(s[j]=='#' || s[j]=='m')
                    cell[i][j]=-1;
            }
        }
        ll one=0,two=0,three=0;

        BFS(hx,hy);
        one= path[ax][ay];
        two= path[bx][by];
        three= path[cx][cy];
        ll ans=max(one,(max(two,three)));
        cout<<"Case "<<cas<<": ";
        cout<<ans<<endl;
        cas++;
    }

    return 0;
}
/*

a,b,c theke H ee shortest path e jabo :*


Input
2

6 8

########

#...c..#

#......#

#.a.h.b#

#......#

########

5 9

#########

#mmm...c#

#ma.h####

#m....b.#

#########



OUTPUT
Case 1: 2

Case 2: 4

*/
