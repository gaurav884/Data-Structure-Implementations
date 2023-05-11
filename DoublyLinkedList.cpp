#include <iostream>

using namespace std;

class Node{
   public:
    int val;
    Node* next;
    Node* prev;

   
    Node(int node_val){
         val = node_val;
         next = NULL;
         prev = NULL;
    }

};

class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList(int head_val){
        head = new Node(head_val);
    }

    void insert(int node_val){

        if(head == NULL){
            head = new Node(node_val);
        }
        else{
            Node* curr = head;

            while(curr->next != NULL){
                curr = curr->next;
            }
            
            Node* newnode = new Node(node_val);
            curr->next = newnode;
            newnode->prev = curr;

        }
    }

    void removeBack(){
        
        if(head == NULL){
            cout<<"Linked List is Empty"<<endl;
        }
        else if(head->next ==NULL){
            head = NULL;
        }
        else{
            Node* curr = head;

            while(curr->next->next != NULL){
                curr = curr->next;
            }

            curr->next = NULL;
 
        }

    }

    void removeFront(){
        
        if(head == NULL){
            cout<<"Linked List is Empty"<<endl;
            return;
        }
        else{
           
           Node* temp = head;
           head = head->next;
           if(head) head->prev = NULL;
           temp=NULL;
 
        }

    }

    void printList(){

        if(head == NULL){
            cout<<"Linked List is empty";
        }
        else{     
            Node* curr = head;      
            while(curr != NULL){

                cout<<curr->val<<" ";
                curr = curr->next;
            }
            cout<<endl;
        }
    }
    
    int size(){

        if(head == NULL){
            return 0;
        }
        else{
            int count = 0;
            Node* curr = head;

            while(curr != NULL){
                count++;
                curr = curr->next;
            }

            return count;

        }
    }
};

int main(){

      DoublyLinkedList* a = new DoublyLinkedList(4);

      a->insert(5);
      a->insert(7);
      a->insert(9);
      a->insert(10);
      a->removeFront();
      a->printList();
      cout<<a->size()<<endl;
      cout<<a->head->next->next->prev->val;


    return 0;
}