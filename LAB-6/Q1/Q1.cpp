#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define Mx vector<vector<int>>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
# define mod 998244353
void build(int i, Mx &adj, vector<bool> &vis, stack<int> &s){
    vis[i]=true;
    for(auto x : adj[i]){
        if(!vis[x]) build(x,adj,vis,s);
    }
    s.push(i);
    return;
}
void toplogicalsort(Mx &adj,int n){
    stack<int> s;
    vector<bool> vis(n,false);

    rep(i,0,n){
        if(!vis[i]) build(i,adj,vis,s);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
    return;
}
int main()
{
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        Mx adj(n); int u,v;
        rep(i,0,m){
            cin>>u>>v; u--; v--;
            adj[u].emplace_back(v);
        }
        toplogicalsort(adj,n);
    }
}
