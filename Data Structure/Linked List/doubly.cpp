// Doubly Linked List:
// Is Linked List ma 1 node point krraha ha 2 node ko to 2 bhi 1 ko point kr raha ha.

//              head                      end or tail
//            +------+     +------+     +------+
//   NULL <-  |   1  | <-> |   2  | <-> |   3  | -> NULL
//            +------+     +------+     +------+


#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

struct Node*  linkedListTraversal(struct Node*head){
    struct Node* current = head;
    // Traverse the list from the beginning to the end
    while (current != NULL) {
        cout <<"Forward traversal :"<<current->data <<endl;
        current = current->next;
    }
    // Traverse the list from the end to the beginning
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Traverse backward and print the elements
    while (current != NULL) {
        cout <<"Backward traversal : "<< current->data <<endl;
        current = current->prev;
    }
    return 0;
}

struct Node * insertAtFirst(struct Node * head,int data){
    struct Node* newNode=new Node;
    struct Node* myNodes=head;
    newNode->data=data;

    myNodes->prev=newNode;
    newNode->next=myNodes;
    newNode->prev=NULL;
    
    return newNode;
}

struct Node * insertAtEnd(struct Node * head,int data){
    struct Node* newNode=new Node;
    struct Node* myNodes=head;
    int i=0;

    while(myNodes->next !=NULL){
        myNodes=myNodes->next;
        i++;
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=myNodes;
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
    head->data=1;
    head->next=second;
    head->prev=NULL;

    // Link second with third nodes
    second->data=2;
    second->next=third;
    second->prev=head;

    // Link third with NULL nodes
    third->data=3;
    third->next=fourth;
    third->prev=second;

    fourth->data=4;
    fourth->next=NULL;
    fourth->prev=third;

    cout<<"Doubly Linked List Before Insertion"<<endl;
    linkedListTraversal(head);

    head=insertAtFirst(head,11);
    //  head=insertAtEnd(head,5); // insert end of linked list

    cout<<"Doubly Linked List After Insertion"<<endl;
    linkedListTraversal(head);
 
    return 0;
}