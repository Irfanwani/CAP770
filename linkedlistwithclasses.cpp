#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
    }
    ~Node() {
        free(next);
    }
};

class LinkedList {
    Node* head;

    public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        free(head);
    }

    // add item at end
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

    // insert item at any position
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

    // to display the data of the linked list
    void display() {
        Node* current = head;
        while(current) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    };

    // to remove any item from the linked list
    void remove(int index) {
        Node* current = head;
        if(index == 0) {
            head = current->next;
            return;
        }

        int i = 0;
        while(current) {
            if(i == index - 1) {
                current->next = current->next->next;
                return;
            }
            current = current->next;
            i++;
        }
    };
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
    linkedlist.remove(0);
    linkedlist.remove(4);
    linkedlist.display();
    return 0;
}