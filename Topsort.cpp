#include<bits/stdc++.h>
using namespace std ;
void Dfs(vector<vector<int>>&adj,vector<bool>&visited , stack<int> &s,int  node){
    if(visited[node]) return;
        visited[node]=true;
        for(int v : adj[node]){
            Dfs(adj,visited,s,v);
        }
        s.push(node);
}
void topSort(stack<int>&s){
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    int u,v;
    vector<vector<int>>adj(n);
    stack<int>s;
    vector<bool>visited(n,false);
    for( int i = 0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i = 0 ; i < n ; i++){
    Dfs(adj,visited,s,i);
    }
    topSort(s);
    return 0;
}