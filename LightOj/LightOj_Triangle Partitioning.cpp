#include<bits/stdc++.h>
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
#define pair pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define N 10000
/*
std::cout << std::fixed;
std::cout << std::setprecision(1);
std::cout << VALUE NAME<<endl;
*/
ll tra[100006],tra1[100006];
double squareRoot(double n) {
    double low = 0, high = 1e4;
    for(int i=0; i<100; i++) {
        double mid = (low+high)/2.0;
        if(mid*mid>n) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    return low;
}

int main()
{
    fast_cin;
    ll t;
    cin>>t;
    ll cas=1;
    while(t--)
    {
        double a,b,c,m;
        cin>>a>>b>>c>>m;

        double fir=squareRoot(m);
        double sec=squareRoot(m+1);
        double sum=(fir/sec)*a;

        std::cout << std::fixed;
        std::cout << std::setprecision(10);
        std::cout<<"Case "<<cas<<": " <<sum<<endl;
        cas++;
    }
}
