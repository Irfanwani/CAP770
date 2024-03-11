#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data): data(data), next(nullptr) {};
};

class Queue {
    Node *head;
    Node *tail;

    public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(int data) {
        Node *newNode = new Node(data);
        if(newNode == nullptr) {
            cout << "Overflow" << endl;
            return;
        }

        if(this->isempty()) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;

    };

    void dequeue() {
        Node *temp = head;
        head = head->next;

        delete temp;
    };

    bool isempty() {
        return head == nullptr;
    };

    void display() {
        Node *current = head;

        while(current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }; 

};

int main() {
    Queue q;
    for(int i = 1; i <= 10; i++) {
        q.enqueue(i*i);
        q.display();
    }

    cout << "Dequeuing process: " << endl;

    for(int i = 1; i <= 4; i++) {
        q.dequeue();
        q.display();

    }
    return 0;
}