#include <bits/stdc++.h>
using namespace std;

void swap(int arr[],int x, int y){
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}

void waveSort(int arr[],int n){
    int i=1;
    while(i<=n-2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1]){
            swap(arr,i,i+1);
        }
        i+=2;
    }
}
int main()
{
    int n=11;
    int arr[n]={1,2,3,4,5,6,7,8,9,10,11};
    waveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}