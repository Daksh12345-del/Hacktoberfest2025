#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning" << endl;
    }
    
    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " as the first element" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at the end" << endl;
    }
    
    // Insert at a specific position (0-indexed)
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* temp = head;
        
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << endl;
    }
    
    // Delete a node with given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from the list" << endl;
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        
        if (current->next == nullptr) {
            cout << "Value " << value << " not found in the list" << endl;
            return;
        }
        
        Node* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
        cout << "Deleted " << value << " from the list" << endl;
    }
    
    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
    
    // Get the size of the linked list
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // Clear the entire list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // Check if list is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

// Menu-driven program
int main() {
    LinkedList ll;
    int choice, value, position;
    
    do {
        cout << "\n===== LINKED LIST OPERATIONS =====" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Search Element" << endl;
        cout << "6. Display List" << endl;
        cout << "7. Get Size" << endl;
        cout << "8. Check if Empty" << endl;
        cout << "9. Clear List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                ll.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                ll.insertAtEnd(value);
                break;
                
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                ll.insertAtPosition(value, position);
                break;
                
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                ll.deleteNode(value);
                break;
                
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (ll.search(value)) {
                    cout << "Element " << value << " found in the list" << endl;
                } else {
                    cout << "Element " << value << " not found in the list" << endl;
                }
                break;
                
            case 6:
                ll.display();
                break;
                
            case 7:
                cout << "Size of the list: " << ll.size() << endl;
                break;
                
            case 8:
                if (ll.isEmpty()) {
                    cout << "List is empty" << endl;
                } else {
                    cout << "List is not empty" << endl;
                }
                break;
                
            case 9:
                ll.clear();
                cout << "List cleared successfully" << endl;
                break;
                
            case 0:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        
    } while (choice != 0);
    
    return 0;
}