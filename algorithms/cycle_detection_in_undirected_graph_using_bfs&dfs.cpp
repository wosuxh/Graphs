#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD
bool usingdfs(int node, int prev , vector<vector<int>> &adj , vector<int> &vis){
    vis[node]=1 ;

    for(auto &val : adj[node]){
        if(!vis[val]){
            if(usingdfs(val,node,adj,vis)) return true ;
        }
        else if(val!=prev){
            return true ;
        }
    }
    return false ;
}

bool usingbfs(int node, vector<vector<int>> &adj , vector<int> &vis){
    vis[node]=1 ;

    queue<pair<int,int>> q ;
    q.emplace(node,-1) ;

    while(!q.empty()){
        auto [node,parent]=q.front();
        q.pop();

        for(auto &val : adj[node]){
            if(!vis[val]){
                vis[val]=1 ;
                q.emplace(val,node) ;
            }
            else if(val!=parent){
                return true ;
            }
        }
    }
    return false ;
}
int main(){
    int n,m;
    cin >> n >> m ;

    vector<vector<int>> adj(n) ;

    for(int i=0 ;i<m ;i++){
        int a,b ;
        cin >> a >> b; 
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n) ;
    for(int i=0 ; i<n ;i++){
        if(!vis[i]){
            if(usingbfs(i,adj,vis)){
                cout << "Cycle is present\n" ;
                return 0 ; 
            }

        }
    }
    cout << "Cycle is not present\n" ;

    return 0 ;
}