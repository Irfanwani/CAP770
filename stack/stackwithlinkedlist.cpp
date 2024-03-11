#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


class Stack {
private:
    Node* top; 

public:
    Stack() : top(nullptr) {}

    
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    
    int pop() {
        if (isEmpty()) {
            cerr << "Stack is empty. Cannot pop.\n";
            return -1; 
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    
    bool isEmpty() {
        return top == nullptr;
    }

    
    int peek() {
        if (isEmpty()) {
            cerr << "Stack is empty. Cannot peek.\n";
            return -1; 
        }
        return top->data;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); 

    cout << "Top element: " << stack.peek() << endl; 

    cout << "Popping: " << stack.pop() << endl; 
    cout << "Popping: " << stack.pop() << endl; 

    stack.display(); 

    return 0;
}
