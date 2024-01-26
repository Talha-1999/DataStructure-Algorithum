#include<iostream>
using namespace std;

// it is fast.
// Time Complexity is O(n) linear time ma sorting mil rahi ha. but at the cost of extra space.
// count algorithum extra space leta ha or ye axhi bat nahi ha.

//  __0___1____2_____3______4________5____   main Array
// |_10_|_7_|__5__|___2___|__3____|___1__|

// Step No 1: count array
//  __0___1____2_____3______4________5_____6____7_____8_____9_____10__   count array initialze to 0. length = max num of main array.
// |_0_|_0_|__0__|___0___|__0____|___0__|__0__|_0__|__0__|__0__|__0__|

// Step Not 2: count array
// main array ma index ma jo value ha us value k index ma count array ma 1 increment kr do

//  __0___1____2_____3______4________5_____6____7_____8_____9_____10__ 
// |_0_|_1_|__1__|___1___|__0____|___1__|__0__|_1__|__0__|__0__|__1__|

// Step Not 3:
// agar jis index ma value 0 ha to ap agy move kr jao. agr koi value ha to is ko decrement kro 
// or us k index ko is ma dal do. 

//  __0___1____2_____3______4________5____   ----->  Sorted Array
// |_1_|_2_|__3__|___5___|__7____|___10__|

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
    int i,j;
    // find max number in the main array
    maxNumber= findmaxNumber(arr,size);
    
    // create count array
    int countArr[maxNumber+1];
    int arrayLength = sizeof(countArr) / sizeof(int);

    // Initialize the array element to 0
    for(i=0;i<maxNumber+1;i++){
        countArr[i]=0;
    }

    // Increment the corresponding index in the countArr
    for(i=0;i< size;i++){
        countArr[arr[i]]=countArr[arr[i]]+1;
    }
    i=0; // counter for countArr 
    j=0; // counter for main array
    while(i<=maxNumber){
        if(countArr[i]>0){
            arr[j]=i;
            countArr[i]=countArr[i]-1;
            j++;
        }else{
            i++;
        }
    }
}


int main(){
    // int data[]={1,4,6,3,5,8,9,7};
    int data[]={7,11,3,14,2,1,13,17,15,18,16,27};
    int arrayLength = sizeof(data) / sizeof(int);

    cout<<"UnSorted Array : ";
    printArray(data,arrayLength);
    
    countSort(data,arrayLength);
    
    cout<<"Sorted Array : ";
    printArray(data,arrayLength);

    return 0;
}