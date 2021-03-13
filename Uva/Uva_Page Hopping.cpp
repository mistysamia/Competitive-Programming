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
        }
    }
}

int main()
{

    ll kas=1;
    while(1)
    {
        ll n,m,sum=0;
        cin>>n>>m;
        clr();
        ll ind=1;
        if(n==0 &&m==0)
            break;
        ll weight=1;
        map<ll,ll>mp,mp1;

        mp[n]=ind++;
        if(mp[m]==0)
            mp[m]=ind++;
        adj[mp[n]][mp[m]]=weight;

        while(1)
        {
            cin>>n>>m;
            if(n==0 &&m==0)
                break;

            if(mp[n]==0)
                mp[n]=ind++;
            if(mp[m]==0)
                mp[m]=ind++;

            adj[mp[n]][mp[m]]=weight;
        }

        ind--;
        FloydWarshall(ind);
        for(int i=1; i<=ind; i++)
        {
            for(int j=1; j<=ind; j++)
            {
                if(i!=j && adj[i][j]!=BIG)
                    sum+= adj[i][j];
            }
        }
        ll co=ind*(ind-1);
        double ans=(double)sum/co;
        cout<<"Case "<<kas++<<": ";
        cout<<"average length between pages = ";
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << ans<<" clicks"<<endl;
    }
    return 0;
}
