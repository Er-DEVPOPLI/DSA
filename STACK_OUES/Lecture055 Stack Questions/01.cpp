#include<iostream>
#include<stack>

using namespace std;

int main(){

    string str = "LOVE" ; 
    string ptr = "" ;

  stack<char> ans  ;


  for(int i = 0; i<str.length() ; i++){
    char ch = str[i] ; 
     ans.push(ch) ; 
       
  }

  while(ans.empty() != 1){
    char ph = ans.top() ; 
     ptr.push_back(ph) ; 
     ans.pop() ; 

  }

  cout<<"ans : "<<ptr ; 






return 0 ;
}