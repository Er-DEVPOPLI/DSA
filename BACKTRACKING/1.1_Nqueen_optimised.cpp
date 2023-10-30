

 // coding Ninjas correct ans by me 


#include <bits/stdc++.h> 

unordered_map<int, bool >rowCheck ; 
unordered_map<int, bool >upperdiagonal ; 
unordered_map<int, bool >lowerdiagonal

 ; 
// void addSolution(vector<vector<int>>&ans  , vector<vector<int>>& board  , int n){
// 	vector<int>temp ; 

// 	for(int i=0 ; i<n ; i++){
// 		for(int j=0 ; j<n ; j++ ){
// 			temp.push_back(board[i][j]) ; 

// 		}
// 	}

// 	ans.push_back(temp) ; 
// }

// bool isSafe(int row , int col , vector<vector<int>>& board  , int n ){
// 	int x = row  ; 
// 	int  y = col ; 

// 	// check for same row  

// 	while(y>=0 ){
// 		if(board[x][y] == 1){
// 			return false ; 
// 		}
// 		y-- ; 
// 	}

// 	x = row  ; 
// 	y =col ; 

// 	while(x>= 0 && y>=0 ){
// 		if(board[x][y] == 1){
// 			return false ; 
// 		}
// 		y-- ; x-- ; 
// 	}

// 	x = row  ; 
// 	y =col ; 

// 	while(x<n  && y>=0 ){
// 		if(board[x][y] == 1){
// 			return false ; 
// 		}
// 		y-- ; x++ ; 
// 	}

// return true ;

// }
// void solve(int col , vector<vector<int>>&ans , vector<vector<int>>&board , int n ){
// 	if(col == n){
// 		addSolution(board , ans ,n ) ; 
// 		return ;
// 	}
	 
// 	 // 
// 	 for(int row = 0 ; row <n ; row++){
// 		 if(isSafe(row,col ,board , n){
// 			 // if placing quee is safe 

// 			 board[row][col] = 1 ; 
// 			 solve(col+1 , ans , board ,n) ; 
// // backtracking 
// 			 board[row][col] = 0 ; 

// 		 }
// 	 }
// }
// vector<vector<int>> nQueens(int n)
// {
// 	vector<vector<int>>ans  ; 
// 	vector<vector<int>> board( n , vector<int>(n,0)) ; 


	
// }

void addSolution ( vector<vector<int> > &ans, vector < vector < int> > &board, int n ){

	vector<int> temp;

	for ( int i = 0; i<n ; i++){
		for ( int j = 0; j<n ; j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
} 
bool isSafe2(int row , int col , vector<vector<int> > &board , int n){
	if(rowCheck[row] == true){
		return false ;
	}
	if(upperdiagonal[n-1+col-row] == true){
		return false ; 
	}
	if(lowerdiagonal[row+col] == true ){
		return false ;
	}
	return true ;

}
bool isSafe ( int row , int col , vector<vector<int> > &board , int n){

	int x = row ;
	int y = col ;




	while ( y>=0){
		if( board [x][y] == 1)
			return false;
		y--;
	}

	x = row ;
	y = col ;
	
	while ( x>= 0 && y>=0){
		if( board [x][y] == 1)
			return false;
	
		y--;
		x--;
	}

	x = row ;
	y = col ;

	while ( x<n && y>=0 ){
		if( board [x][y] == 1)
			return false;
	
		y--;
		x++;
	}

	return true;
}

void solve(int col,vector<vector<int> > &ans,vector<vector<int> > &board , int n){


	if( col == n ){
		addSolution (  ans , board, n);
		return ;
	}

	

	for ( int row = 0 ; row < n ; row++){
		// if( isSafe (row , col ,board , n)){
		// 	// place queen if safe
		// 	board[row][col] = 1;
		// 	solve(col+1 , ans , board , n);
		// 	board[row][col] = 0;
		// }
if( isSafe2 (row , col ,board , n)){
			// place queen if safe
			board[row][col] = 1;
			rowCheck[row] = true ; 

			upperdiagonal[n-1+col-row] = true ; 
			lowerdiagonal[row+col] = true ;

			solve(col+1 , ans , board , n);
    
			// backtrack ..... 
			board[row][col] = 0;
			rowCheck[row] = false ; 
			
			upperdiagonal[n-1+col-row] = false ; 
			lowerdiagonal[row+col] = false ;
		}
		
	}
}

vector<vector<int>> nQueens(int n)
{

	int col = 0 ; 
	vector < vector < int> > board (n , vector <int> ( n , 0));
	vector < vector < int> > ans;

	solve( col , ans , board , n);
	return ans;
}