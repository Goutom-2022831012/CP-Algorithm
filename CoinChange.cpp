#include<bits/stdc++.h>
using namespace std ; 
int count(vector<int>& coin, int n, int sum, vector<vector<int>> &memo ){
    if (sum == 0 ) return 1;
    if(sum <0 || n == 0 ) return 0 ;
    if(memo[n-1][sum] != -1) return memo[n-1][sum];
     return memo[n-1][sum] = 
        count(coin, n, sum - coin[n-1], memo) + 
        count(coin, n - 1, sum, memo);
}


int  coinNum(int sum , vector<int> &coin){
vector<vector<int>> memo (coin.size() + 1 , vector<int>(sum+1, -1));
return count(coin , coin.size() , sum , memo );
} 

int main(){
    vector<int>coin = {1,2,3};
    int sum = 5 ; 
    cout << coinNum(sum, coin );
    return 0;
}