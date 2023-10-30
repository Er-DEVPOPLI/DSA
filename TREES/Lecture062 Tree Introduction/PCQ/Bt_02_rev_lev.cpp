vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans ; 
        
      queue<Node*>q ; 
      q.push(node);
      q.push(NULL) ; 
      
      
      while(!q.empty()){
          
          Node* temp = q.front() ; 
          q.pop() ; 
          
          if(temp !=NULL){
              ans.push_back(temp->data) ; 
             
              if(temp->right){
                   q.push(temp->right) ; 
              }
               if(temp->left){
                  q.push(temp->left) ; 
              }
          }
          
          else{
              if(!q.empty()){
                  q.push(NULL) ; 
              }
          }
         
          
      }
      reverse(ans.begin() , ans.end()) ; 
        return ans ;
}