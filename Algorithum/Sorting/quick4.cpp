#include<iostream>
using namespace std;

// Time Complexity Best case O(nlogn) Average case O(nlogn) Worst case O(n^2)
// Quick sort is not Stable. bcz ye array k element ka order change kr deta ha.
// it is an Inplace Algorithum

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int partition(int arr[],int low,int high){
    int pivot=arr[low];  //  first element of array is pivot
    int i=low+1; //  find greater value from pivot and its run from right side of array
    int j=high;  //  find lower value from pivot and its run from left side of array
    int temp;

    do{
        while(arr[i] <= pivot){  //  ye chalta rahy ga jab tak koi pivot sy bhari value na mil jay 
            i++;
        }
        while(arr[j] > pivot){ // ye chalta rahy ga jab tak koi pivot sy choti value na mil jay
            j--;
        }
        if(i<j){ // agr i index bhara ha j index sy to ye ruk jay ga
            temp=arr[i];  
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);

    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;

    return j;
}


void quickSort(int arr[],int low,int high){
    int partitionIndex; // index of pivot after partiton

    if(low<high){
        partitionIndex=partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);   // sort left sub array
        quickSort(arr,partitionIndex+1,high);  // sort right sub array 
    }

}


int main(){
    //  int data[]={7,11,3,14,2,1,3,17,15,18,16,27};
    int data[]={7,5,3,1,2,6,4};
    int arrayLength = sizeof(data) / sizeof(int);

    cout<<"UnSorted Array : ";
    printArray(data,arrayLength);

    quickSort(data,0,arrayLength-1);

    cout<<"Sorted Array : ";
    printArray(data,arrayLength);

    return 0;
}