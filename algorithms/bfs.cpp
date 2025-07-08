void bfs(int row,int col,vector<vector<char>> &graph, vector<vector<int>> &vis){
	int n=graph.size();
	int m=graph[0].size();
	vis[row][col]=1 ;

	queue<pair<int,int>> q ;
	q.push({row,col});

	while(!q.empty()){
		int r=q.front().first ;
		int c=q.front().second ;
		q.pop();

		for(int i=0 ;i<4 ;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			if(nr>=0 && nc>=0 && nr<n && nc<m && graph[nr][nc]=='.' && !vis[nr][nc]){
				q.push({nr,nc});
				vis[nr][nc]=1 ;
			}
		}
	}
}