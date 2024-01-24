#include<iostream>
using namespace std;
// Time Complexity O(n^2)  it is a worst case complexity  , best case Complexity is O(n)
// yes it is stable and it is by nature adaptive.

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void insertionSort(int arr[],int size){
    for(int i=1;i<=size-1;i++){
        int currentValue=arr[i];
        int backIndex=i-1;

        while(backIndex >= 0 && arr[backIndex] > currentValue){
        // cout<<"Cur : "<<currentValue<<" Back : "<<arr[backIndex]<<endl;
        arr[backIndex+1]=arr[backIndex];
        backIndex--;
        // printArray(arr,size);
        }
        arr[backIndex+1]=currentValue;
    }
}


int main(){
    int data[]={1,4,6,3,8,9,7};
    // int data[]={7,11,3,14,2,1,13,17,15,18,16,27};
    int arrayLength = sizeof(data) / sizeof(int);

    cout<<"UnSorted Array : ";
    printArray(data,arrayLength);
    
    insertionSort(data,arrayLength);
    
    cout<<"Sorted Array : ";
    printArray(data,arrayLength);

    return 0;
}