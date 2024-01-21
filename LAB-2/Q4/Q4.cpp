#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex < k) {
            return quickSelect(arr, pivotIndex + 1, high, k);
        } else {
            return quickSelect(arr, low, pivotIndex - 1, k);
        }
    }

    return -1;
}

double findMedian(int* start, int* end) {
    int size = end - start;
    int k1 = (size - 1) / 2;
    int k2 = size / 2;

    int median1 = quickSelect(start, 0, size - 1, k1);
    int median2 = quickSelect(start, 0, size - 1, k2);

    return (median1 + median2) / 2.0;
}

int main() {
    // genarating random array of size 100000
    freopen("test_cases_Q4.txt","w",stdout);
    cout<<100000<<"\n"; 
    rep(i,0,100000){cout<<rand()<<" ";} cout<<"\n"; 
    fclose (stdout);


    freopen("test_cases_Q4.txt","r",stdin);
    freopen("output_Q4.txt","w",stdout);
    
    int n; cin>>n; int b[n]; 
    rep(i,0,n){cin>>b[i];} 

    cout << "Median: " << findMedian(b,b+n) << endl; 

    // for checking median through sorting
    sort(b,b+n);
    cout<<"for verifing median through sorting : ";
    if(n%2==0){
        cout<<(b[n/2] + b[n/2 - 1])/2.0<<"\n";
    }
    else{
        cout<<b[n/2]<<"\n";
    }

    return 0;
}
