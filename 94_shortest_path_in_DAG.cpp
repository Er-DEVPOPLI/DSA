// DAG - > directed acyclic graph  

#include<iostream>
#include<unordered_map>
#include<stack>

#include<map>
#include<bits/stdc++.h>
#include<list>


using namespace std;

class graph{
    public: 
    map<int,list<pair<int,int>>>adj ; 


void addEdge(int u , int v , int weight){
    pair<int,int>p = {v , weight} ; 
    adj[u].push_back(p) ; 
}

void printAdj(){
    for(auto i : adj){
        cout<<i.first<<"-> " ;

        for(auto j : i.second){
            cout<<"("<<j.first<<","<<j.second<<") , " ;
        }cout<<endl ;
    }
}

void DFS(int node ,unordered_map<int,bool>&visited ,stack<int>&topo ){
    visited[node] = true ; 

    for(auto neg : adj[node]){
        if(!visited[neg.first]){
            DFS(neg.first , visited,topo) ; 
        }
    }

   topo.push(node) ; 
}

void getShortestPath(int src, vector<int>&dist , stack<int>&s){
  
    dist[src] = 0 ; 

    while(!s.empty()){
        int top = s.top() ; 
        s.pop() ;

        if(dist[top] != INT_MAX){
            for(auto i : adj[top]){
                if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] + i.second ;
                }
            }
        }
    }
}

} ;
int main(){


    graph g  ; 
    g.addEdge(0 ,1,5) ; 
       g.addEdge(0 ,2,3) ; 
       g.addEdge(1 ,2,2) ; 
       g.addEdge(1 ,3,6) ; 
       g.addEdge(2 ,3,7) ; 
       g.addEdge(2,4,4) ;
          g.addEdge(2,5,2) ; 
        g.addEdge(3,4,-1) ; 
       g.addEdge(4,5,-2) ; 
    
    g.printAdj() ; 
 


  // topologcal Sort 

  // here n represent no of node 
unordered_map<int,bool>visited ; 
stack<int>s ; 

  int n = 6 ; 
  for(int i= 0 ; i<n ; i++){
    if(!visited[i]){
        g.DFS(i , visited,s) ;
    }
  }

   int src = 1; 
   vector<int>dist(n) ; 
for(int i =0 ; i<n ; i++){
    dist[i] = INT_MAX;
 
}

 g.getShortestPath(src,dist,s) ;

 cout<<"answer is : "<<endl ; 
 for(int i = 0 ; i<dist.size() ; i++){
   cout<<dist[i]<<" ";

 }cout<<endl ;

   
return 0 ;
}