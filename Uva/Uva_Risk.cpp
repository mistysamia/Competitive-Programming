#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[10000];
ll level[1000];
ll shortest_path[10000]; ///shortest path er value ta save korbo

void BFS(ll source)
{
    queue<ll> q;
    for(int i=0; i<=100; i++)
        level[i]=-1;
    for(int i=0; i<=100; i++)
        shortest_path[i]=0;

    q.push(source);
    level[source]=0;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            if(level[adj[u][i]]==-1 )
            {
                level[adj[u][i]]=0;
                shortest_path[adj[u][i]]= shortest_path[u]+1;// shortest path er way number save er jonno
                q.push(adj[u][i]);
            }
        }
    }
}
int main()
{
    ll cas,input;
    ll test_set=1;
    while(cin>>cas)
    {
        while(cas--)
        {
            cin>>input;
            adj[1].push_back(input);
            adj[input].push_back(1);
        }
        for(int i=2; i<=19; i++)
        {
            cin>>cas;
            while(cas--)
            {
                cin>>input;
                adj[i].push_back(input);
                adj[input].push_back(i);
            }

        }
        ll n;
        cin>>n;
        cout<<"Test Set #"<<test_set<<endl;

        while(n--)
        {
            ll root,des;
            cin>>root>>des;
            BFS(root);
            if(root<10)
                cout<<" "<<root;
            else
                cout<<root;
            cout<<" to ";
            if(des<10)
                cout<<" "<<des;
            else
                cout<<des;

            cout<<": ";
            cout<<shortest_path[des]<<endl;
        }
        cout<<endl;
        for(int i=0; i<=20; i++)
            adj[i].clear();

        test_set++;
    }
    return 0;
}
