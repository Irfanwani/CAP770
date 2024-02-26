#include <iostream>
#define SIZE 20
using namespace std;

class Stack {
    int n, num, len;
    int arr[SIZE];

    public:
    Stack(): len(0) {

    do {
        cout << "Enter a choice\n1) Push\n2) Pop\n3) is empty\n4) is full\n5) exit and display" << endl;
        cin >> n;
        if(n < 1 || n > 5 ) {
            cout << "Please enter a valid input" << endl;
            continue;
        }

        if(n == 1) push(arr, len);
        if(n == 2) pop(arr, len);
        if(n == 3) cout << "Stack is " << (isEmpty() ? "Empty" : "Not Empty") << endl;
        if(n == 4) cout << "Stack is " << (isFull() ? "Full" : "Not Full") << endl;
    }while(n != 5);

    display(arr, len);
    };


    void push(int arr[], int &len) {
        if(len == SIZE) {
            cout << "Overflow - Stack is full" << endl;
            return;
        }
        int n;
        cout << "Enter the number to add to the stack" << endl;
        cin >> n;
        arr[len] = n;
        len++;
    };

    void pop(int arr[], int &len) {
        if(len == 0) {
            cout << "Underflow - Stack is empty" << endl;
            return;
        }
        int last = arr[len-1];
    
        cout << "Element removed: " << last << endl;

        len--;
    };

    void display(int arr[], int len) {
        cout << "Stack elements are as: "<< endl;
        for(int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
    }

    bool isEmpty() {
        return !len;
    }

    bool isFull() {
        return (len == 20);
    }

};

int main() {
    Stack stack;
    return 0;
}