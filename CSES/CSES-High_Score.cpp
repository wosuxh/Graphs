/*
ॐ        ॐ
  ओम नमः शिवाय
ॐ        ॐ
*/
 
#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
typedef long long ll;
 
const ll Inf = 1E18;
 
void solve() {
  int n,m ;
  cin >> n >> m ;
  long long inf=1e14;
  vector<vector<long long>> edges(m,vector<long long>(3));
 
  for(int i=0 ;i<m ;i++){
    int x,y,z ;
    cin >> x >> y >> z; 
    edges[i][0]=x ;
    edges[i][1]=y;
    edges[i][2]=z ;
  }
  vector<long long> dis(n+1,-inf) ;
  dis[1]=0 ;
  for(int i=1 ; i<n ;i++){
    for(int j=0 ;j<m ;j++){
      int a=edges[j][0] ;
      int b=edges[j][1] ;
      long long x=edges[j][2];
      if(dis[a]==-inf) continue ;
 
      if(dis[a]+x>dis[b]){
        dis[b]=dis[a]+x ;
      }
    }
  }
  long long ans=dis[n] ;
  for(int i=1 ; i<=n ;i++){
    for(int j=0 ;j<m ;j++){
      int a=edges[j][0] ; 
      int b=edges[j][1] ;
      long long x=edges[j][2];
      if(dis[a]==-inf) continue ;
 
      if(dis[a]+x>dis[b]){
        dis[b]=inf;        
      }
    }
  }
  if(dis[n]==inf) cout << "-1\n" ;
  else
  cout << ans << "\n" ;
 
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t;
  t=1;
  // cin >> t;
  while(t--)solve();
 
  return 0;
}
