#include <bits/stdc++.h>
using namespace std;
vector<int> days(vector<int> arr){
    int n=arr.size();
    vector<int> day;
    stack<pair<int,int>> st;
    for(auto& price : arr){
        int d=1;
        while(!st.empty() && st.top().first <= price){
            d+= st.top().second;
            st.pop();
        }
        st.push({price,d});
        day.push_back(d);

    }
    return day;
}
int main()
{
    vector<int> vec = {100,80,60,70,60,75,85},ans;
    
    ans=days(vec);
    for(auto& i : ans){
        cout<<i<< " ";
    }

    return 0;
}