// Advantage
// ye fast insert and delete krta iska koi fix size nahi hota
// lekin array jb hum declare krty hain to uska size dena hota ha or agr kuch add krna ho
// kisi position pa to humy agy wala data agy krna parta ha or jb delete krna ho
// to delete krny k bd array ko update krna hota h ku k delete k bd wo jaga empty hoti h.


// Disadvantage
// ye item find late krta h ku k agr humy list k end pa jana ho to start sy ana parta ha
// lekin array ma agr humy kisi position pa jana ho to direct ja sakty hain.
// Or agr hum 50 number add krty hain to humy sath 50 pointers bhi add krny party hain un k
// connections k liye lekin agr array ma 50 number add krny ho to sirf 50 number add krty hain.

//  +------+    +------+    +------+
//  |   1  | -> |   2  | -> |   3  | -> NULL
//  +------+    +------+    +------+



#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node*ptr){
    while(ptr != NULL){
        cout<<"Number : "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    // Allocate memory for nodes in the linked list in Heap;
    struct Node *head=new Node;
    struct Node *second=new Node;
    struct Node *third=new Node;


    // Link first with second nodes
    head->data=7;
    head->next=second;

    // Link second with third nodes
    second->data=9;
    second->next=third;

    // Link third with NULL nodes
    third->data=8;
    third->next=NULL;

    linkedListTraversal(head);
 
    return 0;
}