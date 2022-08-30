#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int temp[], int l, int r, int mid){
    int n1= mid-l+1;
    int n2 = r-mid;

    int a[n1]={0};
    int b[n2]={0};

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }

    for(int j=0;j<n2;j++){
        b[j]=arr[mid+1+j];
    }

    int i=0 ;
    int j=0 ;
    int k=l ;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            temp[k]=a[i];
            i++;
            k++;
        }
        else{
            temp[k]=b[j];
            j++;
            k++;    
        }
    }
    while(j<n2){
            temp[k]=b[j];
            j++;
            k++;
        }
    while(i<n1){
            temp[k]=a[i];
            i++;
            k++;
        }

    for(int i=l;i<r+1;i++){
        arr[i]=temp[i];
    }

}

void mergeSort(int arr[],int temp[],int l,int r){
    if(l<r){
        int mid= (l+r)/2;
        mergeSort(arr, temp, l, mid );
        mergeSort(arr, temp, mid+1, r);

        merge(arr,temp,l,r,mid);

    }


}

int main()
{
    int arr[5]={5,4,3,2,1};
    int temp[5];
    mergeSort(arr,temp,0,4);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}