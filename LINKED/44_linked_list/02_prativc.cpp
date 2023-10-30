#include<iostream>
using namespace std;

class node{
    public:
    int data ;
    node *next; 
    node *pre ;

node(int data){
    this->data = data ;
    this ->next =NULL;
    this ->pre = NULL ;
}
}; 
void infront(node* &head , int data ){
    node *n1 = new node(data) ; 
       n1->next = head ;
       head->pre = n1 ; 
       head = n1 ;
}

void inback(node* &tail , int data){
     node *n1 = new node(data) ; 
       tail->next = n1 ; 
      n1 ->pre = tail ; 
       tail = n1 ;
}

void inpos(node* &head , node* &tail , int pos ,int data){
    if(pos ==1 ){
        infront(head , data); 
        return ;
    }

    node *n = new node(data); 
    int cnt = 1 ; 


node *temp = head ;
    while(cnt < pos-1 ){
        temp = temp -> next ; 
        cnt++ ; 
    }
if(temp->next == NULL){
    inback(tail , data); 
return  ; 
}

n->next = temp->next ;
temp->next = n; 
 n->pre = temp ;
 temp->next->pre = n;
}

void print(node * &head){
    if(head == NULL){
        cout<<" list is Empty ! "<<endl ; 
        return ; 

    }

    node *temp = head ; 

    while(temp!= NULL){
        cout<<temp->data <<" " ; 
         temp = temp->next ; 

    }

} 

void indelete(node* &head , int pos){
    if(pos == 1){
        node* temp = head; 
        head= head->next ; 
        head ->pre =NULL; 
        temp->next = NULL ; 

        delete temp ; 

    }
    else {
         node* f = head; 
          node* b= NULL; 
          int cnt  = 1  ; 

          while(cnt < pos){
            b = f ; 
            f = f->next ; 

            cnt++ ; 
          }
          
b->next = f->next  ; 
f ->next ->pre = b ; 
delete f ; 

    }

}

int main(){
    node * n1  = new node(1) ; 

    node *head = n1 ; 
     node *tail = n1 ;

    infront(head, 12); infront(head, 11); infront(head, 10); infront(head, 9); 
    inback(tail , 13); inback(tail ,14 ); inback(tail , 15); inback(tail , 16); 
indelete(head ,2) ; 
    print(head); 



return 0 ;
}