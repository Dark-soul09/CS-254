#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

//a+n*b
ll merge(int* start, int m, int* end){
    int mx = max(*(start+(m-1)),*(end-1)) + 1;
    int n = end - start,i = 0,j = m,k = 0;
    ll inversions = 0;
    while(i < m && j < n && k < n){
        int a = *(start+i) % mx;
        int b = *(start+j) % mx;
        if(a<=b){
            *(start+k) += (a*mx);
            i++; k++;
        }
        else{
            inversions+=(m-i);
            *(start+k) += (b*mx);
            j++; k++;
        }
    }

    while(i < m){
        int a = *(start+i) % mx;
        *(start+k) += (a*mx);
        i++; k++;
    }
    while(j < n){
        int b = *(start+j) % mx;
        *(start+k) += (b*mx);
        j++; k++;
    }

    rep(l,0,n) *(start+l) /= mx;
    return inversions;
}

ll mergesort(int* start, int* end){
    if((end - start) < 2) return 0;
    int m =  (end - start) / 2;
    ll inversions = 0;
    inversions+=mergesort(start,start+m);
    inversions+=mergesort(start+m,end);
    inversions+=merge(start,m,end);
    return inversions;
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
        int n; cin>>n; int a[n];
        rep(i,0,n){cin>>a[i];}
        ll inversions=mergesort(a,a+n);
        // timecomplexity bestcase,averagecase,worstcase O(nlogn)
        // spacecomplexity INPLACE bestcase,averagecase,worstcase considering stack(recursive calls) O(logn)
        cout<<inversions<<"\n";
	}
}