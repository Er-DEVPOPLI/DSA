  int m =1 ; 
    bool solve(Node* root, bool &f){
        // if(root == NULL){
        //     return 0 ; 
        // }
        // int l = isBalanced(root ->left ) ; 
        //  int r = isBalanced(root ->right) ; 
         
        //  if(abs(l-r)<=1){
        //      f = true ; m = 1 ;
        //  }
        //  else{
        //       f = false; m = 0 ; 
        //  }
         
        //  return max(l ,r)+1 ; 
        
        if(root == nullptr ){
            return 0 ; 
        }
        
        int l = solve(root->left) ; 
        int r = solve(root ->right) ; 

if(abs(l-r)>1){
    return 0 ;
}
        int ans = max()
    }
    bool isBalanced(Node *root)
    {   
       bool f = true ;
        int s = solve(root ,f) ; 
        return f ;
    }