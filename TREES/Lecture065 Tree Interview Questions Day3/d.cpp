#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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


*************************************************************/
int an(BinaryTreeNode<int>* root, int k ,int &i){
    if(root == nullptr){
        return -1 ;
    }
    
    int left = an(root->left , k , i); 
    if(left != -1 ){
        return left ;
    }
    i++ ; 
    if(i == k){
        return root ->data; 
    }

    return an(root->right , k , i) ;
}


int ans (BinaryTreeNode<int>* root, int k ,int&i){
     if(root == nullptr){
        return -1 ;
    }

    int left = ans(root->left , k , i) ;

    if(left != NULL){
return left ;
    } 
    
    i++ ; 
    if(i == k){
        return root->data ;
    }

 return  ans(root->right , k , i) ; 
   
    
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
   int i = 0 ; 
   return ans(root , k , i);
}