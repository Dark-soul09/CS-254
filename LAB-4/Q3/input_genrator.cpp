#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
#define lmt 1000
int main()
{
    freopen("test_cases_Q3.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = rand()%lmt;
	cout<<tt<<"\n";
	while (tt--)
	{
        int n=rand()%lmt,k=rand()%n;  cout<<n<<" " <<k<<"\n";
        rep(i,0,n){ cout<<rand()%lmt<<" ";} cout<<"\n";
	}
}