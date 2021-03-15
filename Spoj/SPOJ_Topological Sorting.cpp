#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define white 0
#define gray -1
#define black 1

vector<ll>adj[10006];// main grid
bool visited[10006]= {false};// check the node is visited or not
ll startingTime[10006],finishingTime[10006];
stack<ll>save;// To store the node
ll color[10006];// check the node color
ll Time=1;
ll CycleExist=0;

bool compare(ll a,ll b)
{
    if(a>b)
        return true;
    else
        return false;
}

void DFS(ll source,ll n)
{
    if(visited[source])
        return;
    visited[source]=true;
    color[source]=gray;
    startingTime[source]=Time++;

    for(int i=0; i<adj[source].size(); i++)
    {
        ll u=adj[source][i];
        if(visited[u]==true && color[u]==gray)
        {
            CycleExist=1;
            return;
        }
        else if(visited[u]==false)
            DFS(u,n);
    }

    finishingTime[source]=Time++;
    color[source]=black;
    save.push(source);
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll temp1,temp2;
    for(int i=0; i<m; i++)
    {
        cin>>temp1>>temp2;
        adj[temp1].push_back(temp2);
    }


    for(int i=1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end(),compare);


    for(int i=n; i>=1; i--)
    {
        if(!visited[i])
            DFS(i,n);
    }

    if(CycleExist)
    {
        cout<<"Sandro fails."<<endl;
        return 0;
    }
    while(!save.empty())
    {
        cout<<save.top()<<" ";
        save.pop();
    }
    cout<<endl;
    return 0;
}

