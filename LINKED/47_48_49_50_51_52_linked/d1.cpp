//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
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

 Node* redup(Node* &head ){
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
  return head ; 
  
}

Node* findIntersection(Node* head1, Node* head2)
{    
    
    // map<int,int >mapping ; 
    
    // while()
    if(head1 == NULL || head2 == NULL ){
        return NULL ; 
    }
    
    Node* h = new Node(-1) ; 
    Node* t = h  ;
     Node* temp1 = redup(head1) ; 
     Node* temp2 = redup(head2) ; 
     
    
    while(temp1 != NULL){
        int val1 = temp1->data ; 
        
         while(temp2 != NULL){
             if(temp2->data == val1){
                 insert(h,t,val1) ; 
                 temp1 = temp1->next ; 
                 temp2= temp2->next ; 
             }
             else{
                 temp2 = temp2->next ; 
             }
             
         }
         temp1 = temp1->next  ; 
    }
    
    
    h = h->next ;
    
    return h ; 
    
    
    
    
    
    
    
}