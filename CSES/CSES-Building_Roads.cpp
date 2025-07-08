#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD

void dfs(int node , vector<vector<int>> &adj , vector<int> &vis){
	vis[node]=1 ;

	for(auto &val : adj[node]){
		if(!vis[val]){
			dfs(val,adj,vis);
		}
	}
}
int main(){
	int n , m ;
	cin >> n >> m ;

	vector<vector<int>> adj(n) ;

	for(int i=0 ;i<m ; i++){
		int a,b ;
		cin >> a >> b ;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> ans ; 

	vector<int> vis(n,0) ;
 	
	for(int i=0 ;i<n ;i++){
		if(!vis[i]){
			ans.push_back(i+1) ;
			dfs(i,adj,vis);
		}
	}


	int l=ans.size();
	cout << l-1 << "\n" ;
	for(int i=0 ;i<l-1 ; i++){
		cout << ans[i] << " " << ans[i+1] << "\n" ;
	}
	return 0 ;
}