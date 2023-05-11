#include <iostream>
#include <queue>

using namespace std;


class Stack{
    public:
    queue<int>q1;
    queue<int>q2;

    Stack(){
        
    }

    void push(int value){

          q2.push(value);
          
          while(q1.size() > 0){
            q2.push(q1.front());
            q1.pop();
          }
          
          swap(q1 , q2);
        
    }

    void pop(){
         
         if(q1.size() == 0){
            cout<<"Alredy empty"<<endl;
         }
         else{
            q1.pop();
         }
    }

    int peek(){

         if(q1.size() == 0){
            cout<<"Empty"<<endl;
            return -1;
         }
         else{
            return q1.front();
         }
    }

    int size(){
        return q1.size();
    }
   
    int isEmpty(){
        
        return q1.size()==0 ? true : false;
    }

   
};

int main(){

    Stack* s = new Stack();

    s->push(1);
    s->push(13);
    s->push(91);
    s->push(2);
    s->pop();
    s->push(4);
   
    cout<<s->peek()<<endl;
    return 0;
}