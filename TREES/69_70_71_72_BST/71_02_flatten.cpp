#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root, vector<TreeNode*>& ans){
    if(root == NULL){
        return ; 
    }
    inorder(root ->left, ans) ; 
    ans.push_back(root); 
    inorder(root->right , ans ) ; 

}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode*>ans ; 
    inorder( root , ans ) ; 

    for(int i =0 ; i< ans.size()-1 ; i++){
       ans[i] ->left = NULL ; 
       ans[i] ->right = ans[i+1]; 
    }
    ans[i+1] = NULL ;

    return ans[0] ;
}
//****************************************************************

/*************************************************************/
void inorder(TreeNode<int>* root , vector<int> &val){
    if(root == nullptr ){
        return ;
    }
    inorder(root->left , val); 
    val.push_back(root->data) ; 
    inorder(root->right ,val) ; 
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>val ; 
    inorder(root , val) ; 
   
   TreeNode<int>* head = new TreeNode<int> (val[0]) ;  
    TreeNode<int>* curr = head ;

    int i =1 ; 
    int n = val.size() ; 
    while(i<n){
        TreeNode<int>* temp = new TreeNode<int> (val[i]) ;
        curr->left = nullptr ; 
        curr->right = temp ; 
        curr = temp ;
        i++ ;
    }

 curr ->left = nullptr; 
 curr->right = nullptr  ;
 

 return head ; 
    
    
}
