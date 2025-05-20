#include<bits/stdc++.h>
using namespace std;

void Dfs(vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s){
    if(!visited[0]) visited[0] = true ; 
    s.push(0);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        cout<<u<<endl;
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    s.push(v);
                }
            }
        
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<bool> visited(n,false);
    stack<int>s;
    int u , v ; 
    for(int i = 0 ; i < m ; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Dfs(adj,visited,s);
    return 0 ;
}