#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
#define lmt 1000
int main()
{
    freopen("test_cases_Q2.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = rand()%lmt;
	cout<<tt<<"\n";
	while (tt--)
	{
        int n=rand()%lmt,m=rand()%lmt;  cout<<n<<" "<<m<<"\n";
		int a[n],b[m]; 
		rep(i,0,n){a[i]=rand()%lmt;}
		rep(i,0,m){b[i]=rand()%lmt;} sort(a,a+n); sort(b,b+n);
        rep(i,0,n){ cout<<a[i]<<" ";} cout<<"\n";
        rep(i,0,m){ cout<<b[i]<<" ";} cout<<"\n";
	}
}