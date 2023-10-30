#include<iostream>
using namespace std;

class node{
    public: 
    int data ; 
    node* next ; 

    node(int d){
        this->data = d ;
        this ->next = NULL ; 

    }
}; 

void in(node*&head , int ele , int d){
    if(head == NULL){
        node* temp = new node(d) ; 
        temp->next = temp ; 
        head = temp ;
    }
    else{

        node*curr = head ; 
        while(curr->data != ele){
curr = curr->next ; 
        }
         node* temp = new node(d) ; 
         temp->next = curr->next ; 
         curr->next = temp ;
         

    }
}

void del(node* &head, int ele){
      if(head==NULL){
        cout<<"empty" ;
return ;
    }
    node* pre = head ; 
    node* curr= pre->next ; 
    if(curr== pre){
        head = NULL ; 
        return ;
    }
    while(curr)

}
void print(node* &head){
    if(head==NULL){
        cout<<"empty" ;
return ;
    }
    else{
        node* temp = head; 
do{
    cout<<temp->data<<" ";
    temp= temp->next ; 
}while(temp != head) ; 

    }
}
int main(){
    node* head = NULL ;
in(head , 2,4) ;
in(head , 4,40) ;in(head , 40,50) ;in(head , 50,41) ;in(head , 41,42) ;
print(head) ;


return 0 ;
}