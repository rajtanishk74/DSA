#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int data) : data(data), next(nullptr) {}
};

// Class for Circular Linked List
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Function to delete a node
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head, *prev = nullptr;
        // If the node to be deleted is the only node
        if (temp->data == key && temp->next == head) {
            delete temp;
            head = nullptr;
            return;
        }
        // If head needs to be removed
        if (temp->data == key) {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
            return;
        }
        // Find the key to be deleted
        while (temp->next != head && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        // If node not found
        if (temp->data != key) {
            cout << "Node not found." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Main function
int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    cout << "Circular Linked List: ";
    cll.display();

    cout << "Deleting 20..." << endl;
    cll.deleteNode(20);
    cout << "Updated Circular Linked List: ";
    cll.display();

    cout << "Deleting 10..." << endl;
    cll.deleteNode(10);
    cout << "Updated Circular Linked List: ";
    cll.display();

    return 0;
}
