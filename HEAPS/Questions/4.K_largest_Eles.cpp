//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    
	     // ************ approach 1 :-> min heap 
// 	   vector<int>ans ; 
	   
// 	   priority_queue<int, vector<int> ,greater<int>>heap ; 
// 	   //priority_queue<int>heap ; 
	   
// 	   for(int i = 0 ; i< n; i++){
// 	       heap.push(arr[i]) ; 
	       
// 	       if(heap.size() > k){
// 	           heap.pop() ; 
// 	       }
// 	   }
	   
// 	   while(heap.size() > 0){
// 	       ans.push_back(heap.top()) ; 
// 	       heap.pop() ;
// 	   }
// 	  reverse(ans.begin() , ans.end()) ;
// 	   return ans ;
// 	}
	
	//************  approach 2  : -> MAX heap
	priority_queue<int>heap ; 
	vector<int>ans  ;
	for(int i  =0; i<n ; i++){
	   heap.push(arr[i]);
	}
	
	while(k--){
	    ans.push_back(heap.top()); 
	    heap.pop() ; 
	}
 return ans ;
 
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends