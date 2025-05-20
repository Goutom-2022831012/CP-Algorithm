#include<bits/stdc++.h>
using namespace std ;
void dfs(vector<vector<int>>&adj,vector<bool>&visited , stack<int> &s,int  node){
    if(visited[node]) return;
        visited[node]=true;
        for(int v : adj[node]){
            dfs(adj,visited,s,v);
        }
        s.push(node);
}
void revdfs(vector<vector<int>>&adj,vector<bool>&visited , stack<int> &s,int  node){
    if(visited[node]) return;
        visited[node]=true;
        for(int v : adj[node]){
            revdfs(adj,visited,s,v);
        }
}
void kosaraju(vector<vector<int>>&adj,vector<vector<int>>&rev,vector<bool>&visited , stack<int> &s,int  nodes){
    for(int i = 0 ; i < nodes; i++){
        dfs(adj,visited,s,i);
    }
    for(int i = 0 ; i < nodes ; i++ ){
        visited[i] = false ;
    }
    int ssc = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            revdfs(rev,visited,s,u);
            ssc++;
        }
    }
    cout<<ssc;
}
int main(){
    int n , m ;
    cin>>n>>m;
    vector<bool>visited(n,false);
    vector<vector<int>>adj(n);
    vector<vector<int>>rev(n);
    stack<int>s;
    int u , v;
    for(int i =  0 ; i < m ; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    kosaraju(adj,rev,visited,s,n);
    return 0;
}