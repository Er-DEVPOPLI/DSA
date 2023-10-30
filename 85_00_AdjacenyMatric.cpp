#include<iostream>
using namespace std;

class graph {
    unordered_map<int,list<int>>adj ; 

    void add(int n1 , int n2 , bool dirn){

        adj[n1].push_back(n2) ; 

        if(dirn == 0){
            adj[2].push_back(n1) ; 
        }
    }

    void print(){
        for(auto i : adj){
cout<<"i.first -> "<<i.first ;
            for(auto j : i.second){
               cout<<j
            }
            cout<<endl ;
        }
    }
}

int main(){
         
         int n , m ; 
          
          cin>>n>>m ; 

          // graph here 
          int adj[n+1][n+1] ; 
          for(int i=0 ; i<m ; i++){
            int u ,v; 

            cin>>u>>v ; 
            adj[u][v] = 1 ; 
            adj[v][u] = 1 ; 

          }





return 0 ;
}