#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

int kthlargest(int arr[], int N, int K)
{
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        pq.push(-arr[i]);
        if (pq.size() > K)
            pq.pop();
    }
    return -pq.top();
}
int main()
{

    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--)
	{
        int n,k; 
        cin>>n>>k; int a[n];
        rep(i,0,n){cin>>a[i];}
        ll kthlarge=kthlargest(a,n,k);
        // timecomplexity bestcase,averagecase,worstcase O(nlogk)
        // spacecomplexity O(k)
        // too verify solution
        sort(a,a+n,greater<int>());
        cout<<kthlarge<<" --> "<<a[k-1]<<"\n";
	}
}