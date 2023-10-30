#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Node{
    public : 
     int data ; 
     Node* next ; 
     
}; 

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}


Node* start(Node* head){
   if(head== NULL ){
      return head ; 
   }

   map<Node* , bool > b ; 

  Node* temp = head;

  while(temp!= NULL){
    if(b[temp] == true){
        return temp ; 
    }
    b[temp] = true ; 
    temp = temp->next; 

  }   return NULL ;
   }


}

int main(){




return 0 ;
}