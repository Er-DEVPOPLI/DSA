
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {  
        
        vector<int>ans ;
        if(root == NULL){
            return ans ;
        }
    	queue<Node*>q1 ; 
    	int flag = 1 ;
    	q1.push(root);
    	 
    	while(q1.empty() != 1){
    	    int sz = q1.size() ; 
    	    vector<int>temp ; 
    	    
    	    while(sz--){
    	        Node* front = q1.front() ; 
    	        
    	        temp.push_back(front->data) ; 
    	        q1.pop() ; 
    	        if(front->left){
    	            q1.push(front->left) ;
    	        }
    	        if(front->right){
    	            q1.push(front->right) ;
    	        }
    	        
    	    }
    	    if(flag%2 == 0){ reverse(temp.begin() , temp.end()) ;}
    	    for(int i=0 ; i<temp.size() ; i++){
    	        ans.push_back(temp[i]);   
    	    }
    	    flag++ ;
    	    
    	}
    	
    return ans ;	
    	
    }
};