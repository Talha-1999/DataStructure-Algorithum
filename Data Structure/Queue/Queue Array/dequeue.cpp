#include<iostream>
using namespace std;

struct Queue{
    int size;
    int frontIndex;
    int backIndex;
    int * arr;
};

void QueueTraversal(struct Queue*queue){
    for(int i=queue->frontIndex+1;i<=queue->backIndex;i++){
        cout<<"Element : "<<queue->arr[i]<<endl;
    }
}

int isFull(struct Queue*queue){
    if(queue->backIndex==queue->size-1){
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

int dequeue(struct Queue*queue){
    int data=-1;
    if(isEmpty(queue)){
        cout<<"Queue is Already Empty  🚫"<<endl;
        return 0;
    }
    queue->frontIndex++;
    data=queue->arr[queue->frontIndex];
    cout<<"Queue Element is Deleted  🟢 "<<data<<endl;
    return data;
}

int main(){
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

    cout<<"Before Queue Traversal "<<endl;
    QueueTraversal(queue);

    dequeue(queue);
    dequeue(queue);


    cout<<"After Queue Traversal "<<endl;
    QueueTraversal(queue);
    return 0;
}