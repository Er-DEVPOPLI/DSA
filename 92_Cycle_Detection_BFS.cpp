

// As kahns algo (91) valid for directed acyclic graph (DAG) so that if there is cycle or undirected graph it will fails
// in kahns algo cnt == no of vertices



#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
  // adjacent list
  
  unordered_map<int,list<int>>adj ; 
  for(int i= 0 ; i<edges.size() ; i++){
       int u = edges[i].first ; 
       int v = edges[i].second ; 

       adj[u].push_back(v) ; 
       
  }
  
// indeg creation 
  int indeg[n]= {0} ; 
  
  for(auto it : adj){
    
    for(auto pt : it.second){
      indeg[pt]++ ; 
    }
  }
  
  queue<int>q ;
  for(int i =0 ; i<n  ; i++){
    if(indeg[i] == 0){
      q.push(i) ;
    }
  }
  
  int cnt = 0 ; 
  
  while(!q.empty()){
    int front = q.front() ; 
    q.pop() ; 
     cnt++ ; 
     
     for(auto it : adj[front]){
          --indeg[it] ; 
          if(indeg[it]== 0 ){
            q.push(it) ; 
          }
     }
  }


   if(cnt == n){
     return false ; 
     
   }
   else{
     return true ; 
   }











  
}