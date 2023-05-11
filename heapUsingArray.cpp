#include <iostream>

using namespace std;

class maxHeap{
    public:
    int arr[100];
    int size;

    maxHeap(){
        size = 0;
        arr[0] = -1;
    }
   
    void insert(int val){

        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){

            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void pop(){
          
          if(size ==0 ){
            cout<<"Empty"<<endl;
            return;
          }

          arr[1] = arr[size];
          size--;
          int index = 1;

          while(index < size){
              
              int temp = arr[index];
              int left = 2*index;
              int right = 2*index+1;

              if(left < size && arr[index] < arr[left]){
                 swap(arr[index] , arr[left]);
                 index = left;
              }

              if(right <size && arr[index] < arr[right]){
                  swap(arr[index] , arr[right]);
                  index = right;
              }

              if(arr[index] == temp){             // means it is greater than left and right and no need to change 
                    return;
              }
          }

    }

    int top(){

        if(size == 0){
            cout<<"Empty"<<endl;
            return -1e9;
        }
        
        else{
            return arr[1];
        }
        
    }

    void print(){

        if(size == 0){
            cout<<"Empty";
            return;
        }

        for(int i =1 ;i<=size ; i++){
            cout<<arr[i]<<" ";
        }
    }


};

int main(){

     maxHeap* h = new maxHeap();

     h->insert(2);
     h->insert(3);
     h->insert(4);
     h->insert(10);
     h->insert(34);
     cout<<h->top()<<endl;
     h->pop();
     cout<<h->top()<<endl;
     h->pop();
     cout<<h->top()<<endl;
      h->pop();
     cout<<h->top()<<endl;
      h->pop();
     cout<<h->top()<<endl;

    return 0;
}