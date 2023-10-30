#include<iostream>
using namespace std;

class node{
    public: 
      node* pre ; 
      int data ; 
      node* next ;

      node(int d){
        this->data = d ;
          this->pre = NULL ; 
          this->next = NULL ; 

      }
} ; 

void del(node* &head  ,int pos){
    if(head == NULL){
        cout<<"Empty list" ; 
        return ; 
    }
    if(pos==1){
        // if(head->next ==NULL){
        //     head = NULL ;
        //     return ; 
        // }
        // else{
        // node *temp = head ;
        
        // head = temp->next ;
        // temp->next->pre = NULL ;
        // temp->next = NULL ;
        node* temp = head;
        temp -> next -> pre = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
     
        delete temp ;
        }
    
    int cnt = 1 ;
    node* curr = head ; 
    node* p = NULL ;

    while(cnt<pos){
        p = curr ; 
        curr = curr->next ; 
        cnt++ ; 

    }
    if(curr->next  == NULL){
        curr->pre = NULL  ;
        p->next =NULL;
        delete curr ;
        return ;

    }
    p->next = curr->next ; 
    curr->next->pre = p  ;
    delete curr ; 

}

void first(node* &head , int d){
    if(head==NULL){
         node* temp = new node(d) ;
         head = temp ; 
         return ; 

    }
    else{
    node* temp = new node(d) ; 
      temp->next = head ; 
      head ->pre = temp ; 
      head = temp ; 
}
}

void post(node* &head , int d ,int pos){
    if(pos== 1){
   first(head,d);   return ;
    }
    int cnt = 1 ; 
    node* p  = NULL ; 
    node* curr = head ; 
    

    while(cnt<pos){
         p = curr ;
        curr = curr->next ;
        cnt++ ;
         
    }
    if(p->next ==NULL){
        node* temp= new node(d) ; 
        p->next = temp ;
        temp->pre = p ;
        return ; 
    }

    node* temp= new node(d) ; 
    temp -> next = curr; 
    p->next = temp ;
     curr->pre = temp ; 
     temp->pre = p ; 

}


void print(node* &head ){
    
        node *temp = head ;
        while(temp!=NULL){
            cout<<temp->data <<" " ; 
               temp= temp->next ; 
       }

    }


int main(){  
   

 node* str= new node(12 ) ; 
 node* head = str ; 

//    print(head) ;   
// cout<<endl ; 
   first(head,179) ; first(head,109) ; first(head,199) ; 
//    print(head); 
   
  
cout<<endl ;
      post(head ,11,3) ;
    //    cout<<head->data ; 
  
          post(head ,91,6) ;
del(head,1);
      print(head) ;

return 0 ;
}