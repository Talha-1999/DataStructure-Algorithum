#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node*head){
    while(head != NULL){
        cout<<"Number : "<<head->data<<endl;
        head=head->next;
    }
}

struct Node * insertAtFirst(struct Node * head,int data){
    Node * newNode=new Node; // create a new node
    newNode->next=head;
    newNode->data=data;
    return newNode;
}

struct Node * insertAtEnd(struct Node * head,int data){
    struct Node * newNode=new Node; // create a new node
    struct Node * myNode=head;

    while(myNode->next != NULL){
        myNode=myNode->next;
    }

    newNode->data=data;
    myNode->next=newNode;
    newNode->next=NULL;
    return head;
}

struct Node * insertAtBetween(struct Node*head,int data,int position){
    struct Node * newNode=new Node; // create a new node
    struct Node * myNode=head;
    int i=0;

    while(i != position-1){
        myNode=myNode->next;
        i++;
    };
    newNode->data=data;
    newNode->next=myNode->next;
    myNode->next=newNode;
    return head;
}

struct Node * insertAfterNode(struct Node * head,struct Node * prevNode,int data){
    struct Node * newNode=new Node; // create a new node
    newNode->data=data;

    newNode->next=prevNode->next;
    prevNode->next=newNode;

    return head;
}

int main()
{
    // Allocate memory for nodes in the linked list in Heap;
    struct Node *head=new Node;
    struct Node *second=new Node;
    struct Node *third=new Node;


    // Link first with second nodes
    head->data=2;
    head->next=second;

    // Link second with third nodes
    second->data=4;
    second->next=third;

    // Link third with NULL nodes
    third->data=5;
    third->next=NULL;

    cout<<"Linked List Before Insertion"<<endl;
    linkedListTraversal(head);
    
    // this function return a new head and then update with previous head
    //  head=insertAtFirst(head,1); // insert before head
    //  head=insertAtBetween(head,3,2);  // insert between anywhere
    //  head=insertAtEnd(head,6); // insert end of linked list
    head=insertAfterNode(head,second,6); // insert after any node
    cout<<"Linked List After Insertion"<<endl;
    linkedListTraversal(head);
    
    return 0;
}