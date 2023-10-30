/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int>* root , vector<int> &val){
    if(root == nullptr ){
        return ;
    }
    inorder(root->left , val); 
    val.push_back(root->data) ; 
    inorder(root->right ,val) ; 
}
  TreeNode<int>* bst(vector<int>&val , int s , int e){
      if(s>e ){
          return nullptr ;
      }
      int mid = (s+e)/2 ; 
      TreeNode<int>* R = new TreeNode<int>(val[mid]) ;
      R ->left = bst(val,s,mid-1) ; 
      R->right = bst(val , mid+1 , e) ; 

      return R ;
  }
TreeNode<int>* balancedBst(TreeNode<int>* root) {
  vector<int>val ; 
inorder(root , val) ; 
return bst(val, 0 , val.size()-1 ) ; 


}
