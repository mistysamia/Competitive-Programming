
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[20000];
int level[20000];
int start[20000];
int finish[20000];
void DFS(int source ,int n)
{
    stack<int> q;
    memset(level,-1,sizeof(level));
    q.push(source);
    level[source]=0;
    finish[source]=1;
    while(!q.empty())
    {
        int u=q.top();
        ///here u can visit all the nodes;
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(level[adj[u][i]]==-1)
            {
                level[adj[u][i]]=0;
                finish[adj[u][i]]=1;
                q.push(adj[u][i]);
            }

        }
    }
}
int main()
{
    memset(start,-1,sizeof(start));
    int n,m;
    cin>>n>>m;
    int temp1,temp2;
    if(m!=(n-1))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        cin>>temp1>>temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }

   /* int root;
    cin>>root;*/
    DFS(1,n);
    for(int i=1; i<=n; i++)///if it is a disconnected graph
    {
        if(finish[i]==0)
        {
            //cout<<i<<endl;
            cout<<"NO"<<endl;
            return 0;
        }
    }

        cout<<"YES"<<endl;

    return 0;
}
