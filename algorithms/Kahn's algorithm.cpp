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
    vector<int> indegree(n) ;

    for(int i=0 ;i<m ;i++){
        int a,b ;
        cin >> a >> b ;
        
        adj[a].push_back(b) ;
        indegree[b]++ ;
    }
    vector<int> vis(n) ;
    queue<int> q ;
    vector<int> topo ;

    for(int i=0 ;i<n ;i++){
        if(!indegree[i]){
            q.push(i) ;
            vis[i]=1 ;
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node) ;

        for(auto &val : adj[node]){
            indegree[val]--;
            if(indegree[val]==0){
                q.push(val) ;
            }
        }
    }
    if(topo.size()!=n){
        cout << "NOT a DAG\n" ;
        return 0 ;
    }
    for(auto &val : topo){
        cout << val << " " ;
    }
    cout << "\n" ;
    return 0 ;
}