#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node*head){
    while(head != NULL){
        cout<<"Number : "<<head->data<<endl;
        head=head->next;
    }
}

int isEmpty(struct Node* top){
    if(top==NULL){
        cout<<"Stack is Empty"<<endl;
        return 1;
    }
    return 0;
    
}

int isFull(struct Node* top){
    struct Node * p=new Node;
    if(p==NULL){
        return 1;
    }
    return 0;
}

struct Node *  insertAtFirst(struct Node * top,int data){
    struct Node * newNode=new Node; // create a new node
    if(isFull(top)){
        cout<<"Stack is Full"<<endl;
        return 0;
    }
    newNode->data=data;
    newNode->next=top;
    top=newNode;
    return top;
}

int pop(struct Node**top){ // we use ** bcz we also send top address.
    if(isEmpty(*top)){
        cout<<"Stack is UnderFlow"<<endl;
        return 0;
    }
    struct Node * p=*top; // create a new node
    *top=(*top)->next;
    int x = p->data;
    free(p);
    return x;
}


int main(){

    struct Node  * top=NULL;
    
    top=insertAtFirst(top,1); // insert before head
    top=insertAtFirst(top,2); // insert before head
    top=insertAtFirst(top,3); // insert before head

    linkedListTraversal(top);

    int element=pop(&top); // & are use to send top address bcz i want to change top otherwise he cannot chnage bcz return value store in element variable. 
    if(element){
        cout<<"Pop element is : "<<element<<endl;
    }

    linkedListTraversal(top);

    return 0;
}