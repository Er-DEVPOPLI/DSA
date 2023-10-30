#include <bits/stdc++.h> 
vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	
	map<int,int>mp ; 
    vector<int>ans ; 

	int ct = n/k ; 

for(int i = 0 ; i< n ; i++){
	mp[arr[i]]++ ; 
}
   for(auto i : mp){
	   if(i.second >= ct){
		   ans.push_back(i.first) ;
	   }
   }

   return ans ;
}