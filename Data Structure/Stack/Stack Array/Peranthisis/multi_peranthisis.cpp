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

int isMatch(char close,struct Stack*stack){
    string top = stack->arr[stack->top];
    if(top[0] == '{'&& close=='}' || top[0] == '(' && close==')' || top[0] == '[' && close==']'){
        return 1;
    }
    return 0;
}

int popOne(struct Stack*stack,char close){
    if(isEmpty(stack)){
        cout<<"You can not Pop Stack is Already Empty... 🖐️"<<endl;
        return 0;
    }
    if(!isMatch(close,stack)){
        cout<<"Parenthisis is Not Matching... 🚫";
        return 0;
    }
    string top = stack->arr[stack->top];
    stack->top--;
    cout<<"❌ Pop Element in Stack :"<<top<<endl;
    return 1;
}

int main(){
    struct Stack * stack=new Stack;

    stack->size=10;
    stack->top=-1;
    stack->arr=new string[stack->size];

    // cout<<"Before Push Function"<<endl;
    // stackTraversal(stack);

    string data="[1+3+{5+9}]";
    // string data="((8)[*--&&9])";
    // string data="([7-9}-7)";

    for(int index=0;index<data.length();index++){
        if(data[index] == '[' || data[index] == '(' || data[index] == '{'){    
            pushOne(stack,data[index]);
        }else if(data[index] == ']' || data[index] == ')' || data[index] == '}'){
            int respo=popOne(stack,data[index]);
            if(!respo){
                return 0;
            }
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