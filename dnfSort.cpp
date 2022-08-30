#include <bits/stdc++.h>
using namespace std;
void swap(int arr[],int x,int y){
    int temp= arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
    
}
void dnfSort(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==0){
            swap(arr,mid,low);
            mid++;
            low++;

        }
        else if(arr[mid]==2){
            swap(arr,mid,high);
            high--;
        }
    }
}

int main()
{
    int n=10;
    int arr[n]={1,2,0,2,1,0,0,2,2,2};
    dnfSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

    return 0;
}