// this function are only tell me only the parenthisis matching.
// it does not tell me the validity of expression.
 
#include<iostream>
#include <string>

using namespace std;

struct Stack{
    int size;
    int top;
    string *arr;
};

int stackTraversal(struct Stack*s){
    for(int i=s->top;i>=0;i--){
        cout<<"Elements : "<<s->arr[i]<<endl;
    }
    return 0;

}

int isEmpty(struct Stack*stack){
    if(stack->top== -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack*stack){
    if(stack->top == stack->size-1){
        return 1;
    }
    return 0;
}

int pushOne(struct Stack*stack,char data){
    if(isFull(stack)){
        cout<<"You can not push Stack is Already Full... 🖐️"<<endl;
        return 0;
    }
    stack->top++;
    stack->arr[stack->top]=data;
    cout<<"🟢 Push Element in Stack "<<stack->arr[stack->top]<<endl;
    return 0;
}

int popOne(struct Stack*stack){
    if(isEmpty(stack)){
        cout<<"You can not Pop Stack is Already Empty... 🖐️"<<endl;
        return 0;
    }
    string del=stack->arr[stack->top];
    stack->top--;
    cout<<"❌ Pop Element in Stack :"<<del<<endl;
    return 0;
}

int main(){
    struct Stack * stack=new Stack;

    stack->size=10;
    stack->top=-1;
    stack->arr=new string[stack->size];

    // cout<<"Before Push Function"<<endl;
    // stackTraversal(stack);

    string data="a)*(9)";
    for(int index=0;index<data.length();index++){
        if(data[index] == '('){
            pushOne(stack,data[index]);
        }else if(data[index] == ')'){
            popOne(stack);

        }
    }

    if(isEmpty(stack)){
        cout<<"Parenthisis is Matching... 💯";
        return 1;
    }else{
        cout<<"Parenthisis is Not Matching... 🚫";
        return 0;
    }
    return 0;
}