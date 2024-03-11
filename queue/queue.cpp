#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity) : capacity(capacity), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }

    
    void enqueue(int val) {
        if (isFull()) {
            cerr << "Queue is full. Cannot enqueue.\n";
            return;
        }
        rear++;
        arr[rear] = val;
        size++;
    }

    
    int dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot dequeue.\n";
            return -1; 
    
        }
        int val = arr[front];
        front++;
        size--;
        return val;
    }

    
    bool isEmpty() {
        return size == 0;
    }

    
    bool isFull() {
        return size == capacity;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }

    
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display(); 
    cout << "Dequeue: " << queue.dequeue() << endl; 
    queue.display(); 

    return 0;
}
