#include<iostream>
using namespace std;

#include<vector>


int main(){
   

     vector<int>ans[4] ; 

     ans[0].push_back(1); ans[0].push_back(2); ans[0].push_back(3);
      ans[1].push_back(78); ans[1].push_back(29); ans[1].push_back(49);
       ans[2].push_back(100); ans[2].push_back(200); ans[2].push_back(300);ans[2].push_back(100); ans[2].push_back(200); ans[2].push_back(300);ans[2].push_back(100); ans[2].push_back(200); ans[2].push_back(300);
      
vector<vector<int>>ans2 ; 

ans2.push_back(ans[0]) ; 
ans2.push_back(ans[1]) ; 

cout<<"size "<<ans2.size() ; 



// for (int i = 0; i < 4; i++) {
//         std::cout << "ans[" << i << "]: ";
//         for (int j = 0; j < ans[i].size(); j++) {
//             std::cout << ans[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }


return 0 ;
}