#include <iostream>
using namespace std;



void push(int arr[], int &len) {
    if(len == 10) {
        cout << "Overflow (push)" << endl;
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
        cout << "Stackoverflow (pop)" << endl;
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



int main() {
    int n, num, len = 0;
    int arr[10];

    do {
        cout << "Enter a choice [1) Push 2) Pop 3) exit and display]:" << endl;
        cin >> n;
        if(n < 1 || n > 3 ) {
            cout << "Please enter a valid input" << endl;
            continue;
        }

        if(n == 1) push(arr, len);
        if(n == 2) pop(arr, len);
    }while(n != 3);

    display(arr, len);

    return 0;
}