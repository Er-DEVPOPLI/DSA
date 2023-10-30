class Solution{
    public:
    int FindPosition(int in[] , int n , int num , int inStart , int inEnd){
        
        for(int i =inStart ; i<= inEnd ; i++){
            if(in[i] == num){
                return i ; 
            }
        }
        return -1 ; 
    }
    Node* rec(int in[] , int pre[], int n , int inStart ,int inEnd, int& index){
      
      
      if(index >=n || inStart > inEnd){
          return NULL ;
      }
      
      int ele = pre[index++] ; 
       Node* m = new Node(ele) ;
        //  if (inStart == inEnd){
        //       return m;
        //  }
       
      int pos =FindPosition(in , n , ele , inStart , inEnd) ; 
     
      
      m->left = rec(in , pre , n , inStart , pos-1 , index ) ; 
      m->right = rec(in , pre ,n, pos+1 , inEnd , index ) ; 
      
      
      
      return m ; 
      
    }
    Node* buildTree(int in[],int pre[], int n)
    {  int index = 0 ; 
       Node* ans = rec(in , pre , n , 0 , n-1 ,index) ; 
       return ans ; 
    }
};