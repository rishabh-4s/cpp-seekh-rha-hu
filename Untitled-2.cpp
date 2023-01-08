#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;
void print(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
vector<int> factorial(int N){
    vector<int> ans;
    ans.push_back(1);
    for(int i=1;i<N+1;i++){
        int carry=0;
        for(int j=0;j<ans.size();j++){
            int value=ans[j]*i+carry;
            ans[j]=(value)%10;
            carry=(value)/10;
        }
        if(carry){
            ans.push_back(carry);
            carry=0;
        }
    }
    reverse(ans.begin(),ans.end());
    print(ans);
}

int main(){
    int n;cin>>n;
    factorial(n);
}