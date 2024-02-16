#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
    }
};

class LinkedList {
    Node* head;

    public:
    LinkedList() {
        head = nullptr;
    }
    void append(int data) {
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            return;
        };

        Node* current = head;
        while(current->next) {
            current = current->next;
        }

        current->next = newNode;
    };

    void insert(int data, int index) {
        Node* newNode = new Node(data);

        int i = 0;
        Node* current = head;
        if(index == 0) {
            head = newNode;
            head->next = current;
            return;
        }

        while(current) {
            if(i == index - 1) {
                Node* next = current->next;
                current->next = newNode;
                newNode->next = next;
                break;
            }

            current = current->next;
            i++;
        }

    };

    void display() {
        Node* current = head;
        while(current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    };

    void remove() {};
};

int main() {
    LinkedList linkedlist;
    int num, data;
    cout << "Enter the number of elements: "<< endl;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cout << "Enter data: ";
        cin >> data;
        linkedlist.append(data);
    }
    linkedlist.insert(300, 0);
    linkedlist.insert(3400, 3);
    linkedlist.display();
    return 0;
}