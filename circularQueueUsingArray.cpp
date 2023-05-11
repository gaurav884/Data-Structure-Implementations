#include <iostream>

using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *temp;
    int currSize;
    int capacity;

    Queue(int val)
    {
        front = -1;
        rear = -1;
        temp = new int[val];
        capacity = val;
        currSize = 0;
    }

    void push(int val)
    {

        if (currSize == capacity)
        {
            cout << "Full" << endl;
            return;
        }
        if (rear == -1)
        {

            rear = 0;
            front = 0;
        }
        else
        {

            rear = (rear + 1) % capacity;
        }

        temp[rear] = val;
        currSize++;
    }

    void pop()
    {

        if (front == -1)
        {
            cout << "queue is empty";
        }
        if (currSize == 1)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }

        currSize--;
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Empty Queue" << endl;
            return -1e9;
        }
        else
        {
            return temp[front];
        }
    }

    int size()
    {
        return currSize;
    }
};

int main()
{

    Queue *q = new Queue(5);

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