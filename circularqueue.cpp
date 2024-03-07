#include <iostream>
#define SIZE 10
using namespace std;

class Queue {
    int arr[SIZE];
    int f;
    int r;

    Queue() {
        f = -1;
        r = -1;
    }

    void enqueue() {
        if(f == 0 && r == SIZE - 1) {
            cout << "Overflow";
            return;
        }

        cout << "Enter the number to be inserted: ";
        int x;
        cin >> x;
        if(r == SIZE - 1) {
            r = 0;
        }
        arr[++r] = x;
    };

    void dequeue() {};
};

int main() {

    return 0;
}