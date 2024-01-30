#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

// case 1 : delete the leaf node.
// case 2 : delete the root node.
// case 3 : delete the node between BST.


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

struct Node * inOrderPredecessor(struct Node*root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct Node* deleteNode(struct Node*root,int value){
    struct Node*iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->right==NULL && root->left==NULL){
        free(root);
        return NULL;
    }
    // Search for the node for deleted.
    if(value<root->data){
       root->left= deleteNode(root->left,value);
    }else if(value>root->data){
       root->right= deleteNode(root->right,value);
    }else{
        // Delete strategy when the node is found.
        iPre=inOrderPredecessor(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left,iPre->data);
    }
    return root;

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

    inOrderTraversal(n);
    deleteNode(n,7);
    cout<<endl;
    inOrderTraversal(n);
    

    return 0;
}