#include <iostream>
using namespace std;

// Time Complexity is O(n)
int LineraSearch(int arr[],int size,int element){
    for(int index=0;index<size;index++){
        if(arr[index]==element){
            return arr[index];
        }
    }
    return -1;
}

int main()
{

    int myArray[]={1,2,4,3,6,9,7,8};
    int arraySize = sizeof(myArray) / sizeof(int);
    int element=8;
    int findElement=LineraSearch(myArray,arraySize,element);

    cout<<"Linear Search Find Data : "<<findElement<<endl;
    return 0;
}