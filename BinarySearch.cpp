#include<bits/stdc++.h>
using namespace std;

int binarySreach(vector<int>&arr, int coin){
    sort(arr.begin(),arr.end());
    int low = 0;
    int high = arr.size() -1 ;
    int ans;
    while(low<=high){
        int mid = (low+(high-low))/2;
        if(arr[mid]>=coin){
            ans = mid+1;
            low = mid+1;
        }
        else high = mid -1 ; 
    }
    return ans;
}
int main(){
    vector<int>arr = {1,4,5,3,5,6,12,10,8,9,3};
    cout<<binarySreach(arr,9);
    return 0;
}