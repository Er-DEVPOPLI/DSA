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
void inorder(BinaryTreeNode<int>* root, vector<int>& sot){
    if(root == nullptr){
        return ;
    }
    inorder(root->left ,sot );
    sot.push_back(root->data) ; 
    inorder(root->right ,sot);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    
    vector<int>sot ; 

    inorder(root , sot); 
  
  if(k <= sot.size()){
       return sot[k-1];
  }
    else {
        return -1  ;
    }
}

//****************************** approach  2


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
int ans(BinaryTreeNode<int>* root, int k ,int &i){
    if(root == nullptr){
        return -1 ;
    }
    
    int left = ans(root->left , k , i); 
    if(left != -1 ){
        return left ;
    }
    i++ ; 
    if(i == k){
        return root ->data; 
    }

    return ans(root->right , k , i) ;
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
   int i =0; 
   return ans(root , k , i) ; 
}



//****************
void solve(BinaryTreeNode<int>* root, int k ,int&i, int &r){
    if(root == NULL){
        return ; 
    }
   solve(root->left , k , i,r) ; 
   i++; 
   if(i == k){
    r = root->data ; 

   }
   solve(root->right , k , i ,r) ; 

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
   int i = 0 ; int r = -1 ; 
   solve(root, k , i , r) ; 
   return r ; 
}  