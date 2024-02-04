#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
// for checking the answer is correct or not
double mergeArrays(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = 0;
    vector<int> arr3(n+m);
    while (i<n && j <m)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    // Store remaining elements of first array
    while (i < n)
        arr3[k++] = arr1[i++];
 
    // Store remaining elements of second array
    while (j < m)
        arr3[k++] = arr2[j++];
    int t1=(n+m)/2,t2=m+n-t1-1;
    int ans = arr3[t1]+arr3[t2];
    return (double)ans/2;
}
int main()
{

    freopen("test_cases_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n,m;
        cin >>n>>m;
        int a[n],b[m];
        int i=0,j=0;
        int t1=(n+m)/2,t2=m+n-t1-1,ans=0;
        while(i<n && j<m && i+j<=max(t1,t2)){
            if(a[i]<=b[j]){
                if(i+j == t1 || i+j==t2){ ans+=a[i];}
                i++;
            }
            else {
                if(i+j == t1 || i+j==t2){ ans+=b[j];}
                j++;
            }
        }
        while(i<n && i+j<=max(t1,t2)){
            if(i+j == t1 || i+j==t2){ ans+=a[i];} 
            i++;
        }
        while(j<m && i+j<=max(t1,t2)){
            if(i+j == t1 || i+j==t2){ ans+=b[j];} 
            j++;
        }
        // time complexity worst case O(n)
        // space complexity O(1)
        cout<<(t1==t2 ? ans : (double)ans/2)<<"--->";
        // to check the answer
        cout<<mergeArrays(a,b,n,m)<<"\n";
    }
}