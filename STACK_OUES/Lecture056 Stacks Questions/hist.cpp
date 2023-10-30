
// doubt



class Solution {
public:

 vector<int>l ; 
 vector<int>r ; 

   void left(vector<int>&arr,int n){

      stack<pair<int,int>>st ; 
     

      for(int  i=0 ; i<n ;i++ ){
          while(!st.empty() && st.top().first<= arr[i] ){
               st.pop();
          } // while
          if(st.empty()){   l.push_back(-1);    ; }
          else{
             l.push_back(st.top().second); 
          }
          st.push({arr[i] ,i}) ; 
      } // for
  }


   void right(vector<int>&arr,int n){
      stack<pair<int,int>>st ; 
   

      for(int  i= n-1 ; i >=0 ;i-- ){
          while(!st.empty() and st.top().first >= arr[i] ){
               st.pop();
          } // while
          if(st.empty()){        r.push_back(n); }
          else{
             r.push_back(st.top().second); 
          }
          st.push({arr[i] ,i}) ; 
      } // for

      reverse(r.begin() , r.end()) ; 

  }


    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size() ; 

          left(heights , m) ; 
          right(heights,m) ; 

       vector<int>area ; 

        for(int i =0 ; i<m ;i++){
              int width = r[i]-l[i]-1 ;
    int hgt = heights[i] ; 
              area[i] = width * hgt ; 
        }// for

int num ;
        for(int i = 0 ; i<area.size() ; i++){
             num = area[0] ; 
 if(area[i] >= num){ num = area[i] ;  }
        } // for

        return num ;
    }
};