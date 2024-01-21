#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;


// Function to find the median among three elements
int findMedian(int a, int b, int c) {
    if ((a >= b && a <= c) || (a >= c && a <= b))
        return a;
    else if ((b >= a && b <= c) || (b >= c && b <= a))
        return b;
    else
        return c;
}

// Function to partition the array and return the index of the pivot
int partition(vector<int>& arr, int low, int high) {
    int pivotValue = findMedian(arr[low], arr[(low + high) / 2], arr[high]);
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivotValue);

        do {
            j--;
        } while (arr[j] > pivotValue);

        if (i >= j)
            return j;

        // Swap arr[i] and arr[j]
        swap(arr[i], arr[j]);
    }
}

// Function to perform QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the partition index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pivotIndex);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // genarating random array of size 100000
    freopen("test_cases_Q6.txt","w",stdout);
    cout<<100000<<"\n"; 
    rep(i,0,100000){cout<<rand()<<" ";} cout<<"\n"; 
    fclose (stdout);


    freopen("test_cases_Q6.txt","r",stdin);
    freopen("output_Q6.txt","w",stdout);
    
    int n; cin>>n; vector<int>b(n); 
    rep(i,0,n){cin>>b[i];} 

    cout<<"for large random input \n";

    cout<<"before sorting is_sorted value of array : "<<is_sorted(all(b))<<"\n"; // before sorting
    quickSort(b,0,n-1);
    cout<<"after sorting is_sorted value of array : "<<is_sorted(all(b))<<"\n"; // after sorting
    rep(i,0,n){cout<<b[i]<<" ";} cout<<"\n"; 

    return 0;
}
