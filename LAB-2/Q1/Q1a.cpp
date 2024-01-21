#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
int* merge(int* af, int* bf,int* al, int* bl){
    int n = (al-af)+(bl-bf);
    int* a = new int[n];
    int i=0,j=0;
    while(i<(al-af) && j<(bl-bf)){
        if( *(af+i)<*(bf+j) ){}
    }
}

int main()
{
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int n; cin>>n; 
    ll a,first_mx=LONG_LONG_MIN,second_mx=LONG_LONG_MIN;
    rep(i,0,n){
      cin>>a; 
      second_mx=min(first_mx,max(second_mx,a));
      first_mx=max(first_mx,a);
    } 
    cout<<first_mx+second_mx<<"\n";
}