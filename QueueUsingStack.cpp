#include <iostream>
#include<stack>

using namespace std;

class Queue
{
public:
    stack<int>s1;
    stack<int>s2;

    Queue()
    {
        
    }

    void push(int val)
    {
         s1.push(val);
      
    }

    void pop()
    {     
        if(s1.size() == 0 && s2.size() ==0){
            cout<<"Empty";
        }
        else{

            if(s2.size() == 0){

                while(s1.size() >0){
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            s2.pop();
        }
        
    }

    int peek()
    {
        if(s1.size() == 0 && s2.size() ==0){
            cout<<"Empty";
        }
        else{

            if(s2.size() == 0){

                while(s1.size() >0){
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            return s2.top();
        }
    }

    int size()
    {
        return s1.size()+s2.size();
    }
};

int main()
{

    Queue *q = new Queue();

    q->push(4);
    q->push(44);
    q->push(45);
    q->push(345);
    q->push(455);
    q->pop();
    q->pop();
    q->pop();
    q->push(34);
    q->push(544);
    q->pop();
    q->pop();
    cout << q->peek() << endl;

    return 0;
}