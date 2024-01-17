//  Circular linked list ma last ka node NULL nahi hota or last Node head sy Connect
//  hota ha.

      // head                    end ya phir tail
//    +------+    +------+    +------+
//    |  1   | -> |  2   | -> |   3  |
//    +------+    +------+    +------+
//      ^^                       |
//      |_______________________|



#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node*head){
    struct Node* ptr=head;
   do{
        cout<<"Number : "<<ptr->data<<endl;
        ptr=ptr->next;
    }while(ptr != head);
}

struct Node* insertAtFirst(struct Node * head,int data){
    struct Node * newNode=new Node;
    struct Node * allNodes=head->next;
    newNode->data=data;

    while(allNodes->next != head){
        allNodes=allNodes->next;
    }
    allNodes->next=newNode;
    newNode->next=head;
    head=newNode;
    return head;
}

struct Node * insertAtEnd(struct Node* head,int data){
    struct Node * newNode=new Node;
    struct Node* allNodes=head->next;
    newNode->data=data;


    while(allNodes->next != head){
        allNodes=allNodes->next;
    }
    allNodes->next=newNode;
    newNode->next=head;
    return head;
}

struct Node * insertAtBetween(struct Node*head,int data,int position){
    struct Node* newNode=new Node;
    struct Node* myNodes=head;
    int i=1;

    while (i!=position-1){
        myNodes=myNodes->next;
        i++;
    }
    newNode->data=data;
    newNode->next=myNodes->next;
    myNodes->next=newNode;
    return head;
}

int main()
{
    // Allocate memory for nodes in the linked list in Heap;
     Node *head=new Node;
     Node *second=new Node;
     Node *third=new Node;
     Node *fourth=new Node;


    // Link first with second nodes
    head->data=4;
    head->next=second;

    // Link second with third nodes
    second->data=3;
    second->next=third;

    // Link third with NULL nodes
    third->data=2;
    third->next=fourth;

    fourth->data=1;
    fourth->next=head;


    cout<<"Circular Linked List Before Insertion"<<endl;
    linkedListTraversal(head);

    // head=insertAtFirst(head,5);
    // head=insertAtEnd(head,-1);
    head=insertAtBetween(head,14,2); // insert between but start and end not. 

    cout<<"Circular Linked List After Insertion"<<endl;
    linkedListTraversal(head);

 
    return 0;
}