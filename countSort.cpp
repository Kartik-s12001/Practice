#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }
    int count[20]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for (int i = 1; i < k+1 ; i++)
    {
        count[i]+=count[i-1];
    }
    int res[n];
    for(int i=n-1;i>=0;i--){
        res[--count[arr[i]]]=arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=res[i];
    }
    
    
    
}

int main()
{
    int n=12;
    int arr[n]={1,4,2,4,5,5,4,3,0,0,4,6};
    countSort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl;

    return 0;
}