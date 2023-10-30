/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
   Node* zerohead = new Node(-1) ; 
    
    Node* onehead = new Node(-1) ; 
    Node* twohead = new Node(-1) ; 
 Node* zerotail = zerohead; 
  Node* onetail = onehead; 
  Node* twotail = twohead;  

  Node* temp = head;
 
  while(temp != NULL){
 int val = temp->data ;

 if(val == 0){  zerotail ->next = temp ; zerotail = temp ;}
 else if(val == 1){onetail ->next = temp ; onetail = temp ;} 
 else if(val == 2){twotail ->next = temp ; twotail = temp ;} 
temp = temp->next ; 
 }

if(zerohead->next !=NULL){
zerotail->next = onehead->next ; 
onetail->next = twohead ->next ; 

}
else{
    zerotail->next = twohead->next ; 
}
 
 
  twotail->next = NULL ;

 head = zerohead->next ;

 delete zerohead ; 
 delete onehead ; 
 delete twohead  ; 


 return head ; 



















  
   
}