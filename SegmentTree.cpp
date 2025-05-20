#include <bits/stdc++.h>
using namespace std;

vector<int>arr(10);
vector<int>tree(10*3);
void init(int root , int left , int right ){
    if(left==right){
            tree[root] = arr[left];
         return;
    }
    int leftIndex = root*2+1;
    int rightIndex = root*2+2;
    int mid = (left+right)/2;
    init(leftIndex,left,mid);
    init(rightIndex,mid+1,right);
    tree[root]=tree[leftIndex]+tree[rightIndex];
}
void minimum(int root,int left,int right){
    if(left==right){
        tree[root]=arr[left];
        return;
    }
    int leftIndex = root*2+1;
    int rightIndex = root*2+2;
    int mid = (left+right)/2;
    minimum(leftIndex,left,mid);
    minimum(rightIndex,mid+1,right);
    tree[root]=min(tree[leftIndex],tree[rightIndex]);

}
int range(int root , int left , int right,int i, int j){
    if(right<i || left>j){
        return 0;
    }
    if(left>=i && right<=j){
        return tree[root];
    }
        int leftIndex = 2*root +1;
        int rightIndex = 2*root +2;
        int mid = (left+right)/2;
        return (range(leftIndex,left,mid,i,j)+range(rightIndex,mid+1,right,i,j));
}
void update(int root ,int left,int right,int i,int j, int value){
    if(right<i || left>j){
        return;
    }
    if(left>=i && right<=j){
        tree[root] = value;
        return;
    }
        int leftIndex = 2*root +1;
        int rightIndex = 2*root +2;
        int mid = (left+right)/2;
        update(leftIndex,left,mid,i,j,value);
        update(rightIndex,mid+1,right,i,j,value);
        tree[root]= tree[leftIndex]+tree[rightIndex];
}

int main() { 

    for(int i = 0 ; i< 10;i++){
        arr[i]=i*2;
    }
   minimum(0,0,9);
   for(int i = 0 ; i< 25;i++){
    cout<<tree[i]<<endl;
}
    return 0;
}
