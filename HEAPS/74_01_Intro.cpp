#include<iostream>
#include<queue> 

using namespace std;
/*
heap sort {
    // step 1  :  build heap 
    // step 2 : logic for heapSort 

// STL  priority queue se minHeap and Max Heap create krenge '

}
*/
class heap{
    public : 
     int arr[100] ; 
     int size ; 
 

 heap(){
    size = 0 ; 
    arr[0] = -1 ;
 }
     void insert(int val){
        size = size +1 ;
        int index = size ; 
        arr[index] = val ; 

        while(index > 1){
            int parent = index/2 ; 

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent  ; 

            }else{
                return  ;
            }
        }
     }

    void print(){
        for(int i = 1 ; i<= size  ; i++){
            cout<<arr[i]<<" " ; 

        }cout<<endl ; 
    }
} ; 

// Below  is for Max Heap **************----------------------------------------------------------
        
void heapify(int arr[] , int n , int i ){
    int largest = i ; 
    int left = 2*i ; 
    int right = 2*i + 1 ; 

    if(left <= n && arr[largest] < arr[left]){
        largest = left ; 
    }
     if(right  <= n && arr[largest] < arr[right]){
        largest = right ; 
    }

    if(largest != i){
        swap(arr[largest] , arr[i])  ;
        heapify(arr, n , largest) ; 
    }
}

// ************************ For Min Heap ******************--------------------
        
void heapify_MinHeap(int arr[] , int n , int i ){
    int smallest = i ; 
    int left = 2*i ; // int left = 2*i ;  ------------> valid for 1 based Indexing   // for zero based indexing :-  int left = 2*i+1 ;
    int right = 2*i + 1;// int right = 2*i + 1 ; ------------> valid for 1 based Indexing // for zero based indexing :-  int right = 2*i + 2 ;

    if(left <= n && arr[smallest] > arr[left]){
       smallest= left ; 
    }
     if(right  <= n && arr[smallest] > arr[right]){
        smallest = right ; 
    }

    if(smallest != i){
        swap(arr[smallest] , arr[i])  ;
       heapify_MinHeap(arr, n , smallest) ; 
    }
}

void heap_sort(int arr[] , int n){
    int size = n ; 
    while(size>1){
        // step 1 : swap 
        swap(arr[size] , arr[1]) ; 
        size-- ; 

        // step 2 
  heapify(arr , size , 1) ; 

    }
}

int main(){
      

      heap h ; 

      h.insert(50) ; 
      h.insert(55); 
      h.insert(53) ; 
      h.insert(52) ; 
      h.insert(54) ; 

      h.print() ; 

      int arr[6] = {-1 , 54,53,55,52,50} ; 
      int n =5 ; 

      for(int i =n/2 ; i>0 ; i--){
        heapify(arr,n,i);
      }

      cout<<"printing the array now for******* Max HEAP ************ "<<endl<<endl  ; 

      for(int i = 1 ; i<=n ; i++){
      cout<<arr[i]<<" " ;
      }cout<<endl ;

        //  heap sor
        heap_sort(arr,n) ; 
        cout<<endl<<"printing the******** HEAP SORT ******"<<endl <<endl ; 
      for(int i = 1 ; i<=n ; i++){
      cout<<arr[i]<<" " ;
      }
      cout<<endl <<endl<<endl  ;
 // **************************************  priority_queue ********************************

 priority_queue<int> pq  ; 

 pq.push(4) ; 
 pq.push(2) ; 
 pq.push(5) ; 
 pq.push(3) ; 

 cout<<" Element at top : "<<pq.top() <<endl ;  // max_heap me top element largest hoga 
 pq.pop() ; 
cout<<" Element at top : "<<pq.top() <<endl ;  // max_heap me top element largest hoga 

 cout<<" Size is : "<<pq.size()<<endl  ; 


 if(pq.empty()){
    cout<<"pq is Empty . "<<endl ;
 }
 else{
    cout<<"pq is not Empty ."<<endl ; 
 }


// ******************  for min heap 

priority_queue<int,vector<int>, greater<int>> minheap ; 




minheap.push(4) ; 
minheap.push(2) ; 
minheap.push(5) ; 
minheap.push(3) ; 

cout<<endl<<" Element at top : "<< minheap.top() <<endl ;  // max_heap me top element largest hoga 
  minheap.pop() ; 
cout<<" Element at top : "<< minheap.top() <<endl ;  // min_heap me top element smallest hoga 

 cout<<" Size is : "<< minheap.size()<<endl  ; 


 if(minheap.empty()){
    cout<<"minheap is Empty . "<<endl ;
 }
 else{
    cout<<"minheap  is not Empty ."<<endl ; 
 }
return 0 ;
}