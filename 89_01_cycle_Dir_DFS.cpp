

#include<unordered_map>
#include<list>

bool checkCycleDFS(int node ,unordered_map<int , bool>&visited ,unordered_map<int,bool>&dfsVisited ,unordered_map<int,list<int>>&adj){
     
     visited[node] = true ; 
     dfsVisited[node] = true ;  

     for(auto neg : adj[node]){
       if(!visited[neg]){
         bool cycleDetected = checkCycleDFS(neg ,visited , dfsVisited ,adj);

         if (cycleDetected) {
           return true;
         }
       }
        else if (dfsVisited[neg]) {
         return true;
       }
       
     }
     dfsVisited[node] = false ;
      return false ; 
 }
 

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
  unordered_map<int,list<int>>adj ; 

 for(int i = 0 ; i<edges.size() ; i++){
   int u = edges[i].first ; 
   int v = edges[i].second ; 

   adj[u].push_back(v) ; 
 }

 // call dfs for all componenets 
 unordered_map<int,bool >visited ; 
  unordered_map<int,bool >dfsvisited ; 

  for(int i =0 ; i<= n ; i++){
    if(!visited[i]){
      bool cyclefound = checkCycleDFS(i , visited , dfsvisited , adj) ; 
      if(cyclefound){
        return true ; 
      }

    }
    
  }
  return false ; 

}