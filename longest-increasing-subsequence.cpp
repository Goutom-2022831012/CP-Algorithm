#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> & numbers){
    vector<int> dp(numbers.size(),1);
    for(int i = 0 ; i < numbers.size() ; i++){
        for(int j = 0 ; j < i; j++){
            if(numbers[j]<numbers[i]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}

int main(){
    vector<int> numbers = {0,1,0,3,2,3};
    cout<<lis(numbers);
}