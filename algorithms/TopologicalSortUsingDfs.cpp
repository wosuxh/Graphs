#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD
void dfs(int node , vector<vector<int>> &adj , vector<int> &vis , stack<int> &st){
    vis[node]=1 ;

    for(auto &val : adj[node]){
        if(!vis[val]){
            dfs(val,adj,vis,st);
        }
    }
    st.push(node) ;
}
int main(){
    int n,m ;
    cin >> n >> m ;
    vector<vector<int>> adj(n) ;

    for(int i=0 ;i<m ;i++){
        int a,b ;
        cin >> a >> b ;
        
        adj[a].push_back(b) ;
    }

    stack<int> st ;
    vector<int> vis(n) ;

    for(int i=0 ;i<n ;i++){
        if(!vis[i])
            dfs(i,adj,vis,st) ;
    }

    while(!st.empty()){
        int node=st.top();
        st.pop();
        cout << node << " " ;
    }
    cout << "\n" ;
    return 0 ;
}