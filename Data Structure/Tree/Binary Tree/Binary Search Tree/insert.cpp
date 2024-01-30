#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};


void inOrderTraversal(struct Node*root){
//  Rule :   Left subtree ----> Root ----> Right subtree
    if(root != NULL){
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }    

}


struct Node * createNode(int data){
    struct Node *n=new Node; // creating a node pointer and allocate memory in heap
    n->data=data; // setting the data
    n->left=NULL; // setting the left children is NULL
    n->right=NULL; // setting the right children is NULL
    return n;
}

void insert(struct Node*root,int key){
    struct Node*prev=NULL;
    while(root!=NULL){
        prev=root;
        if(root->data==key){
            cout<<"Already Available"<<endl;
        }
        if(key<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    struct Node* newNode=createNode(key);
    if(key < prev->data){
        prev->left=newNode;
        cout<<"Insert Successfully "<<"Connect left side of "<<prev->data<<endl;
    }else{
        prev->right=newNode;
        cout<<"Insert Successfully "<<"Connect right side of "<<prev->data<<endl;
    }

}

int main(){
    // Construct the node using function.
    struct Node *n=createNode(7); // it is a root node
    struct Node *n2=createNode(2); // it is a left node of root
    struct Node *n3=createNode(8); // it is a right node of root
    struct Node *n4=createNode(1); 
    struct Node *n5=createNode(3); 


    // Linking the node with left and right children.
    n->left=n2;
    n->right=n3;

    n2->left=n4;
    n2->right=n5;

    insert(n,11);
    cout<<endl;
    inOrderTraversal(n);
    

    return 0;
}