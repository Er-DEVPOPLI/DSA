#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
  unordered_map<int,list<int>>adj ; 
  
  for(int i = 0 ; i<edges.size() ;  i++){
      int u = edges[i][0] ; 
      int v = edges[i][1] ; 
      
      adj[u].push_back(v);
      
  }
  
  int indeg[v] = {0} ; 
  for(auto ap : adj){
      
      for(auto dp : ap.second){
          indeg[dp]++ ; 
      }
  }
  

  queue<int>q ; 
  for(int i = 0 ; i<v ; i++){
      if(indeg[i] == 0){
          q.push(i);
      }
  }
vector<int>ans ; 
 while(!q.empty()){
     int front = q.front() ; 
     q.pop() ; 
     ans.push_back(front) ; 
     
     for(auto it : adj[front] ){
         --indeg[it] ;
         if(indeg[it]== 0){
             q.push(it) ; 
         }
     }
     
 }
 return ans  ;
  
}