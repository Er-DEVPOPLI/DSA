#include <bits/stdc++.h> 

void topo(int i , stack<int>&s   ,  unordered_map<int,list<int>>&adj ,
int visited[] ){
    visited[i] = true ; 

    for(auto ad :adj[i] ){
             if(!visited[ad]){
                 visited[ad] = true ;
                 topo(ad , s, adj , visited) ;
                
             }
    }
     s.push(i) ; 
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
      

      unordered_map<int,list<int>>adj ; 

// adjacent 
      for(int i= 0 ; i<e ; i++){
               int a = edges[i][0] ; 
               int b = edges[i][1] ; 

               adj[a].push_back(b) ; 
      }

// unordered_map<int,bool>visited ;
int visited[v] = {0}  ; 
vector<int>ans ; 
stack<int>s ; 

for(int i =0 ; i< v ; i++){
    if(!visited[i]){
        topo(i ,s ,adj ,visited ) ; 
    }
}

while(!s.empty()){
    ans.push_back(s.top()) ; 
    s.pop() ; 
}

return  ans  ;
}