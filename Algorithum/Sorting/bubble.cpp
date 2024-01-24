#include<iostream>
using namespace std;

int* bubbleSortedArray(int arr[],int size){
    int count=1;
    bool isSorted=false; // it is use for adaptive algorithum if we not use then its not adaptive.

    while(count != size){ //  while loop run arraylength times.  number of passes
        // cout<<"Working on Passes : "<<count<<endl;
        isSorted=true;
        for(int index=0;index<size-count;index++){  // comparison in each passes
            if(arr[index]>arr[index+1]){
                int temp=arr[index];
                arr[index]=arr[index+1];
                arr[index+1]=temp;
                isSorted=false;
            }
        }    
        if(isSorted){
            return arr;
        }
        count++;
    }
    return arr;
}

int main(){
    
    int data[]={12,7,11,3,14,2,1,13,17,15,18,16,27};
    // int data[]={1,2,3,4,5,6};
    int arrayLength = sizeof(data) / sizeof(int);
   
    int* updated=bubbleSortedArray(data,arrayLength);

    for(int i=0;i<arrayLength;i++){
        cout<<updated[i]<<" ";
    }

    return 0;
}