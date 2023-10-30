 
 // doubt 

#include <bits/stdc++.h> 
#include<vector>
bool isSafe(int nrow , int ncol , vector < vector < int >> & arr ,vector < vector < int >> & vis , int n   ){
     if((nrow >=0 && nrow < n )&&(ncol >=0 && ncol < n ) && vis[nrow][ncol] != 1 && arr[nrow][ncol] ==1){
         return true ; 
}
    return false ; 
}
void solve(int row , int col ,vector<vector<int>>&arr 
, vector < vector < int >> &vis , string path ,
                      vector<string>&ans ,int n  ){
    if(row == n-1 && col == n-1){
        ans.push_back(path) ; 
          return  ;
    }

    // DLRU 

 // DOWN
    if(isSafe(row+1 ,col , arr , vis  ,n )){
        vis[row][col] = 1 ; 
        
        solve( row+1 , col ,arr ,vis , path+'D',ans , n  ) ; 

        vis[row][col] =0   ; 

         
    }

    // LEFT 
     if(isSafe(row ,col-1, arr , vis  ,n )){
        vis[row][col] = 1 ; 

        solve( row , col-1 ,arr ,vis , path+'L',ans, n  ) ; 
        
          vis[row][col] =0   ; 
    }

    // RIGHT
     if(isSafe(row ,col+1 , arr , vis  ,n )){
        vis[row][col] = 1 ; 
        
        solve( row , col+1 ,arr ,vis , path+'R', ans , n ) ; 
  vis[row][col] =0   ; 
    }

    // UP
     if(isSafe(row-1 ,col , arr , vis  ,n )){
            vis[row][col] = 1 ; 
        
        solve( row-1 , col ,arr ,vis , path+'U', ans , n ); 
            vis[row][col] =0   ; 
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    
  int row = 0 ; 
  int col =0 ; 

    vector<string>ans ;


    vector<vector<int>>vis(n , vector<int>(n,0)) ; 

    string path = "" ; 
  

  if(arr[0][0]  == 0){
    return ans  ;
  }
 
    solve(0, 0  , arr , vis , path ,ans , n) ; 

    return ans ;
}