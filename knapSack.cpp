#include<bits/stdc++.h>
using namespace std;

int knapSack( int w , vector<int> & weight , vector<int> &profit ,int  index, vector<vector<int>> & memo ){
if (index <0) return 0;
if(memo[index][w] != -1) return memo[index][w];
if(weight[index]>w) memo[index][w] = knapSack(w, weight, profit, index - 1, memo);
else {
    memo[index][w] = max(profit[index]+knapSack(w-weight[index], weight, profit, index - 1, memo),
                          knapSack(w, weight, profit, index - 1, memo  ));
                          }
                          return memo[index][w] ;
}
int main(){
    vector<int> weight = {3,2,4};
    vector<int> profit = {30,40,50};
    int w = 8 ;
    int n  =  weight.size();
    vector<vector<int>> memo (n, vector<int>(w+1 , -1));
    cout<<knapSack(w,weight,profit,n-1,memo);
    return 0 ;
}