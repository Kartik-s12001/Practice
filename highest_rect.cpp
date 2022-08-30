#include <bits/stdc++.h>
using namespace std;
int find_highest(vector<int> arr){
    stack<int> st;
    int ans=0,i=0,n=arr.size();
    arr.push_back(0);
    while(i<n){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int t = st.top();
            int h= arr[t];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }
            if(!st.empty()){
                int len= i-st.top()-1;
                ans=max(ans,h*len);
            }            

        }
        st.push(i);
        i++;
    }
    return ans;
}
int main()
{
    vector<int> vec = {2,1,5,9,3,2};
    cout<<find_highest(vec);
    

    return 0;
}