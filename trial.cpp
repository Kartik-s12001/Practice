#include <bits/stdc++.h>
using namespace std;
void deleteNonRepeat(int size, int *inputList)
{  
    int count = 0, i, j;
    int counter[size]; 
    for(i=0;i<size;i++)
    {
        counter[i]=1;
    }
    for(i=0;i<size;i++)
    {
        for(j = i+1; j<size; j++)
        {
            if(inputList[i]== inputList[j])
            {
                counter[i]++;
                counter[j]++;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        if(counter[i]>1)
        {
            count++;
        }
    }    
    j=0;
    for(i=0;i<size;i++)
    {
        if(counter[i]>1)
        {
            cout<<inputList[i++]<<" ";
        }
    }    
}
int main()
{
    

    return 0;
}