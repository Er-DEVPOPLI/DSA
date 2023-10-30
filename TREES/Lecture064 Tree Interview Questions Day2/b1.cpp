

class Solution {
public:

  void left(Node* root , vector<int>&l){
      if((root ->left == NULL && root->right == NULL)|| (root == NULL)){
         
          return ;
      }
    //   if(root == NULL){
    //       return ;
    //   }
    
      l.push_back(root->data) ; 
      if(root->left != NULL ){
           left(root->left , l) ; 
      }
     else{
         left(root->right , l) ;
     }
      
      
      
  }
   void leaf(Node* root , vector<int>&mid){
      if(root->left == nullptr && root ->right ==nullptr  ){
          mid.push_back(root->data) ; 
          return ;
      }
      if(root == NULL){
          return ;
      }
      
      leaf(root ->left , mid) ; 
      leaf(root->right , mid) ; 
      
      
  }
  void right(Node* root , vector<int>&r){
      
  if((root->left == nullptr && root ->right == nullptr)|| (root == nullptr)){
      return ;
  }
  
     if(root->right != nullptr){
           right(root->right , r) ;
     } 
     else{
         right(root->left, r) ; 
     }
    
    r.push_back(root->data) ; 
      
  }
    vector <int> boundary(Node *root)
    {  vector<int>ans ; 
    ans.push_back(root->data) ;
        left(root->left ,ans) ; 
        leaf(root->left, ans) ; 
         leaf(root->right, ans) ; 
        right(root->right , ans ) ;
        //Your code here
        // vector<int>ans2 ; 
        // ans.pop_back() ; 
        // for(int i =0 ; i<ans.size()-1 ; i++){
        //     ans2[i] = ans[i];
        // }
        return ans  ;
    }
};