    //        y     -----> Right Rotate      x
    //       / \                            / \    
    //      x   T3                         T1   y
    //     / \                                / \ 
    //   T1   T2     Left Rotate <-------   T2  T3

    //        9     -----> Right Rotate      4
    //       / \                            / \    
    //      4   10                         2   9
    //     / \                                / \ 
    //    2   6     Left Rotate <-------     6   10

#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    int height;
};

int max(int a,int b){
    return a>b ? a : b;
}

int getHeight(struct Node*root){ // get the height of the tree.
    if(root==NULL){
        return 0;
    }
    return root->height;
}

int getBalancedFactor(struct Node*root){ 
    if(root==NULL){
        return 0;
    }else{
        return getHeight(root->left) - getHeight(root->right);
    }
}

struct Node* rightRotate(struct Node*y){
    struct Node* x=y->left;
    struct Node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    return x;

}

struct Node* leftRotate(struct Node*x){
    struct Node* y=x->right;
    struct Node* T2=y->left;

    y->left=x;
    x->right=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    return y;
}

struct Node * createNode(int data){
    struct Node *n=new Node; // creating a node pointer and allocate memory in heap
    n->data=data; // setting the data
    n->left=NULL; // setting the left children is NULL
    n->right=NULL; // setting the right children is NULL
    n->height=1;
    return n;
}

struct Node* insert(struct Node*node,int value){
    if(node==NULL){
        return (createNode(value));
    }
    if(value<node->data){
        node->left=insert(node->left,value);
    }
    else if(value>node->data){
        node->right=insert(node->right,value);
    }
    node->height=1+ max(getHeight(node->left),getHeight(node->right));
    int bf=getBalancedFactor(node);
    
    // Left Left Case
    if(bf>1 && value < node->left->data){
        return rightRotate(node);
    }
    // Right Right Case
    if(bf<-1 && value > node->right->data){
       return leftRotate(node);
    }
    // Left Right Case
    if(bf>1 && value>node->left->data){
        node->left=leftRotate(node->left);
       return rightRotate(node);
    }
    // Right Left Case
    if(bf<-1 && value<node->right->data){
        node->right=rightRotate(node->right);
       return leftRotate(node);
    }
    return node;
}

void preOrderTraversal(struct Node*root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    } 
}

int main(){
    // Construct the node using function.
    struct Node *root=NULL; // it is a root node
    root=insert(root,11); 
    root=insert(root,9);
    root=insert(root,18);
    root=insert(root,5); 
    root=insert(root,4); 
    root=insert(root,10); 

    // This is a Left-Left Case :
   // Right rotate once with respect to first imbalanced node.
    
    //   bf 2        11           ----> Left left insertion      0   9
    //          L   / \                                            /  \ 
    //  bf 1       9  18  0                                   1   5   11 0
    //        L   / \                                            /   / \ 
    // bf 1      5   10                                      0  4   10 18  0
    //          /  
    //         4   
   // result : 11 9 5 4 10 18  ---> Left Left           9 5 4 11 10 18   this AVL tree.  

    preOrderTraversal(root);
    return 0;
}