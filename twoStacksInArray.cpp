#include <iostream>
#include <vector>

using namespace std;


class TwoStack{
    public:
    int* temp;
    int top1;
    int top2;
    int capacity1;
    int capacity2;

    TwoStack(int max_size1 , int max_size2){

        temp = new int[max_size1 + max_size2];
        top1 = -1;
        top2 = max_size1 + max_size2;
        capacity1 = max_size1;
        capacity2 = max_size2;
    }

    void push1(int value){

          if(top1+1 == capacity1){
              cout<<"Capacity reached"<<endl;
              return;
          }
          top1++;
          temp[top1] = value;
        
    }

    void pop1(){
          if(top1 == -1){
            cout<<"Stack is empty";
          }
          else{
             top1--;
          }
    }

    int peek1(){
         if(top1 == -1){
            cout<<"Stack is empty";
            return -1;
          }
          else{
             return temp[top1];
          }
    }

    int size(){
        return top1+1;
    }


     void push2(int value){

          if(top2-1 == capacity1-1){
              cout<<"Capacity reached"<<endl;
              return;
          }
          top2--;
          temp[top2] = value;
        
    }

    void pop2(){
          if(top2 == capacity1+capacity2){
            cout<<"Stack2 is empty";
          }
          else{
             top2++;
          }
    }

    int peek2(){
         if(top2 == capacity1+capacity2){
            cout<<"Stack is empty";
            return -1;
          }
          else{
             return temp[top2];
          }
    }

    int size2(){
        return (capacity1+capacity2) - top2;
    }
   
   
    ~TwoStack(){
        delete []temp;
    }

};

int main(){

    TwoStack* s = new TwoStack(4,4);

    s->push2(1);
    s->push2(13);
    s->push2(91);
    s->push2(2);

    s->push1(1);
    s->push1(13);
    s->push1(91);
    s->push1(2);
    s->pop1();
    s->push1(4);
   
    cout<<s->size2()<<endl;
    return 0;
}