#include<iostream>
#include<list>
#include<unordered_map>

using namespace std  ;

class graph{
    public : 
    
 unordered_map<int,list<int>>adj ; 

 void addEdge(int u , int v , bool direction){ // here tewo 
    // dir ->0 = undirected 
    // dir ->1 = directed 

    adj[u].push_back(v); 

    if( direction == 0){
         adj[v].push_back(u); 

         
    }
 }

 void printAdjList(){

    for(auto i : adj ){
        cout<<i.first<< "->" ; 
        for(auto j : i.second){
            cout<<j<<"," ; 
        }
        
        cout<<endl ; 
    }
 }

} ; 

using namespace std;
int main(){

  int n ; 

  cout<<"Enter the no. of nodes"<<endl ; 
  cin>>n ; 

int m ; 
   cout<<"Enter the no. of edges "<<endl ; 
  cin>>m ; 


graph g ; 


for(int i = 0 ; i<m ; i++){
    int u , v ; 
    cin>>u>>v ; 

// creating an Undirected  graph 

    g.addEdge(u,v,0) ; 

}
 // print graph 

 g.printAdjList() ; 


return 0 ;
}
