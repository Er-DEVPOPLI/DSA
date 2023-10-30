#include<iostream>
using namespace std;

class node{
    public: 
    int data ; 
    node* next ; 


    node(int m ){
        this->data = m ; 
        this->next = NULL ;

    } ; 

};

void first(node* &head  ,int d){

    node* temp =new node(d) ; 
    temp->next = head ; 
    head = temp ; 
}

void last(node* &tail  ,int d){
     node* temp =new node(d) ; 
    temp->next = NULL ; 
   tail->next= temp; 
   tail =temp ; 

}

void print(node*&head ){
    if(head==NULL){
        return  ;
    }
    int cnt =1 ;
    node* temp =head ; 

    while(temp!=NULL){
        cout<<temp->data <<" " ; 
        temp = temp->next ;
    }
}
void position(node* &head , int d ,int pos){
    if(pos==1){
        first(head,d) ; 
        return ;  
    }

    int cnt = 1  ; 
    node* temp = head ; 
    node* pre = NULL ;

    while(cnt<pos){
       
        temp = temp->next ; cnt++ ; 
    }
        node* t = new node(d) ; 
 
        t->next = temp->next  ;  
        temp->next = t; 
        
    }

    void del(node* &head ,int  pos  ){
        if(pos==1){
             node* temp = head ; 
             head = head->next ; 
             delete temp ;
        }

        else{
             int cnt = 1  ; 
             

        }
    }


int main(){


    node* head = new node(10) ; 
    node* tail = head; 

   first(head ,40) ;    
    last(tail ,70) ;
    position(head, 50 ,2) ; 
print(head) ; 
      
return 0 ;
}