#include<bits/stdc++.h>

void BFS(int i , int visited[] 
 , unordered_map<int,int>&parent ,
 unordered_map<int,list<int>>&adj){


	queue<int>q ; 
	parent[i] = -1 ; 
	visited[i] =true ; 
	q.push(i) ; 

	while(!q.empty()){
		int front = q.front() ; 
		q.pop() ; 
		 
		 for(auto  ad : adj[front]){
           if(!visited[ad]){
			   visited[ad] = true ; 
			   parent[ad] = i ; 
			   q.push(ad) ; 
		   }
		 }

	}

}

vector<int> shortestPath( vector<pair<int,int>> edges , 
int n , int m, int s , int t){
	
	unordered_map<int,list<int>>adj ; 

	for(int i = 0 ; i<edges.size() ; i++ ){
		int a = edges[i].first ; 
		int b = edges[i].second ; 

    adj[a].push_back(b) ; 
	adj[b].push_back(a) ; 
	}
	
	 int visited[n+4] = {0} ;  // this is also correct 
     // unordered_map<int,bool>visited ; // this is also correct 
    unordered_map<int,int>parent ; 
	vector<int>ans ; 

	// for(int i = 1 ; i<= n ; i++){
	// 	if(!visited[i]){
	// 		BFS(i , visited , parent , adj) ;
	// 	}
	// }

	queue<int>q ; 
	parent[s] = -1 ; 
	visited[s] =true ; 
	q.push(s) ; 

	while(!q.empty()){
		int front = q.front() ; 
		q.pop() ; 
		 
		 for(auto  ad : adj[front]){
           if(!visited[ad]){
			   visited[ad] = true ; 
			   parent[ad] = front ; 
			   q.push(ad) ; 
		   }
		 }

	}
	int cur  = t ; 
	ans.push_back(cur) ; 

	while(cur != s){
		
		cur = parent[cur] ;
        ans.push_back(cur) ; 
	}
//    ans.push_back(s) ;
reverse(ans.begin() ,ans.end()) ;
	return ans ;
	
}
