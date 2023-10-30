
class Solution
{
    public:
    void flatten(Node *root)
    {
       if(root == nullptr){
           return ; 
       }
       
       Node* curr = root ; 
       while(curr != NULL){
           
           if(curr->left != NULL){
               Node* pred = curr->left ;
               while(pred->right != NULL){
                   pred = pred->right ;
               }
               pred ->right = curr->right ; 
               curr->right = curr->left ; 
               curr->left = NULL ;
           }
           curr = curr->right ; 
       }
       // curr = root ; 
       /* while(curr!= NULL){
           curr->left = NULL ; 
           curr = curr->right ; 
       } */
       }
    }
};