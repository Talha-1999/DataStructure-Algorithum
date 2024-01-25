#include<iostream>
using namespace std;


void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int findmaxNumber(int arr[],int size){
    int max=arr[0];

    for(int i=0;i<=size-1;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

void countSort(int arr[],int size){
    int maxNumber;
    maxNumber= findmaxNumber(arr,size);
    
    int countArr[maxNumber+1];
    int arrayLength = sizeof(countArr) / sizeof(int);

    for(int i=0;i<=maxNumber;i++){
        countArr[i]=0;
    }

    for(int i=0;i<=arrayLength-1;i++){
        countArr[arr[i]]=countArr[arr[i]]+1;
    }

    for(int i=0;i<=arrayLength-1;i++){
        cout<<countArr[i]<<endl;
    }
}


int main(){
    int data[]={1,4,6,3,8,9,7};
    // int data[]={7,11,3,14,2,1,13,17,15,18,16,27};
    int arrayLength = sizeof(data) / sizeof(int);

    cout<<"UnSorted Array : ";
    printArray(data,arrayLength);
    
    countSort(data,arrayLength);
    
    // cout<<"Sorted Array : ";
    // printArray(data,arrayLength);

    return 0;
}