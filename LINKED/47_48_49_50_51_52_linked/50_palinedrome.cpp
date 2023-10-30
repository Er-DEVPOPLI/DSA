//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>
class Solution{
  private : 
   int checkp(vector<int> arr ){
       int n = arr.size() ; 
       int s = 0 ;
       int e = n-1 ; 
       while(s<=e){
           if(arr[s] != arr[e]){
               return 0 ; 
           }
           s++ ; e-- ; 
       }
       return 1 ; 
   }
   public: 
   vector<int>arr ; 
    bool isPalindrome(Node *head)
    {
        
        
        Node* temp = head ; 
        
        while(temp!=NULL){
            arr.push_back(temp->data); 
            temp = temp->next ;
        }
        
        
        return checkp(arr) ; 
        
    }
};




//*************************  Approach 2 *******************

#include<vector>
class Solution{
  private : 
   Node* rev(Node *head){
       if(head->next == NULL || head == NULL){
           return head ;
       }
       Node* prev = NULL ; 
       Node* curr = head ; 
       Node* f = NULL ;
       
       while(curr!=NULL){
           f = curr->next ; 
           curr->next = prev ; 
           prev = curr ; 
           curr = f ; 
       }
       return prev ; 
   }
   
   public: 
   
    bool isPalindrome(Node *head)
    {
        
         if(head ->next == NULL){
             return 1 ;
         }
         
        Node* slow = head ; 
        Node* fast = head ;
        
        while(fast->next != NULL && fast->next->next != NULL){
           fast = fast->next->next  ;
           slow = slow->next ;  }
           
        slow->next = rev(slow->next ) ; 
        Node* temp = head; 
        Node* s = slow->next ;
        while(s != NULL ){
            if(temp->data != s->data ){
                return 0 ; 
            }
            s = s->next ; 
            temp = temp ->next  ;
            
        }
      
        
        
        return 1 ; 
    
        
    }
};