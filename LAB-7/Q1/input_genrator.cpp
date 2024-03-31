#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
#define lmt 100
#define lmt2 1000
int main()
{
    freopen("test_cases_Q1.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = rand()%lmt;
	cout<<tt<<"\n";
	while (tt--)
	{
        
        int n = rand()%lmt, W = rand()%lmt2;

        cout << n << ' ' << W << endl;

        rep(i,0,n){cout<<rand()%lmt+1<<" ";}cout<<"\n";
        rep(i,0,n){cout<<rand()%lmt<<" ";}cout<<"\n";

	}
}