
// Represent the Binary Tree using linked Representation.

//                                  2
//                                /   \
//                               1     4
//                              / \   / \
//                             11 12 N   3

#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node *n=new Node; // creating a node pointer and allocate memory in heap
    n->data=data; // setting the data
    n->left=NULL; // setting the left children is NULL
    n->right=NULL; // setting the right children is NULL
    return n;
}

int main(){
    // Construct the node using function.
    struct Node *n=createNode(2); // it is a root node
    struct Node *n2=createNode(1); // it is a 2nd node
    struct Node *n3=createNode(4); // it is a 3rd node

    // Linking the node with left and right children.
    n->left=n2;
    n->right=n3;

    return 0;
}