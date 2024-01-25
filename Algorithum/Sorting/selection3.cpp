#include<iostream>
using namespace std;

// Time Complexity O(n^2)
// it is not stable . its not adaptive.

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[],int size){

    for(int i=0;i < size-1;i++){ // arrayLength - 1 times number of passes
        int indexOfMin=i; // min value index

        for(int next=i+1 ; next < size ;next++){ // compare previous value for all other next values. if next value is smaller then previous value then swape it.
        //    cout<<"Previous : "<<arr[indexOfMin]<<" Front : "<<arr[next]<<endl;
            if(arr[next]<arr[indexOfMin]){
                indexOfMin=next;
            }
        }
        int temp=arr[i];
        arr[i]=arr[indexOfMin];
        arr[indexOfMin]=temp;
       
    }
}
int main(){
    int data[]={7,11,3,14,2,1,3,17,15,18,16,27};
    // int data[]={7,5,3,1,2,6,4};
    int arrayLength = sizeof(data) / sizeof(int);

    cout<<"UnSorted Array : ";
    printArray(data,arrayLength);

    selectionSort(data,arrayLength);

    cout<<"Sorted Array : ";
    printArray(data,arrayLength);
    return 0;
}