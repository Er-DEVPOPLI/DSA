//****************** method 1*****************   MAP
void redup(Node* head ){
    Node* temp = head ; 
     Node* pre = NULL ; 
    map<int,int >ch ;

    while(temp!=NULL){
        if(ch[temp->data] == 1){
           Node* m = temp ; 
           temp = temp->next  ;
           m->next = NULL ;
           delete m ; 
           pre->next = temp ;
        }
        else{
            ch[temp->data] = 1 ; 
            pre = temp ; 
            temp = temp->next ; 
        }
    }

  
}

//********************** METHOD 2 ******************  iteration