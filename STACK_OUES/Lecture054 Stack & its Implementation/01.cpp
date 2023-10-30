#include<iostream>
using namespace std;

class stack{

    public: 
      int *arr ; 
      int size  ; 
      int top ; 


 stack(int size){
    this->size = size ; 
     arr = new int[size] ; 
     top = -1 ;  
 }

 void push(int x){
    if(size - top > 1){
        top++ ; 
        arr[top] = x ;   }
        else{
            cout<<"stack overflow " ; 
        }
 }

 int peek(){
    if(top >= 0){
        return arr[top] ; 
    }
    else{
        return -1 ; 
    }
 } 

 void pop(){
    if(top == -1){
        cout<<"UNDERFLOW " ; 
    }
    else{
        top-- ;

    }
 }

 int isempty(){
    if(top == -1){
        return 1 ;
    }
    else{
        return -1; 
    }
 }


void print(){
   for(int i =0 ; i <= top ; i++){
    cout<<arr[i]<<" " ; 
   }
}
};
int main(){
  stack s(7) ; 
  s.push(4) ; 
  s.push(6) ; 
  s.push(7) ; 



 s.pop() ;  s.print() ; 


 cout<<s.peek()<<" " ; 
return 0 ;
}