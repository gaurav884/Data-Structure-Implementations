#include <iostream>

using namespace std;

class Queue{
    public:

    int front;
    int rear ;
    int *temp;
    int capacity;

    Queue(int val){
         front, rear = -1;
         temp = new int[val];
         capacity= val;
    }
     
    void push(int val){

        if(rear == -1 && front == -1){
            rear , front = 1;
            temp[front]= val;
        }
        else if(rear == capacity){
             cout<<"Full"<<endl;
        }
        else{
            rear++;
            temp[rear] = val;
        }
    }

    void pop(){

        if(rear == -1 && front == -1){
            cout<<"queue is empty";
        }
        else if(rear == front){
            cout<<"queue is empty"<<endl;
            rear , front = -1;
        }
        else{
            front++;
        }
    }

    int peek(){

        if(rear == front){
            return -1e9;
        }
        else{
            return temp[front];
        }
    }



};

int main(){
    
    Queue *q = new Queue(5);

    cout<<q->peek()<<endl;
    q->push(4);
    q->push(14);
    q->push(44);
    q->push(54);
    cout<<q->peek()<<endl;
    q->push(94);

    return 0;
}