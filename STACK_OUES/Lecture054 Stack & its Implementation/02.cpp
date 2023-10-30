#include<iostream>
using namespace std;


class node{
    public: 
      int data  ;
       node* next ; 
        

    node(int x ){
        this->data = x ; 
        this->next = NULL ;
    }
}
class stack{
    public : 
     node* top = NULL ;



void push(int  d){
    node* temp = new temp(d) ; 

    if(temp != NULL){
        cout<<"stack overflow.." ; 
        exit(1) ; 
    }
    else{
         
    }
}




}
int main(){

return 0 ;
}