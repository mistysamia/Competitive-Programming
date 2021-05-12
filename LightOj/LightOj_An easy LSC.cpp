#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 200



ll save_datait[SIZE][SIZE];
string s1,s2,s[SIZE][SIZE];


///iterative way
void length_iterative(ll n, ll m)
{
    for (int i =1; i <=n; i++)
    {
        for (int j =1; j<=m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                save_datait[i][j] = save_datait[i-1][j-1]+1;
                s[i][j]=s[i-1][j-1]+s1[i-1];
            }
            else
            {
                if(save_datait[i-1][j]>save_datait[i][j-1])
                    s[i][j]=s[i-1][j];
                else if(save_datait[i-1][j]<save_datait[i][j-1])
                    s[i][j]=s[i][j-1];
                else
                    s[i][j]=min(s[i][j-1],s[i-1][j]);

                save_datait[i][j]=max(save_datait[i][j-1],save_datait[i-1][j]);
            }

        }
    }
    return;
}

void clr()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            save_datait[i][j]=0;
            s[i][j]="";
        }
    }
    s1.clear();
    s2.clear();
}
int main()
{
    ll t,cas=1;
    cin>>t;
    while(t--)
    {
        clr();
        cin>>s1>>s2;
        ll len1=s1.length();
        ll len2=s2.length();
        length_iterative(len1,len2);
        if(save_datait[len1][len2]!=0)
            cout<<"Case "<<cas++<<": "<<s[len1][len2]<<endl;
        else
            cout<<"Case "<<cas++<<": :("<<endl;

    }
}

