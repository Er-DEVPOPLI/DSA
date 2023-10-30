
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	
	int ct = n/2 ;  int ans = -1 ;
	map<int,int>mp ; 

	for(int i =0 ; i<n ; i++){
		mp[arr[i]]++ ; 
	}
	for(auto i: mp){
		if(i.second > n/2){
			ans = i.first ;
		}
	}

	return ans  ;
}