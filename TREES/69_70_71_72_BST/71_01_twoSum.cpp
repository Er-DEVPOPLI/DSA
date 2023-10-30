#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
void inorder(BinaryTreeNode<int>* root, vector<int>& ans){
    if(root == NULL){
        return ; 
    }
    inorder(root ->left, ans) ; 
    ans.push_back(root->data); 
    inorder(root->right , ans ) ; 

}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
       vector<int>ans ; 
 inorder(root , ans) ; 

 int i = 0; 
 int j = ans.size() -1 ; 


 while(i < j){
     int sum = (ans[i] + ans[j]) ;

         if(sum == target){
                 return true ; 
         }

         if( sum > target){
        j-- ; 
     

         }
         if(sum < target){
             i++ ; 
         }

 }

 return false ; 
}