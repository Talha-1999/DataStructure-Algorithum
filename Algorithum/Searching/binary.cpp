#include <iostream>
using namespace std;

// Binary Search Algorithum use When A Array is Sorted:
// Time Complexity is O(logn)
int* BinarySearch(int arr[],int size,int element){

    int* response = new int[2]; // create array in pointer for return 
    int low=0;
    int mid;
    int high=size-1;

    while(low<=high){
       mid=(low+high)/2; // create a mid point of an array
       if(arr[mid]==element){
         response[0]=arr[mid];
         response[1]=mid;
         return response;
        }else if(arr[mid] < element){
          low=mid+1;
        }else{
          high=mid-1;
        }
    }

    return 0;
}

int main()
{

    int myArray[]={1,2,3,4,5,6,7,8,9};
    int arraySize = sizeof(myArray) / sizeof(int);
    int element=4;
    int* findElement=BinarySearch(myArray,arraySize,element);

    cout<<"Binary Search Find Data : "<<findElement[0]<<" And Index is : "<<findElement[1]<<endl;

    return 0;
}