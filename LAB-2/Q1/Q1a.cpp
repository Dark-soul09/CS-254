#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
vector<int> mergeArrays(int arr1[], int arr2[], int n, int m)
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

    return arr3;
}

//  Construct a sorted array C for A ∪ B.
vector<int> union_mergeArrays(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = -1;
    vector<int> arr3;
    while (i<n && j <m)
    {
        if (arr1[i] < arr2[j])
            if(k>=0 && arr3[k]==arr1[i]) i++;
            else {arr3.push_back(arr1[i++]); k++;}
        else
            if(k>=0 && arr3[k]==arr2[j]) j++; 
            else {arr3.push_back(arr2[j++]); k++;}
    }
 
    // Store remaining elements of first array
    while (i < n)
        if(k>=0 && arr3[k]==arr1[i]) i++;
        else {arr3.push_back(arr1[i++]); k++;}
 
    // Store remaining elements of second array
    while (j < m)
        if(k>=0 && arr3[k]==arr2[j]) j++; 
        else {arr3.push_back(arr2[j++]); k++;}
    
    return arr3;
}

// Construct a sorted array C for A ∩ B.
vector<int> disji_mergeArrays(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = -1;
    vector<int> arr3;
    while (i<n && j <m)
    {
        if(arr1[i]==arr2[j] && ( k<0 ||arr3[k]!=arr1[i] )){ arr3.push_back(arr1[i]); i++; j++; k++;}
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }

    return arr3;
}

int main()
{

    freopen("test_cases_Q1.txt","w",stdout);
    int n = 20,m=30 , a[n], b[m]; 

    rep(i,0,n){a[i] = rand()%50;} 
    sort(a,a+n);  // modifying  according to question
    rep(i,0,m){b[i] = rand()%50;} 
    sort(b,b+m);  // modifying  according to question

    cout<<n<<" "<<m<<"\n"; 
    rep(i,0,n){cout<<a[i]<<" ";} cout<<"\n"; 
    rep(i,0,m){cout<<b[i]<<" ";} cout<<"\n"; 
    fclose (stdout);

    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    
    vector<int> c = mergeArrays(a,b,n,m);
    vector<int> d = union_mergeArrays(a,b,n,m);
    vector<int> e = disji_mergeArrays(a,b,n,m);

    cout<<"a sorted array C by merging A and B \n";
    for(int x : c){ cout<<x<<" ";} cout<<"\n";
    cout<<"a sorted array C for A ∪ B\n";
    for(int x : d){ cout<<x<<" ";} cout<<"\n";
    cout<<"a sorted array C for A ∩ B\n";
    for(int x : e){ cout<<x<<" ";} cout<<"\n";
    
}