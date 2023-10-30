Node* reverseDLL(Node * head)
{
       Node* p = NULL ;
    Node* curr = head ; 
Node* f = NULL ;

    while(curr!= NULL){
        
        f = curr->next ; 
        curr->next =  p ;
        curr->prev = f ; 
        p = curr; 
        curr = f  ; 
    
    }
    return p ;

}