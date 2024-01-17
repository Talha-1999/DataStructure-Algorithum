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

struct Node * deleteFirst(struct Node*head){
    struct Node * ptr=head; // new node point to head
    head=head->next; // head equal ho jay ga head k next k
    free(ptr); // head ko hum delete kr dyn gy

    return head;
}

struct Node * deleteAtBetween(struct Node * head,int index){
    struct Node * p = head;
    struct Node * q = head->next;

    for(int i = 1; i < index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;

}

struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;

}

struct Node * deleteFromValue(struct Node * head,int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next != NULL){
        p=p->next;
        q=q->next;
    }

    if(q->data == value){
        p->next=q->next;
        free(q);
    }
    return head;


}


int main()
{
    // Allocate memory for nodes in the linked list in Heap;
     Node *head=new Node;
     Node *second=new Node;
     Node *third=new Node;


    // Link first with second nodes
    head->data=1;
    head->next=second;

    // Link second with third nodes
    second->data=2;
    second->next=third;

    // Link third with NULL nodes
    third->data=3;
    third->next=NULL;

    cout<<"Linked List Before Insertion :"<<endl;
    linkedListTraversal(head);

    // head=deleteFirst(head); // delete first node in linked list
    // head=deleteAtBetween(head,3);// delete any node but first not 
    // head=deleteAtEnd(head); // delete the last node
    head=deleteFromValue(head,3); // delete the node from value but first not

    cout<<"Linked List After Insertion :"<<endl;
    linkedListTraversal(head);
    
    
    return 0;
}