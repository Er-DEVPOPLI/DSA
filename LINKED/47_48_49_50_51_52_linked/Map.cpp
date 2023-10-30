#include<iostream>
#include<map>
#include<bits/stdc++.h>

using namespace std;
int main(){

map< int,string  > m ; 
map<string , int > g; 




m[1] = "dev" ; 
m[2] = "rahul" ;
m[3] = "Aniket" ;
m[4] = "Puneet" ; 
m[2] = "rah" ;
m.insert({6,"bheem"}) ; 


for(auto i : m){
    cout<<i.first <<" "<<i.second <<endl ;

}

cout<<"finding-> 2 :  "<<m.count(2)<<endl ; 
m.erase(2) ; 

for(auto i : m){
    cout<<i.first <<" "<<i.second <<endl ;

}
   
   auto it = m.find(4) ; 
   
cout<<endl<<endl ;

   for(auto i = it ; i!= m.end() ; i++){
    cout<<(*i).first<<endl ; 
   }


return 0 ;
}