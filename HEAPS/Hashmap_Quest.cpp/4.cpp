#include <bits/stdc++.h> 
int countSubarrays(int n, vector<int> &arr){
 
// vector<int>ans ;
int count = 0 ;
  
    for(int i = 0 ; i<n ; i++){
 int sum = 0 ; 
 
        for(int j=i ; j<n ; j++){
             sum = sum + arr[j] ; 
      if(sum == 0){
          count++ ;
      }
        //  ans.push_back(sum) ;
        }


    }

    return count++ ;
}