/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode *root, vector<int>& ans ){
    if(root == NULL ){
        return ;
    }
  inorder(root->left , ans); 
   ans.push_back(root->data) ; 
   inorder(root->right , ans);

}

vector<int> ADD(vector<int>&ans1 , vector<int>&ans2 , vector<int>&merge){
    int i =0 ; 
    int j = 0 ; 
    int k = 0 ; 
 

while(i < ans1.size() && j <ans2.size()){
    if(ans1[i] < ans2[j]){
        merge[k] = ans1[i] ; 
        i++ ; k++ ;
    }
    else if(ans1[i] > ans2[j]){
        merge[k] = ans2[j] ; 
        j++ ; k++ ;
    }
    else{
        merge[k] = ans2[j] ; 
        j++ ; k++ ;
    }
}

while( i< ans1.size()){
    merge[k] = ans1[i] ; 
    i++ ; k++ ;
}

while( j< ans2.size()){
    merge[k] = ans2[j] ; 
    j++ ; k++ ;
}
  return merge ;

}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{    vector<int> ans1, ans2 ; 
      
      inorder(root1, ans1) ; 
       inorder(root2, ans2) ; 
   vector<int>mg(ans1.size()+ans2.size()) ;
   return ADD(ans1, ans2 , mg) ;

}


// ****************************** doubt 

/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void convertIntoSortedDLL(TreeNode *root, TreeNode *&head){
    //base case 
    if(root == NULL){
        return  ;
    }
    
   convertIntoSortedDLL(root->right , head) ; 
   
   root ->right = head ; 
   if(head != NULL){
       root ->left = root ; 
   }
       head = root  ; 
       
    convertIntoSortedDLL(root->left , head) ; 
}

TreeNode<int>mergeLinkedList(TreeNode *head1, TreeNode *head2){
    TreeNode *head = NULL;
     TreeNode *tail = NULL ; 
     

     while(head1 != NULL && head2 != NULL){
         if(head1->data < head2->data){
             if(head== nullptr){
                 head = head1 ; 
                 tail = head1 ; 
                 head1 = head1->right ; 
             }
             else{
                 tail ->right = head1 ; 
                 head1->left= tail ; 
                 tail = head1 ; 
                 head1 = head1 ->right ; 
             }
         }
         else{
              if(head== nullptr){
                 head = head2 ; 
                 tail = head2 ; 
                 head2 = head2->right ; 
             }
             else{
                 tail ->right = head2 ; 
                 head2->left= tail ; 
                 tail = head2 ; 
                 head2 = head2 ->right ; 
             }
         }
     }
    while(head1 != nullptr){
        tail ->right = head1 ; 
                 head1->left= tail ; 
                 tail = head1 ; 
                 head1 = head1 ->right ; 
    }
     while(head2 != nullptr){
       tail ->right = head2 ; 
                 head2->left= tail ; 
                 tail = head2 ; 
                 head2 = head2 ->right ; 
    }
}
int count(TreeNode *head){
    int cnt = 0 ; 
    TreeNode<int>*temp = head ; 
    while(temp != NULL){
        cnt++ ; 
        temp = temp ->right ;
    }
    return cnt ; 
}
TreeNode<int>* sortedLLtoBST(TreeNode *&head , int n ){
    if(n <= 0 || head == NULL){
        return NULL ; 
    }
    TreeNode *left = sortedLLtoBST(head , n/2) ; 
    TreeNode *root  = head ; 
    
    root->left = left ; 
    head =head->next ; 
    
    root->right = sortedLLtoBST(head , n-n/2-1) ; 
    return root ; 
    
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{  
    //1. CONVERT BST Into sortedDLL 
    TreeNode *head1 = NULL ; 
  convertIntoSortedDLL(root1 ,head1) ;
  head1->left = NULL ; 


  
TreeNode *head2 = NULL ; 
  convertIntoSortedDLL(root2 ,head2) ;
  head2->left = NULL ; 

// 2 mergeing 

  TreeNode *head = mergeLinkedList(head1,head2) ;
  

  // 3. sll to bst 
  return sortedLLtoBST(head , count(head) ) ;







  
}