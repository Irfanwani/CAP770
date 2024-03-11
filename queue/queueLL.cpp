#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    
    ~Queue() {
        
        while (!isEmpty()) {
            dequeue();
        }
    }

    
    bool isEmpty() {
        return front == nullptr;
    }

    
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue." << endl;
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued from queue." << endl;
        front = front->next;
        delete temp;
    }

    
    int getFront() {
        if (isEmpty()) {
            cerr << "Queue is empty." << endl;
            exit(EXIT_FAILURE);
        }
        return front->data;
    }
};

int main() {
    
    Queue queue;

    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    
    cout << "Front element: " << queue.getFront() << endl;

    
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    
    queue.dequeue();

    return 0;
}
