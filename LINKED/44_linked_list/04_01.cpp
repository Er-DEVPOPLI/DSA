class Solution{
    public:
    // // int getLength(Node* head) {
    // int len = 0;
    // Node* temp  = head ;

    // while(temp != NULL) {
    //     len++;
    //     temp  = temp -> next;
    // }

//     return len;
// }
    // int len(Node* &head){
    //     if(head == NULL){
    //         return 0 ; 
    //     }
    //     int cnt = 1 ; 
    //     Node* temp = head ; 
    //     while(temp!=NULL){
   //  cnt++ ;
    //         temp = temp->next ; 
    //         
    //     }
    //     return cnt; 
    // }
    int getMiddle(Node *head)
    {
        //  int mid = ( getLength(head)/2 ) + 1;
         
        //  int cnt = 1 ; 
         
        //  Node *temp = head;
        //  while(cnt<mid){
        //      temp = temp->next ; 
        //      cnt++ ;
             
        //  }
        
        //  return temp->data ;
        
   
    Node* d = head ; 
     Node* s = head ; 
     
     while(d->next != NULL){
         d = d->next ; 
         if(d != NULL){
             d = d->next ; 
           
         }
         s= s->next ; 
     }
        
        return s->data ;
        
            
    }
};