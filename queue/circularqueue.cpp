#include <iostream>
#define SIZE 10
using namespace std;

class Queue {
    int arr[SIZE];
    int f;
    int r;

    public:
    Queue() {
        f = -1;
        r = -1;
    }

    void enqueue() {
        if(f == 0 && r == SIZE || (f == r+1)) {
            cout << "Overflow";
            return;
        }

        cout << "Enter the number to be inserted: ";
        int x;
        cin >> x;
        if(f == -1) {
            f = 0;
            r = 0;
        }
        else if(r == SIZE - 1) {
            r = 0;
        }else r++;
        arr[r] = x;
    };

    void dequeue() {
        if(f == r) {
            cout << "Underflow" << endl;
            f = -1;
            r = -1;
            return;
        }

        if(f == SIZE - 1) f = 0;
        else f++;
    };

    void display() {
        if (f == -1) {
            cout << "Empty Queue" << endl;
            return;
        }

        cout << "Elements of the Queue are: " << endl;
        if (r < f) {
            for (int i = 0; i <= r; i++) {
                cout << arr[i] << endl;
            }
            for (int i = f; i < SIZE; i++) {
                cout << arr[i] << endl;
            }
        } else {
            for (int i = f; i <= r; i++) {
                cout << arr[i] << endl;
            }
        }
    }
};

int main() {
    Queue q;

    for(int i = 0; i < SIZE; i++) {
        q.enqueue();
    }

    for(int i = 0; i < 4; i++) {
        q.dequeue();
    }

    for(int i = 0; i < 4; i++) {
        q.enqueue();
    }
    q.display();
    return 0;   
}