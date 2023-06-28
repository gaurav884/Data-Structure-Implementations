#include <iostream>

using namespace std;

class Node
{

private:
    int val;
    Node *next;
    friend class LinkedList;

    Node(int node_val)
    {
        val = node_val;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList(int head_val)
    {
        head = new Node(head_val);
    }

    void insert(int node_val)
    {

        if (head == NULL)
        {
            head = new Node(node_val);
        }
        else
        {
            Node *curr = head;

            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            curr->next = new Node(node_val);
        }
    }

    void removeBack()
    {

        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            Node *curr = head;

            while (curr->next->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = NULL;
        }
    }

    void removeFront()
    {

        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
            return;
        }
        else
        {

            Node *temp = head;
            head = head->next;
            temp = NULL;
        }
    }

    void printList()
    {

        if (head == NULL)
        {
            cout << "Linked List is empty";
        }
        else
        {
            Node *curr = head;
            while (curr != NULL)
            {

                cout << curr->val << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    int size()
    {

        if (head == NULL)
        {
            return 0;
        }
        else
        {
            int count = 0;
            Node *curr = head;

            while (curr != NULL)
            {
                count++;
                curr = curr->next;
            }

            return count;
        }
    }
};

int main()
{

    LinkedList *a = new LinkedList(4);

    a->insert(5);
    a->insert(7);
    a->insert(9);
    a->insert(10);
    a->removeFront();
    a->printList();
    cout << a->size();

    return 0;
}