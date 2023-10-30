//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
       vector<int >ans; 
       
       priority_queue<int, vector<int>,greater<int>> heap ; 
       
       for(int i = 0 ; i<num ; i++){
           heap.push(arr[i]) ;
           if(heap.size() >K){
               ans.push_back(heap.top());
               heap.pop() ; 
           }
       }
       
       while(heap.size()){
           ans.push_back(heap.top()); 
           heap.pop() ; 
       }
       
       return ans ;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends