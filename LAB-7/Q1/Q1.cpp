#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a-1; i >=b; --i)
#define all(v) v.begin(), v.end()
#define pii pair<int,int> 
#define Mx vector<vector<int>>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
# define mod 998244353 
bool comp(vector<int> &v1,vector<int> &v2){
  return (v1[2]/v1[1]) < (v2[2]/v2[1]);
}

void greedy(Mx& a,int W){
    int n=a.size();
    sort(all(a),comp);
    vector<int> ans;
    int i=n-1,wt=0,val=0;
    while(i>-1 && a[i][1]+wt<=W){
        wt+=a[i][1];
        val+=a[i][2];
        ans.emplace_back(a[i][0]);
        i--;
    }
    cout<<"FROM GREEDY APPROCAH THE SOLUTION\t";
    cout<<val<<"\n";
    cout<<"The indices are\n";
    for(auto x : ans){ cout<<x<<" "; }
    cout<<"\n";
}

void knapsackOptimal(Mx& items, int weight_limit) {
    int n = items.size();
    Mx dp(n + 1, vector<int>(weight_limit + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= weight_limit; ++w) {
            if (items[i - 1][1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1][1]] + items[i - 1][2]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<int> selected_items;
    int total_value = dp[n][weight_limit];
    int remaining_weight = weight_limit;

    for (int i = n; i > 0 && total_value > 0; --i) {
        if (total_value != dp[i - 1][remaining_weight]) {
            selected_items.push_back(items[i - 1][0]);
            total_value -= items[i - 1][2];
            remaining_weight -= items[i - 1][1];
        }
    }

    cout<<"FROM OPTMIAL APPROCAH THE SOLUTION\t";
    cout<<dp[n][weight_limit]<<"\n";
    cout<<"The indices are\n";
    for(auto x : selected_items){ cout<<x<<" "; }
    cout<<"\n";
    
    return ;
}

int main()
{
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--)
	{
        int n,W; cin>>n>>W;
        Mx a(n,vector<int>(3));
        rep(i,0,n){ a[i][0]=i+1;}
        rep(i,0,n){ cin>>a[i][1];}
        rep(i,0,n){ cin>>a[i][2];}
        greedy(a,W);
        knapsackOptimal(a,W);
        cout<<"\n\n";
	}
}