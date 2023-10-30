

// doubt

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
void inorder(BinaryTreeNode<int> *root ,vector<int> &sot ){
    if(root == nullptr){
        return ; 
    }

    inorder(root->left, sot ); 
    sot.push_back(root ->data);
    inorder(root->right, sot);
}

bool check(vector<int>dt ){
    for(int i = 0 ; i<dt.size()-1 ; i++){
        if(dt[i] > dt[i+1]){
            return 0 ;
        }
    }
    return 1 ;  
}
bool validateBST(BinaryTreeNode<int> *root) {
    vector<int>sot ; 
    inorder(root,sot ); 

for(int i = 0 ; i<sot.size()-1 ; i++){
        if(sot[i] > sot[i+1]){
            return 0 ;
        }
    }
    return 1 ;  
    
}



//**************************** approach 2 *************
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
bool isBst(BinaryTreeNode<int> *root , long min , long max){
    if(root == nullptr ){
        return true ;
    }
    
    if(root ->data >= min && root->data <= max){
      bool left =   isBst(root->left, min , root->data ); 
      bool right  = isBst(root->right ,root->data , max) ; 
      return  (left && right ) ; 
    }
    
    return false ; 
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isBst(root, INT_MIN , INT_MAX) ; 
}