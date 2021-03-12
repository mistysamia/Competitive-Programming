
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1005
#define BIG 1000000000000005


ll adj[SIZE][SIZE];
ll path_save[SIZE][SIZE];

void FloydWarshall(ll n)
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(adj[i][j]>adj[i][k]+adj[k][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                    path_save[i][j]=path_save[i][k];
                }
            }
        }
    }
}

void clr()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(i!=j)
                adj[i][j]=BIG;
            else
                adj[i][i]=0;

            path_save[i][j] = j;
        }
    }
}

int main()
{
    ll kas=1;
    while(1)
    {
        clr();
        ll n,m;
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        ll ind=1;
        map<ll,string>mp1;
        for(int i=1; i<=n; i++)
        {
            string s;
            cin>>s;
            mp1[i]=s;
        }
        for(int i=1; i<=m; i++)
        {
            ll from,to,weight;
            cin>>from>>to>>weight;
            adj[from][to]=weight;
            adj[to][from]=weight;
        }

        FloydWarshall(n);
        ll save=BIG,sum=0,index=0;
        for(int i=1; i<=n; i++)
        {
            sum=0;
            for(int j=1; j<=n; j++)
                sum+=adj[i][j];

            if(save>sum)
            {
                save=sum;
                index=i;
            }
        }
        cout<<"Case #"<<kas++<<" : "<<mp1[index]<<endl;
    }
    return 0;
}
