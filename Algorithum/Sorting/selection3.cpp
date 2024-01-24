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

    for(int i=1;i<=size-1;i++){ // number of passes
        int backIndex=i-1; // previous value index

        for(int next=i;next<=size-1;next++){ // compare previous value for all other next values. if next value is smaller then previous value then swape it.
        //    cout<<"Previous : "<<arr[backIndex]<<" Front : "<<arr[next]<<endl;
            if(arr[next]<arr[backIndex]){
                int temp=arr[backIndex];
                arr[backIndex]=arr[next];
                arr[next]=temp;
            }
        }
       
    }
}
int main(){
    int data[]={7,11,3,14,2,1,3,17,15,18,16,27};
    int arrayLength = sizeof(data) / sizeof(int);

    cout<<"UnSorted Array : ";
    printArray(data,arrayLength);

    selectionSort(data,arrayLength);

    cout<<"Sorted Array : ";
    printArray(data,arrayLength);
    return 0;
}