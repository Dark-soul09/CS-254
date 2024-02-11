#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
#define lmt 100
int main()
{
    freopen("test_cases_Q1.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = rand()%lmt;
	cout<<tt<<"\n";
	while (tt--)
	{
        
        int n = rand()%lmt, m = rand()%lmt;

        cout << n << ' ' << m  << endl;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = rand();

                cout << x%2 << ' ';
            }

            cout << endl;
        }
	}
}