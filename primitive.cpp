#include <iostream>
#include <cstdlib>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
        }
};
class CircularLinkedList {
private:
    Node* last; 
public:
    CircularLinkedList() {
        last = nullptr;
    }
    void clear();
    ~CircularLinkedList() {
        clear();
    }
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);       
        if (last == nullptr) {
            last = newNode;
            newNode->next = newNode; 
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << "Inserted " << x << " at the beginning" << endl;
    }
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);   
        if (last == nullptr) {
            last = newNode;
            newNode->next = newNode; 
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode; 
        }
        cout << "Inserted " << x << " at the end" << endl;
    }
    void insertAfterKey(int key, int x) {
        if (last == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = last->next; 
        do {
            if (temp->data == key) {
                Node* newNode = new Node(x);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == last) {
                    last = newNode;
                }
                cout << "Inserted " << x << " after " << key << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Key " << key << " not found in the list" << endl;
    }
    void deleteNodeatbeg() {
        if (last == nullptr) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        Node* first = last->next; 
        int deletedValue = first->data;
        if (first == last) {
            delete first;
            last = nullptr;
        } else {
            last->next = first->next; 
            delete first;
        }
        
        cout << "Deleted " << deletedValue << " from the beginning" << endl;
    }
    void deletenodeatend(){
        if(last==nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=last->next;
        if(temp==last)
        {
            delete last;
            last=nullptr;
            return;
        }
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        temp->next=last->next;
        delete last;
        last=temp;
        cout<<"Deleted node from end"<<endl;
    }
    void deletenodebykey(int key){
        if(last==nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp=last->next,*prev=last;
        do{
            if(temp==key)
            {
                if(temp==last->next)
                {
                    last->next=temp->next;
                    if(temp==last)
                    {
                        last=nullptr;
                    }
                }
                else if(temp==last)
                {
                    prev->next=last->next;
                    last=prev;
                }
                else
                {
                    prev->next=temp->next;
                    delete temp;
                    cout << "Deleted node with key " << key << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            } while (temp != last->next);
            cout << "Key " << key << " not found in the list" << endl;
        }
    }
    void traverse() {
        if (last == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = last->next; 
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};
