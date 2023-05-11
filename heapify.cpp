#include <iostream>

using namespace std;


void heapify(int arr[] , int i , int size){
    
    int largest = arr[i];
    int left = 2*i;
    int right =2*i+1;

    if(left < size && arr[i] < arr[left]){
         swap(arr[i] , arr[left]); 
    }
    if(right < size && arr[i] < arr[right]){
         swap(arr[i] , arr[right]); 
    }

    if(arr[i]  != largest){                           //means swap occured and now check the heap further down below
        heapify(arr , largest, size);
    }
}


int main(){

    int arr[6] = {-1 , 54 ,53 ,55 , 52 ,50};
    int n= 5;
    
    for(int i=n/2 ; i>=1 ;i--){
        heapify(arr , i , n);
    }
    
    for(int i =1 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}