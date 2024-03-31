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

struct Job {
    int id;
    int deadline;
    int profit;
};

bool jobComparator(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

void maximizeProfit(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), jobComparator);

    int n = jobs.size();
    vector<bool> slot(n, false);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result.push_back(jobs[i].id);
                break;
            }
        }
    }

    cout << "Following is the maximum profit sequence of jobs: [";
    for (int id : result) {
        cout << id << ", ";
    }
    cout << "]" << endl;

    int totalProfit = 0;
    for (int i = 0; i < result.size(); i++) {
        for (const Job& job : jobs) {
            if (job.id == result[i]) {
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Total profit = " << totalProfit << endl;
}

int main() {
    
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--)
	{
        int n; cin>>n;
        vector<Job> jobs(n);
        rep(i,0,n){ jobs[i].id=i+1;}
        rep(i,0,n){ cin>>jobs[i].deadline;}
        rep(i,0,n){ cin>>jobs[i].profit;}
        maximizeProfit(jobs);
        cout<<"\n\n";
	}
}
