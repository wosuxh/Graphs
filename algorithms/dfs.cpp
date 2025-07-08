void dfs(int node , vector<vector<int>> &adj , vector<int> &vis){
	vis[node]=1 ;

	for(auto &val : adj[node]){
		if(!vis[val]){
			dfs(val,adj,vis);
		}
	}
}