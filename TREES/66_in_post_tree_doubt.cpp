class Solution{
    public:
    void createmap(int in[] , map<int,int> &mapping , int n){
        for(int i = 0 ; i<n ; i++){
            mapping[in[i]] = i ; 
            
        }
    }
    // int FindPosition(int in[] , int n , int num , int inStart , int inEnd){
        
    //     for(int i =inStart ; i<= inEnd ; i++){
    //         if(in[i] == num){
    //             return i ; 
    //         }
    //     }
    //     return -1 ; 
    // }
    Node* rec(int in[] , int post[], int n , int inStart ,int inEnd, int &index , 
    map<int,int>& mapping){
      
      
      if(index < 0 || inStart > inEnd){
          return NULL ;
      }
      
      int ele = post[index--] ; 
       Node* m = new Node(ele) ;
        //  if (inStart == inEnd){
        //       return m;
        //  }
       
      int pos = mapping[ele]; 
     
       m->right = rec(in , post ,n, pos+1 , inEnd ,index ,mapping ) ; 
      m->left = rec(in , post , n , inStart , pos-1 , index , mapping ) ; 
     
      
      
      
      return m ; 
      
    }
    // Node* buildans(int in[],int pre[], int n)
    // {  int index = n-1 ; 
    //   Node* ans = rec(in , pre , n , 0 , n-1 ,index) ; 
    //   return ans ; 
    // }
    Node *buildTree(int in[], int post[], int n) {
//   Node* ans = buildans(in, post , n) ; 
//   return ans ;
map<int , int>mapping ; 

int index = n-1 ; 
       Node* ans = rec(in , post , n , 0 , n-1 ,index , mapping) ; 
       
       return ans ; 
}

};