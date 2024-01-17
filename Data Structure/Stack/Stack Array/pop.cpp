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
        // cout<<"The Stack is Empty...";
        return 1;
    }else if(ptr->top == ptr->size-1){
        // cout<<"The Stack is Full..."<<endl;
        return 2;
    }else{
        // cout<<"The Stack is Not Empty...";
        return 3;
    }
    return 0;
}

int popSingle(struct Stack*ptr){
    int top=ptr->top;
    if(top == -1){
        return 0; // 0 means false 1 means true;
    }
    int response=ptr->arr[ptr->top];
    ptr->top=ptr->top-1;
    return response;
}


int popMultiple(struct Stack*ptr,int number){

    for(int i=number;i>0;i--){
        if(ArrayIsEmptyOrFull(ptr)>1){
            int deleted=ptr->arr[ptr->top];
            ptr->top=ptr->top-1;
            cout<<"PopMultiple Delete This Value from Stack : "<<deleted<<endl;
        }else{
            cout<<"The Stack is Empty at this number : "<<i<<endl;
         return 0;
        }
    }
    return 0;

}


int main(){

   struct Stack *s=new Stack;
   
    s->size=10;
    s->top=-1;
    s->arr=new int[s->size];

    s->arr[0]=1;  // add value in stack looks like this. 
    s->top++;
    
    s->arr[1]=2;
    s->top++;

    s->arr[2]=3;
    s->top++;

    s->arr[3]=4;
    s->top++;

    int check=ArrayIsEmptyOrFull(s); // check array is Empty or Full;
    
    if(check > 1){
    //    popMultiple(s,4); // Delete How many Values.

       int deleted= popSingle(s); // Delete Single Value from top bcz rule is LIFO or FILO.
       if(deleted){
       cout<<"PopSingle Delete Value from Stack : "<<deleted<<endl;
       }else{
       cout<<"PopSingle Stack is Already Empty... "<<endl;
       }

    }else{
     cout<<"Sorry Stack is Already Empty....."<<endl;
    }

    stackTraversal(s);

    return 0;

}