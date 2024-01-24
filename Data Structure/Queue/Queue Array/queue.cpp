// Structure :

                    //       Front
                    //        |
                    //      +------+    +------+    +------+    +------+
                    //      | Data | -> | Data | -> | Data | -> | Data |
                    //      +------+    +------+    +------+    +------+
                    //                                             |
                    //                                           Rear



// Defination :
    // A queue is a fundamental data structure in computer science that follows the
    // First In First Out (FIFO) principle. In a queue, elements are added to the
    // rear (enqueue operation) and removed from the front (dequeue operation).
    // The first element added is the first one to be removed.

// Operation of Queue ADT :

    //  Enqueue: Adds an element to the rear of the queue. O(1)
    //  Dequeue: Removes and returns the element from the front of the queue. O(1) using on programmer. but our depend O(1)
    //  Front: Returns the element at the front of the queue without removing it.
    //  Rear: Returns the element at the rear of the queue without removing it.
    //  IsEmpty: Checks if the queue is empty.
    //  Size: Returns the number of elements in the queue.

// Queue can be Implemented By:
        //    1:  Array.
        //    2:  Linked List.
        //    3:  Stack.


#include<iostream>
using namespace std;

struct Queue{
    int size;
    int frontIndex;
    int backIndex;
    int * arr;
};

void QueueTraversal(struct Queue*queue){
    for(int i=0;i<=queue->backIndex;i++){
        cout<<"Element : "<<queue->arr[i]<<endl;
    }
}

int main(){

// in this case Drawback of Queue using array is;
// hum data ko delete kr rahy hain lekin wo space empty hain but hum use ni kr sakty unhain.
// f=frontIndex
// b=backIndex
// e=EmptySpace but we not use.

// Empty Queue

//    we insert one number b++
//   we delete one number f++

//  f=-1
//  b=-1

//  -1   ---------------------------------
//      |   |    |    |    |    |    |   |                     
//      ---------------------------------

//      insert one number. b++

//  f=-1 , b=0
//       ---------------------------------
//      | b |    |    |    |    |    |   |                     
//      ---------------------------------

//      delete one number. f++

//  f=0 , b=0
//       ---------------------------------
//      | f |  b |    |    |    |    |   |                     
//      ---------------------------------

//       ----------------------------------------
//      | e  |  e  |  e  |  e  |  e  |  f  |  b |                     
//      ----------------------------------------

// ye cenario efficient nahi isi ko hal krny k liye circular queue kya h or wo efficient h. 

    struct Queue * queue=new Queue;

    queue->size=10;
    queue->frontIndex=-1; // increment when we delete
    queue->backIndex=-1; // increment when we insert
    queue->arr=new int[queue->size];

    queue->backIndex=0;
    queue->arr[0]=1;

    queue->backIndex=1;
    queue->arr[1]=2;

    queue->backIndex=2;
    queue->arr[2]=3;

    cout<<"Queue Traversal "<<endl;
    QueueTraversal(queue);

    return 0;
}