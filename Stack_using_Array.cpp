#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;  // Pointer to dynamic array
    int size;  // Size of the stack
    int top;   // Index of the top element

public:
    // Constructor
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Push function
    void push(int value) {
        if (top == size - 1) {  // Correct condition for overflow
            cout << "Stack overflow!\n";
            return;
        } else {
            top++;
            arr[top] = value;
            cout << "Pushed " << value << " into the stack\n";
        }
    }

    // Pop function
    void pop() {
        if (top == -1) {  // Correct condition for underflow
            cout << "Stack underflow!\n";
        } else {
            cout << "Popped " << arr[top] << " from the stack\n";
            top--;
        }
    }

    // Peek function
    int peek() {
        if (top == -1) {
            cout << "Stack underflow!\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    // IsEmpty function
    bool isEmpty() {
        return top == -1;
    }

    // Size function
    int getSize() {
        return top + 1;
    }
};

int main() {
    Stack s(5);  // Create a stack with size 5

    // Perform stack operations
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);

    cout << "Top element: " << s.peek() << endl;

    s.push(10);  // This will trigger an overflow

    s.pop();
    s.pop();

    cout << "Current stack size: " << s.getSize() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
