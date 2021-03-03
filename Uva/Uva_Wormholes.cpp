#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1005
#define BIG 1000000000000005

ll path_cost[SIZE];
ll path_save[SIZE];

vector<pair<ll,ll>>adj[SIZE];

bool bellmanFord(ll source,ll n)
{
    for(int i=0; i<SIZE; i++)
    {
        path_cost[i] = BIG;
        path_save[i] = -1;
    }
    path_cost[source] = 0;

    for(int i=1; i<=n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<adj[j].size(); k++)
            {
                ll des = adj[j][k].first;
                ll cost = adj[j][k].second;

                if(path_cost[j]+cost<path_cost[des])
                {
                    path_cost[des] = path_cost[j]+cost;
                    path_save[des] = j;
                }
            }
        }
    }

    for(int j=0; j<n; j++)
    {
        for(int k=0; k<adj[j].size(); k++)
        {
            ll des = adj[j][k].first;
            ll cost = adj[j][k].second;

            if(path_cost[j]+cost<path_cost[des])
                return false;
        }
    }

    return true;
}

void clr()
{
    for(int i=0; i<SIZE; i++)
        adj[i].clear();
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        clr();
        ll m,n;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            ll from,to, weight;
            cin>>from>>to>>weight;
            adj[from].push_back({to,weight});
        }

        if(!bellmanFord(0,n))
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;
    }
    return 0;
}
