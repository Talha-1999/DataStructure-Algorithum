//  Structure:
//                                 +------+
//                                 |  1   |
//                                 +------+
//                                 |   3  |  
//                                 +------+
//                                 |   5  |
//                                 +------+

// Defination:
    // Stack is a Linear Data Structure.Operation on Stack are Perfomed LIFO (last in first out)
    // or FILO (first in last out) order. Stack is Looks like Bucket or Container.

// Implementation:
    // A Stack is a collection of elements with certain operations following LIFO dicipline.
    // Stack ko hum array sy bhi implement kr sakty hain or Linked List sy bhi.

//  Stack ADT:
    //  In order to create a stack we need a pointer to the topmost element
    //  along with other element which are stored inside the stack.

// Operations of Stckt ADT are:
    //  push() ->  push on element into the stack. O(1)
    //  pop()  ->  remove the topmost element from the stack. O(1)
    //  peek() ->  value at a given position returned. O(1)
    //  isEmpty() / isFull()  ->  Determine whether the stack is empty or full.


#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *arr; // pointer array. we use pointer * for dynamic location its mean 
    // array location are create in heap memory. if we not use pointer array location
    // are create in stack. 
};

int ArrayIsEmptyOrFull(struct Stack * ptr){
    if(ptr->top == -1){
        cout<<"The Stack is Empty...";
    }else if(ptr->top == ptr->size-1){
        cout<<"The Stack is Full...";
    }else{
        cout<<"The Stack is Not Empty...";
    }
    return 0;
}

int main(){
//  struct Stack s;
//  s.size=10;
//  s.top=-;

//  if we use struct Stack *s "*" are use for create pointer. We pass it from other functions
//  and we easily run callBy reference and we change structure.So we use struct Stack *s then
//  we use -> for change attributes. Forexample  s->size=10 , s->top=-1.

   struct Stack *s=new Stack;
   
    s->size=10;
    s->top=-1; // -1 are used bcz array is empty;
    s->arr=new int[s->size];

   

    // check array is Empty or Full;
    ArrayIsEmptyOrFull(s);

    return 0;

}