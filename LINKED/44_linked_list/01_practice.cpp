#include<iostream>
using namespace std;

class Node{

    public: 
    int data ;
    Node *next ;

Node(int data){
    this -> data = data ;
    this-> next = NULL;
}

};

void infront(Node* &head , int data){
    Node *temp = new Node(data) ; 
    temp -> next = head ; 
    head = temp ; 

}

void inback(Node* &tail , int data){
    Node * temp = new Node(data) ;
    tail ->next = temp ; 
    tail = temp ; 
}

void print(Node * &head){
    if(head == NULL){
        cout<<" list is Empty ! "<<endl ; 
        return ; 

    }

    Node *temp = head ; 

    while(temp!= NULL){
        cout<<temp->data <<" " ; 
         temp = temp->next ; 

    }

}

void pos(Node* &head , Node* &tail , int pos ,int data){
    if(pos == 1){
        infront(head ,data); 
        return ;
    }
    Node *temp = head; 
    int cnt = 1;

    while(cnt<pos-1){
        temp = temp->next ; 
        cnt++ ; 
    }
    if(temp->next == NULL){
        inback(head ,data);
        return ;
    }

    Node *node1 = new Node(data);
     node1->next = temp->next ;
     temp->next = node1 ; 
     return ; 

}

void indelete(Node* &head ,int pos){
    if(pos == 1){
        Node *temp = head ;
        head = head ->next ;
        temp->next = NULL ; 
        delete temp ; 
    }
    else {
        Node *curr  = head ; 
        Node *prev = NULL ;

        int cnt = 1 ; 

        while(cnt < pos){
            prev = curr  ; 
            curr = curr -> next ; 
            cnt ++ ;

    }
    prev -> next = curr->next ;
    curr ->next =NULL ; 
    delete curr ; 

} 
}


int main(){

    Node *node1 = new Node(12); 
    // Node *node2 = new Node(22); 
    

    Node *head = node1 ; 
    Node *tail  = node1 ; 
    infront(head , 13); 
      infront(head, 89); 
        infront(head , 79); 
           
        //    pos(head , tail, 10 ,  12); 
                
                
                print(head) ; 

               indelete(head ,3) ;
cout<<"\n" ; 
              
                inback(tail , 45) ; 
                inback(tail, 67) ; 
                cout<<"\n" ; 
print(head);
return 0 ;
}