#include<iostream>
using namespace std;


void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[],int mid,int low,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int newArr[high+1];

    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            newArr[k]=arr[i];
            i++;k++;
        }else{
            newArr[k]=arr[j];
            k++;j++;
        }
    }
    while(i<= mid){ // copy all remaining element from main array to newArr i to mid
        newArr[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){ // copy all remaining element from main array to newArr j to high
        newArr[k]=arr[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=newArr[i];
    }

}

void MergetSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergetSort(arr,low,mid);
        MergetSort(arr,mid+1,high);
        merge(arr,mid,low,high);
        // cout<<"Low : "<<arr[low]<<" Mid : "<<arr[mid]<<" High : "<<arr[high]<<endl;
    }

}
int main(){
    int data[]={7,11,3,14,2,1,3,17,15,18,16,27};
    // int data[]={7,5,3,1,2,6,4};
    int arrayLength = sizeof(data) / sizeof(int);

    cout<<"UnSorted Array : ";
    printArray(data,arrayLength);

    MergetSort(data,0,arrayLength-1);

    cout<<"Sorted Array : ";
    printArray(data,arrayLength);
    return 0;
}