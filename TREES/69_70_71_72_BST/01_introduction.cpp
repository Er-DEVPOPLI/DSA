 #include<iostream>
#include<queue>
using namespace std;

class node{
    public :
    int data ; 
    node* left ;
    node* right ; 

    node(int d){
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }

};

void levelorder(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}


void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}
node* insertBST(node* root , int d){
    if(root == nullptr){
        root = new node(d);
        return root ;
    }

    if(d > root->data ){
        root ->right = insertBST(root->right ,d); 

    }
    else{
        root ->left = insertBST(root->left ,d) ; 
    }

    return root ;
}

void takeinput(node* &root){
    int data ; 
    cin>>data ; 

    while(data != -1){
        root = insertBST(root , data) ; 
        cin>>data ; 

    }
}

node* minval(node* root ){
    node* temp = root ; 

    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp ; 
}
  

node* Maxval(node* root ){
    node* temp = root ; 

    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp ; 
}

node* deletefromBST(node* &root , int val){
     // base 
    if(root == nullptr){
        return root ;
    }

    if(root ->data == val){
        //0 child
          if(root->left == nullptr && root ->right == nullptr ){
            delete root ; 
            return nullptr ;
          }
        // 1 child
           
           // left child
           if(root ->left != NULL && root ->right == NULL){
            node* temp = root->left ; 
            delete root ; 
            return temp ;
           }

           // right child
            if(root ->left == NULL && root ->right != NULL){
            node* temp = root->right ; 
            delete root ; 
            return temp ;
           }
        // 2 child
  
      if(root ->left != nullptr && root->right != nullptr ){
        int mini = minval(root->right )->data;   // ya fir max from left side can be calculated 
        root->data = mini ; 
        root->right = deletefromBST(root->right ,mini) ;
        return root ; 


// OR 

        //  int maxi = Maxval(root->left )->data;   // ya fir max from left side can be calculated 
        // root->data = maxi ; 
        // root->left = deletefromBST(root->left ,maxi) ;
        // return root ; 
      }

    }
    else if(root->data > val){
        root ->left = deletefromBST(root->left , val) ;
        // return root ;
    }
    else{
        root->right = deletefromBST(root->right ,val) ; 
        // return root ; 
    }
}
int main(){
  node* root = nullptr ; 

  cout<<"enter data : "<<endl ;
  takeinput(root) ; 
 




cout<<" printing : level order "<<endl<<endl ;

 levelorder(root) ;
cout<<" printing : pre-oreder  "<<endl<<endl ;
 preorder(root ) ; 
cout<<"Min val : "<<minval(root)->data << endl ; 
cout<<"Max val : "<< Maxval(root)->data <<endl ;
root = deletefromBST(root , 30 ) ;

cout<<endl<<"After Deletion "<<endl<<endl ;
cout<<" printing : level order "<<endl<<endl ;

 levelorder(root) ;
cout<<" printing : pre-oreder  "<<endl<<endl ;
 preorder(root ) ; 
return 0 ;
}