

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        // approach 1 , 2 both are correct  
        
        
        priority_queue<int , vector<int> , greater<int>>heap ; 
        vector<int>vec ; 
        
        for(int i =0 ; i < N ; i++){
            
            int sum = 0 ; 
            
            for(int j = i; j < N ;j++){
                sum += Arr[j] ; 
                heap.push(sum) ; 
                
                if(heap.size() > K ){
                    heap.pop() ; 
                }
                // vec.push_back(sum) ; 
                
            }
        }
        // sort(vec.begin() , vec.end()) ; 
        // 
        return heap.top() ; 
    }
};