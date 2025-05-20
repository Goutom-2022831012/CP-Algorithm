#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& Btree, int index , int value, int size){
    index++;
    while(index<=size){
    Btree[index]+=value;
            index += (index &(-index));
    
    }
}

void construct(vector<int>& Btree , vector<int> &arr){
    int l = Btree.size();
    for(int i = 0 ; i< l ; i++){
        Btree[i] = 0 ;
    }
    int size = arr.size();
    for(int i = 0 ; i< size ; i++){
        update(Btree , i , arr[i], size);
        
    }

} 
int getSums(vector<int>& Btree , int index){
    index++;
    int sum = 0;
    while(index>0){
        sum+=Btree[index];
        index-=(index & (-index));
    }
    return sum;
}
int main(){
    vector<int> arr = {1,2,34,32,45,6,5,32,45,6,7};
    int l = arr.size();
    vector<int> Btree(l+1);
    construct(Btree , arr);
    cout<<getSums(Btree , 3)-getSums(Btree ,1);
    return 0 ;
}