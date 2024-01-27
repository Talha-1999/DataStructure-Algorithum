//                                  7
//                                /   \
//                               2     3
//                              / \     \
//                             1   8     4

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

int main(){
    // Construct the node using function.
    struct Node *n=createNode(7); // it is a root node
    struct Node *n2=createNode(2); // it is a 2nd node
    struct Node *n3=createNode(3); // it is a 3rd node
    struct Node *n4=createNode(1); 
    struct Node *n5=createNode(4); 
    struct Node *n6=createNode(8); 


    // Linking the node with left and right children.
    n->left=n2;
    n->right=n3;

    n2->left=n4;
    n2->right=n6;
    n3->right=n5;


    inOrderTraversal(n);

    return 0;
}