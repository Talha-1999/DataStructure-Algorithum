// Peek means we get a value in array from Stack.

#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *arr; 
};

int stackTraversal(struct Stack*s){
    for(int i=s->top;i>=0;i--){
        cout<<"Elements : "<<s->arr[i]<<endl;
    }
    return 0;

}

int ArrayIsEmptyOrFull(struct Stack * ptr){
    if(ptr->top == -1){
        cout<<"The Stack is Empty..."<<endl;
    }else if(ptr->top == ptr->size-1){
        cout<<"The Stack is Full..."<<endl;
    }else{
        cout<<"The Stack is Not Empty..."<<endl;
    }
    return 0;
}

int peekSingleValue(struct Stack*ptr,int position){
    int arrayIndex=ptr->top-position+1;
    if(arrayIndex < 0){
        cout<<"Not a Valid Position.."<<endl;
        return 0;
    }else{
        return ptr->arr[arrayIndex];
    }
    return 0;
}

int peekMultipleValue(struct Stack*ptr,int positions){
// Elements : 4  top = 3 - i=1  = 3  ptr->arr[ptr->top-i+1]
// Elements : 3  top = 3 - i=2  = 2  ptr->arr[ptr->top-i+1]
// Elements : 2  top = 3 - i=3  = 1  ptr->arr[ptr->top-i+1]
// Elements : 1  top = 3 - i=4  = 0  ptr->arr[ptr->top-i+1]
    for(int i=1;i<=positions;i++){
        if(ptr->top-positions+1 < 0){
            cout<<"Not a Valid Position.."<<endl;
            return 0;
        }else{
            cout<<"PeekMultiple values from Stack : "<<ptr->arr[ptr->top-i+1]<<endl;
        }
    }
    return 0;
}

int topMostValue(struct Stack*ptr){
    if(ptr->top == -1){
        cout<<"Stack is Already Empty"<<endl;
        return -1;
    }else{
        cout<<"Top most value of Stack : "<<ptr->arr[ptr->top]<<endl;
        return 0;
    }
    return 0;
}

int bottomMostValue(struct Stack*ptr){
    if(ptr->top == -1){
        cout<<"Stack is Already Empty"<<endl;
        return -1;
    }else{
        cout<<"Bottom most value of Stack : "<<ptr->arr[0]<<endl;
        return 0;
    }
    return 0;
}

int main(){

   struct Stack *s=new Stack;
   
    s->size=10;
    s->top=-1; // -1 are used bcz array is empty;
    s->arr=new int[s->size];

    s->arr[0]=1;  // add value in stack looks like this. 
    s->top++;
    
    s->arr[1]=2;
    s->top++;

    s->arr[2]=3;
    s->top++;

    s->arr[3]=4;
    s->top++;
   

    // ArrayIsEmptyOrFull(s);     // check array is Empty or Full;

    // int checkValue=peekSingleValue(s,2); // find which position value from top to bottom.
    // if(checkValue){
    //     cout<<"PeekSingle Value From Stack : "<<checkValue<<endl;
    // }
    // peekMultipleValue(s,2); //how many values from top to bottom.

    topMostValue(s); // top most value of Stack
    bottomMostValue(s); // bottom most value of Stack

    stackTraversal(s); // check all values from array in Stack 




    return 0;

}