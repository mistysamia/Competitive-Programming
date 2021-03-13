#include<stdio.h>
int main()
{
    long long int n,i,j,sum,tot,k,l,m,pp,temp,r,s,t;

    while(( scanf("%lld%lld",&i,&j))!=EOF)
    {
        pp=j;
        s=i;
        tot=0;
        if(i>j)
        {
            r=j;
            j=i;
            i=r;
        }
        while(j>=i)
        {
            n=j;
            sum=1;
            while(1)
            {
                if(n==1)
                {
                    break;
                }
                else if(n%2==0)
                {
                    n=n/2;
                    sum++;
                }
                else
                {
                    n=3*n+1;
                    sum++;
                }
            }
            if(tot<sum)
            {
                tot=sum;
            }

            j--;
        }
        printf("%lld %lld %lld\n",s,pp,tot);


    }
    return 0;
}
