#include<iostream>
using namespace std;

struct Queue{
    int size;
    int frontIndex;
    int backIndex;
    int * arr;
};

int QueueTraversal(struct Queue*q){
    // cout<<queue->frontIndex<<" "<<queue->backIndex<<endl;
    int end=q->backIndex;
    int i=0;
    while(i<end){
        cout<<"Element : "<<q->arr[i]<<endl;
        i++;
    }
    // for(int i=0;i<end;i++){
    //     cout<<"Element : "<<q->arr[i]<<endl;
    // }
    return 0;
}

int isFull(struct Queue*queue){
    if((queue->backIndex+1)%queue->size==queue->frontIndex){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue*queue){
    if(queue->frontIndex==queue->backIndex){
        return 1;
    }
    return 0;
}

// int i=(i+1)%arraysize; circular linear formula:

// bcz:
// 0=1
// 1=2
// 2=3
// then if 3==arraySize it is equal to 0;

void enqueue(struct Queue*queue,int data){
    if(isFull(queue)){
        cout<<"Queue is Already Full  🚫"<<endl;
    }else{
        queue->backIndex=(queue->backIndex+1)%queue->size;
        queue->arr[queue->backIndex]=data;
        cout<<"Queue is Inserted  🟢 "<<queue->arr[queue->backIndex]<<" "<<queue->backIndex<<endl;
    }
}

int dequeue(struct Queue*queue){
    int data=-1;
    if(isEmpty(queue)){
        cout<<"Queue is Already Empty  🚫"<<endl;
        return 0;
    }else{
        queue->frontIndex =(queue->frontIndex+1)%queue->size;
        data=queue->arr[queue->frontIndex];
        cout<<"Queue Element is Deleted  🟢 "<<data  <<" "<<queue->frontIndex<<endl;
        return data;
    }
}

int main(){
    struct Queue * queue=new Queue;

    queue->size=4;
    queue->frontIndex=0; // increment when we delete
    queue->backIndex=0; // increment when we insert
    queue->arr=new int[queue->size];

    cout<<"Before Queue Traversal "<<endl;
    QueueTraversal(queue);

    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);

    cout<<"After Queue Traversal "<<endl;
    QueueTraversal(queue);

    return 0;
}