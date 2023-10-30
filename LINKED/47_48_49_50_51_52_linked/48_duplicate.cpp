#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

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

void del(Node* head){
    Node* curr = head ; 

    while(curr!=NULL && curr->next!=NULL){
        Node* temp = curr->next ; 
        Node* prev = curr ; 
        while(temp!=NULL){
            // cout<<"prev : "<<prev->data << "temp: "<<temp->data <<endl; 
            if(curr->data == temp->data  ){
                prev->next = temp->next ;
                delete (temp);  
               temp = prev->next ;
            }
            else{
            //    prev = temp ;
                temp = temp->next ;
            }
    //    temp = temp->next ;  
        }
         curr = curr->next ;
    }

   
  
}




int main() {
    
    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;
    
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    //print(head);

    insertAtTail(tail, 12);

    //print(head);
    
    insertAtTail(tail, 10);
     insertAtTail(tail, 12);
      insertAtTail(tail, 10);
    //print(head);

    insertAtPosition(tail,head, 6, 22);
     insertAtPosition(tail,head, 6, 22);
      insertAtPosition(tail,head, 6, 22);
    //print(head);    

    //cout << "head " << head -> data << endl;
    //cout << "tail " << tail -> data << endl;

    //deleteNode(4, head);
    

   

  
    print(head);


cout<<endl ; 
//  print(head); 
del(head) ;
print(head);
  cout<<"ans : " <<head->next->next->next->data ; 
   


    return 0;
}