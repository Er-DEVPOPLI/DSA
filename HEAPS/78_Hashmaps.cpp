#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){


      unordered_map<string,int>m;

      pair<string,int> p = make_pair("babbar" ,3) ; 
    m.insert(p); 

    pair<string,int> pair2("love" , 2) ; 
    m.insert(pair2) ; 

    m["mera"] = 1 ; 
     
     m["mera"] = 2  ; // update above by 2 


     // search 

     cout<< m["mera"]<<endl ; 
     cout<< m.at("babbar")<<endl ; 

      //cout<< m.at("unknown")<<endl  ;  // go=ive error but    m["unknown"]   will give zero  
      cout<< m["unknown"]<<endl ;
      cout<<m.size() <<endl ; 

      cout<< m.count("bro")<<endl ; // suggest key is presnt or not if present give 1 otherwise give 0 ; 



for(auto i : m){
    cout<<"i.first -> "<<i.first<<" "<<"i.second -> "<<i.second <<endl; 

}
      m.erase("babbar") ; 
      cout<<"m.size() : " <<m.size()<<endl ;


       //iterator 
       unordered_map<string,int> :: iterator it = m.begin() ; 
    map<string,int> :: iterator im = m.begin() ; // in this ordered is preserved  

      cout<<"iterator : "<<endl<<endl ; 
         while(it != m.end()){
        
        cout<<it->first<<" "<<it->second<<endl ; 
        it++ ;
              }







     




return 0 ;
}