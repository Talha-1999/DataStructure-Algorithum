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
        return 2;
    }else{
        // cout<<"The Stack is Not Empty...";
        return 3;
    }
    return 0;
}

int pushSingle(struct Stack*ptr,int value){
    if(ArrayIsEmptyOrFull(ptr)!=2){ // check if stack is not full then insert.
        ptr->top++;
        ptr->arr[ptr->top]=value;
        cout<<"Insert Value in Stack : "<<value<<endl;
    }else{
        cout<<"Function PushSingle Sorry The Stack is Full.."<<endl;
    }
    return 0;
}


int pushMultiple(struct Stack*ptr,int arrValue[],int size){
    for(int i=0;i<size;i++){
        if(ArrayIsEmptyOrFull(ptr)!=2){ // check if stack is not full then insert.
          ptr->top++;
          ptr->arr[ptr->top]=arrValue[i];
          cout<<"Insert Value in Stack : "<<arrValue[i]<<endl;
        }else{
            cout<<"Function PushMultiple Sorry The Stack is Full on Value : "<<arrValue[i-1]<<endl;
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
    
    int check=ArrayIsEmptyOrFull(s); // check array is Empty or Full;
    
    if(check != 2){
        // add multiple value in Stack :
        int multipleData[]={4,5,6,7,8,9,10,11};
        int arraySize = sizeof(multipleData) / sizeof(int);
        pushMultiple(s,multipleData,arraySize);

        // add one value in Stack :
        pushSingle(s,11);
    }else{
        cout<<"The Stack is Full..."<<endl;
    }

    stackTraversal(s);

    return 0;

}