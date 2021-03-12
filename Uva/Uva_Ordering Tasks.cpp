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
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define BIG 100000000
#define N 10000
ll all[1000];
int main()
{
    ll n,m;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        vector<ll>grid[1000];
        queue<ll>q;
        memset(all,0,sizeof(all));
        for(int i=0; i<m; i++)
        {
            ll a,b;
            cin>>a>>b;
            grid[a].push_back(b);
            all[b]++;
        }

        for(int i=1; i<=n; i++)
            if(all[i]==0)
                q.push(i);

        ll save=0;
        while(!q.empty())
        {
            save=q.front();
            q.pop();
            cout<<save<<" ";
            for(int i=0; i<grid[save].size(); i++)
            {
                ll index=grid[save][i];
                --all[index];
                if(all[index]==0)
                    q.push(index);
            }
        }
        cout<<endl;
        for(int i=0; i<m; i++)
            grid[i].clear();

    }
}
