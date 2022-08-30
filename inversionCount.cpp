#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int l, int mid, int r,long long int& count){
    int n1= mid-l+1;
    int n2 = r-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else if(a[i]<b[j]){
            arr[k]=a[i];
            // count += (n1-i);
            i++;
            k++;
        }
        else if(a[i]>b[j]){
            arr[k]=b[j];
            count+=n1-i;
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[],int l,int r, long long int& count){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid,count);
        mergeSort(arr,mid+1,r,count);

        merge(arr,l,mid,r,count);
    }

}


int main()
{
    int n=11;
    long long int count=0;
    int arr[n]={2,3,4,5,6,7,8,9,10,11,1};
    mergeSort(arr,0,n-1,count);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<count<<endl;

    return 0;
}

// #include "bits/stdc++.h"
// using namespace std;
// long long merge(int arr[], int l, int mid, int r)
// {
//     long long inv = 0;
//     int n1 = mid - l + 1;
//     int n2 = r - mid;
//     int a[n1];
//     int b[n2];
//     for (int i = 0; i < n1; i++)
//     {
//         a[i] = arr[l + i];
//     }

//     for (int i = 0; i < n2; i++)
//     {
//         b[i] = arr[mid + i + 1];
//     }
//     int i = 0, j = 0, k = l;
//     while (i < n1 and j < n2)
//     {
//         if (a[i] <= b[j])
//         {
//             arr[k] = a[i];
//             k++;
//             i++;
//         }
//         else
//         {
//             arr[k] = b[j];
//             inv += n1 - i;
//             k++;
//             j++;
//         }
//     }
//     while (i < n1)
//     {
//         arr[k] = a[i];
//         k++;
//         i++;
//     }
//     while (j < n2)
//     {
//         arr[k] = b[j];
//         k++;
//         j++;
//     }
//     return inv;
// }
// long long mergeSort(int arr[], int l, int r)
// {
//     long long inv = 0;
//     if (l < r)
//     {
//         int mid = (l + r) / 2;
//         inv += mergeSort(arr, l, mid);
//         inv += mergeSort(arr, mid + 1, r);
//         inv += merge(arr, l, mid, r);
//     }
//     return inv;
// }
// int main()
// {
//     int n=11;
//     long long int count=0;
//     int arr[n]={2,3,4,5,6,7,8,9,10,11,1};
//     count = mergeSort(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     cout<<count<<endl;

//     return 0;
// }
