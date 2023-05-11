#include <iostream>
#include <queue>

using namespace std;


class Stack{
    public:
    queue<int>q;

    Stack(){
        
    }

    void push(int value){
         
         int size = q.size();
         q.push(value); 
         for(int i= 0 ;i<size ;i++){
            q.push(q.front());
            q.pop();
         }
         
          
        
    }

    void pop(){
          
          if(q.size() == 0){
            cout<<"Empty"<<endl;
            return;
          }
          q.pop();
    }

    int peek(){

          if(q.size() == 0){
            cout<<"Empty"<<endl;
            return -1e9;
          }
          return q.front();
          
    }

    int size(){
        return q.size();
    }
   
    int isEmpty(){
        
        return q.size()==0 ? true : false;
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