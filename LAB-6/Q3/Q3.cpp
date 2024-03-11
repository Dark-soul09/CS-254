#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define Mx vector<vector<int>>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
bool dfs(int curr, int des, vector<vector<int> >& adj,
            vector<int>& vis)
{

    if (curr == des) {
        return true;
    }
    vis[curr] = 1;
    for (auto x : adj[curr]) {
        if (!vis[x]) {
            if (dfs(x, des, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}

bool isPath(int src, int des, vector<vector<int> >& adj)
{
    vector<int> vis(adj.size() + 1, 0);
    return dfs(src, des, adj, vis);
}

vector<vector<int> > findSCC(int n,vector<vector<int> >& adj)
{
    vector<vector<int> > ans;
    vector<int> is_scc(n + 1, 0);

    // vector<vector<int> > adj(n + 1);

    // for (int i = 0; i < a.size(); i++) {
    //     adj[a[i][0]].push_back(a[i][1]);
    // }

    // Traversing all the vertices
    for (int i = 1; i <= n; i++) {

        if (!is_scc[i]) {
            vector<int> scc;
            scc.push_back(i);

            for (int j = i + 1; j <= n; j++) {
                if (!is_scc[j] && isPath(i, j, adj)
                    && isPath(j, i, adj)) {
                    is_scc[j] = 1;
                    scc.push_back(j);
                }
            }
            ans.push_back(scc);
        }
    }
    return ans;
}
int main(){
    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        Mx adj(n+1); int u,v;
        rep(i,0,m){
            cin>>u>>v;
            adj[u].emplace_back(v);
        }
        Mx ans = findSCC(n,adj);
        cout<<"strongly connected components :\n";
        for(auto x:ans){
            for(auto y : x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
    }
}
