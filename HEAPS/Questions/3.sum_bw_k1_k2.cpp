//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        long long sum = 0 ; 
        
        priority_queue<int>heap ; 
        
        for(int i =0 ; i< N ; i++ ){
            heap.push(A[i]) ;
            
            if(heap.size() > K2){
                heap.pop() ;
            }
        }
        
        int  diff = K2 - K1 -1 ; 
        heap.pop() ;
        
        while(diff--){
            sum+= heap.top() ; 
            heap.pop() ;
        }
        
        return sum ;
        // vector<int>vec ;
        
        // long long sum  = 0 ; 
        
        // for(long long  i = 0 ; i< N ; i++){
        //     vec.push_back(A[i]) ;
        // } ;
        
        // sort(vec.begin() , vec.end()) ;
        
        // for (long long i = 0 ; i< N ; i++){
        //     if( i < K2 -1 && i > K1 -1 ){
        //         sum += vec[i] ; 
        //     }
        // }
        
        // return sum ;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends