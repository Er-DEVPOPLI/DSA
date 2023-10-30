
// ********************** Approach 1 ***********************************
 BinaryTreeNode<int>* bst(vector<int>&val , int s , int e){
      if(s>e ){
          return nullptr ;
      }
      int mid = (s+e)/2 ; 
     BinaryTreeNode<int>* R = new BinaryTreeNode<int>(val[mid]) ;
      R ->left = bst(val,s,mid-1) ; 
      R->right = bst(val , mid+1 , e) ; 

      return R ;
  }
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int n = preorder.size()-1 ; 
   sort(preorder.begin() , preorder.end() ) ; 
   return bst(preorder , 0 , n ) ; 
}


//******************* Approach 2 ******************************

#include <bits/stdc++.h> 

BinaryTreeNode<int>*BST(vector<int> &preorder, int &i , long min , long max) {
    if(i >= preorder.size() ){
        return NULL ;
    }
    
    if(preorder[i] < min || preorder[i] > max ){
        return NULL ; 
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = BST(preorder , i , min , root->data) ; 
    root->right = BST(preorder, i , root->data , max ); 


    return root ; 
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i =0 ; 
    return BST(preorder , i, INT_MIN , INT_MAX) ; 
}