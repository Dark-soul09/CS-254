#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    // genrating random input
    freopen("test_cases_Q5.txt","w",stdout);
    int n=10000; cout<<n<<"\n";
    rep(i,0,n){cout<<rand()<<" ";} cout<<"\n";
    fclose (stdout);

    freopen("test_cases_Q5.txt","r",stdin);
    freopen("output_Q5.txt","w",stdout);
    cin>>n; 
    ll a,first_mn=LONG_LONG_MAX,second_mn=LONG_LONG_MAX;
    rep(i,0,n){
      cin>>a; 
      second_mn=max(first_mn,min(second_mn,a));
      first_mn=min(first_mn,a);
    } 
    cout<<"\nfirst minimum : "<<first_mn<<"\nsecond minimum : "<<second_mn<<"\n";

    // linear time complexity
}