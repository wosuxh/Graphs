#include<bits/stdc++.h> 
using namespace std ;
 
int main(){
  int n,m ;
  cin >> n >> m ;
 
  vector<vector<pair<int,int>>> adj(n) ;
  for(int i=0 ;i<m ;i++){
    int x,y,z;
    cin >> x >> y >> z ;
    x-- ;
    y--;
    adj[x].push_back({y,z});
  }
  long long inf=1e15 ;
  vector<long long> disWithCoupon(n,inf);
  vector<long long> disWithoutCoupon(n,inf);
  disWithCoupon[0]=0 ;
  disWithoutCoupon[0]=0 ;
  priority_queue<pair<pair<long long,int>,int>,vector<pair<pair<long long,int>,int>>,greater<pair<pair<long long,int>,int>>> pq ;   
 
  pq.push({{0,0},0});
  pq.push({{0,0},1});
 
  while(!pq.empty()){
    long long dis=pq.top().first.first;
    int node=pq.top().first.second;
    int chk=pq.top().second ;
 
    pq.pop();
 
    if(((dis>disWithCoupon[node]) && chk) || ((dis>disWithoutCoupon[node]) && !chk)) continue;
 
    for(auto &val:adj[node]){
      int edge=val.first;
      int edgeWt=val.second;
 
      if(chk){
        if(dis+edgeWt<disWithCoupon[edge]){
          disWithCoupon[edge]=dis+edgeWt;
          pq.push({{disWithCoupon[edge],edge},1});
        }
      }
      else{
        if(dis+edgeWt<disWithoutCoupon[edge]){
          disWithoutCoupon[edge]=dis+edgeWt;
          pq.push({{disWithoutCoupon[edge],edge},0});
        }
        if(dis+edgeWt/2<disWithCoupon[edge]){
          disWithCoupon[edge]=dis+edgeWt/2 ;
          pq.push({{disWithCoupon[edge],edge},1});
        }
      }
    }
 
  }
  cout << disWithCoupon[n-1] << "\n" ;
      
  return 0 ;
}