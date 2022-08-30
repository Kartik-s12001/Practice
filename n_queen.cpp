#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isSafe(int **arr ,int x, int y,int n){
    for(int i = 0; i<x;i++){
        if(arr[i][y]==1)
            return false;
    }
    int row = x, col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1)
            return false;
        row--;
        col--;
    }
    row =x, col =y;
    while(row>=0 && col<n){
        if(arr[row][col]==1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool placeQueens(int **arr,int n, int x){
        if(x==n){
            return true;
        }
        for(int y=0;y<n;y++){
            if(isSafe(arr,x,y,n)){
                arr[x][y]=1;
                if(placeQueens(arr,n,x+1))
                   return true;
                arr[x][y]=0;
            }
        }
        return false;
    
}

int main()
{   
    int n=8;
    int **arr= new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    } 

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    // arr[n][n]=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    placeQueens(arr,n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"executed"<<endl;

    return 0;
}