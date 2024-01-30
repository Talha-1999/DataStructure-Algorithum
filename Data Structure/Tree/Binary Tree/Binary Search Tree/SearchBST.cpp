#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * searchBST(struct Node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data== key){
        return root;
    }else if(root->data>key){
        return searchBST(root->left,key);
    }else{
        return searchBST(root->right,key);
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
    struct Node *n2=createNode(2); // it is a left node of root
    struct Node *n3=createNode(8); // it is a right node of root
    struct Node *n4=createNode(1); 
    struct Node *n5=createNode(3); 


    // Linking the node with left and right children.
    n->left=n2;
    n->right=n3;

    n2->left=n4;
    n2->right=n5;


    struct Node * foundData=searchBST(n,3);
    if(foundData != NULL){
        cout<<"Element Found : "<<foundData->data<<endl;
    }else{
        cout<<"Element Not Found "<<endl;
    }

    return 0;
}