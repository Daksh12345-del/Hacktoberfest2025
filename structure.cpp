#include <iostream>
using namespace std;
struct Node 
{
Node* head = nullptr;
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
int main(){
    Node* head = nullptr;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    traverse(head);
    return 0;
}
    void traverse(Node* head) { 
          Node* temp = head; 
          while (temp != nullptr) { 
                cout << temp->data << " "; 
                temp = temp->next; 
          } 
            cout << endl;
      }
      void insertatbegin(int value)
      {
        Node* newNode= new Node(value);
        {
            Node* head=nullptr;
            newNode->next=head;
            head=newNode;

        }
    }
        void insertAtEnd(int value) 
        {
            Node* newNode = new Node(value);
            Node* head=nullptr;
            if (head == nullptr) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }