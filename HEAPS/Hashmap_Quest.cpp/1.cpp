#include <bits/stdc++.h> 
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	pair<int,int>ans ; 
    unordered_map<int,int>mp; 

	int count = 0 ; 
	int unio = 0 ; 

	for(int i =0 ; i< n ; i++){
		if(mp[arr1[i]]!= 1 ){
               mp[arr1[i]] = 1 ;
		}
		
	} 

	for(int i =0 ; i< m ; i++){
		if(mp[arr2[i]] == 1 ){
                 count ++ ;
		} 
	} 

	unio = (m-count) +n  ; 

	ans.first = count; 
	ans.second = unio ;


	return ans ;



}