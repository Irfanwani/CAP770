#include <iostream>
using namespace std;

struct Node {
    int info;
    struct Node *link;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->info = data;
    newNode->link = nullptr;
    return newNode;
}

void append(Node** head, int data) {
  Node* newNode = createNode(data);
  if (*head == nullptr) {
    *head = newNode;
    return;
  }

  Node* current = *head;
  while (current->link) {
    current = current->link;
  }
  current->link = newNode;

}

void display(Node *head) {
 while(head != nullptr) {
        cout << head->info << " -> ";
        head = head->link;
    }

    cout << "NULL" << endl;
};

int main() {
    struct Node *head = nullptr;
    int n, data;
    cout << "Enter the number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter data:" << endl;
        cin >> data;

        append(&head, data);
        
    } 

   display(head);
    
    return 0;
}