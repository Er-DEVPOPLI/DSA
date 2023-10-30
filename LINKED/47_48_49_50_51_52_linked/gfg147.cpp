

// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
   
      
    Node* reverse(Node* head){
        Node* prev = NULL ;
        Node* curr = head ; 
        Node* f = NULL ;
        while( curr != NULL){
            f = curr->next ;
            curr->next = prev ; 
            prev = curr ; 
            curr = f ; 
        }
        return prev ; 
    }
    
    void insert(Node* &head ,Node* &tail , int data ){
         Node* m = new Node(data); 
        if(head == NULL){
            head = m  ; 
            tail = m ; 
        }
        else{
            tail->next = m ; 
            tail = m ;
        }
    }
    
    
    Node* addOne(Node *head) 
    {
    
     
     int carry = 0 ; 
     
     Node* temp = reverse(head) ; 
     int count = 0 ;
     
     Node* h = NULL ; 
     Node* t = NULL ; 
     int sum = 0 ;
     
     while(temp!= 0){
         if(count == 0){
             sum = 1 + temp->data + carry  ;
              ++count  ;
         }
         else{
             sum = temp->data +carry ; 
             ++count ;
         }
       
        int digit = sum %10 ;
        insert(h , t , digit) ; 
        
        carry = sum /10 ;
        temp = temp->next ;
     }
    
    
    while(carry != NULL){
      int sum = carry ;
      int digit = sum %10; 
      
      insert(h,t,digit) ; 
        carry = carry /10 ; 
        
    }
    
 Node* m1 = reverse(h) ; 
 
    
 return m1  ; 
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
};
