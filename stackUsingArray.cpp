#include <iostream>
#include <vector>

using namespace std;


class Stack{
    public:
    int* temp;
    int top;
    int capacity;

    Stack(int max_size){
        temp = new int[max_size];
        top = -1;
        capacity = max_size;
    }

    void push(int value){

          if(top+1 == capacity){
              cout<<"Capacity reached"<<endl;
              return;
          }
          top++;
          temp[top] = value;
        
    }

    void pop(){
          if(top == -1){
            cout<<"Stack is empty";
          }
          else{
             top--;
          }
    }

    int peek(){
         if(top == -1){
            cout<<"Stack is empty";
            return -1;
          }
          else{
             return temp[top];
          }
    }

    int size(){
        return top+1;
    }
   
    int isEmpty(){
        
        return top==-1 ? true : false;
    }

    ~Stack(){
        delete []temp;
    }

};

int main(){

    Stack* s = new Stack(4);

    s->push(1);
    s->push(13);
    s->push(91);
    s->push(2);
    s->pop();
    s->push(4);
   
    cout<<s->peek()<<endl;
    return 0;
}