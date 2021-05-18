#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005
#define BIG 1000000000000005
typedef pair<ll, ll> pii;

vector<pii> adj[SIZE];        /// Graph
ll dis[SIZE];
ll vis[SIZE];

struct Node
{
    ll node;
    ll weight;
    Node()
    {
    }
    Node(ll node,ll weight)
    {
        this->node = node;
        this->weight = weight;
    }
    bool operator < (const Node &a)const
    {
         return weight > a.weight;
    }


};

priority_queue<Node> Q;

void  dijkstra(ll main_source)
{
    while(!Q.empty())
        Q.pop();
    for(int i=0; i<SIZE; i++)
    {
        dis[i] = BIG;
        vis[i]=BIG;
    }
    Node s(main_source, 0);
    Q.push(s);
    dis[main_source] = 0;
    while(!Q.empty())
    {
        Node current = Q.top();
        Q.pop();
        ll source = current.node;
        for(int i=0; i<adj[source].size(); i++)
        {
            ll des = adj[source][i].first;
            ll cost = adj[source][i].second;
            if(dis[source]+cost < dis[des])
            {
                if(dis[des]<vis[des])
                    vis[des]=dis[des];

                dis[des] = dis[source] + cost;
                Node n(des,cost);
                Q.push(n);
            }
            else if((vis[des]>dis[source]+cost)&&(dis[des]!=dis[source]+cost ))
            {
                vis[des]=dis[source]+cost;
                Node n(des, cost);
                Q.push(n);
            }
            else if(vis[source]+cost<vis[des])
            {
                vis[des]=vis[source]+cost;
                Node n(des, cost);
                Q.push(n);
            }
        }
    }
}
int main ()
{
    ll t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        ll n, m;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            ll a, b,w;
            cin>>a>>b>>w;

            adj[a].push_back(pii(b, w));
            adj[b].push_back(pii(a, w));
        }

        dijkstra(1);

        cout<<"Case "<<k<<": "<<vis[n]<<endl;
        for(int i=0; i<SIZE; i++)
        adj[i].clear();
    }
    return 0;
}
