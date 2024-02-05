#include <iostream>
using namespace std;

int main() {
    int arr[100], size;
    do {
    cout << "Enter the number of elements: " << endl;
    cin >> size;
    }while(size <= 0 || size >= 100);

    int x = 0;
    cout << "Enter the elements: " << endl;
    while(x < size && cin >> arr[x]) x++;
    int num, index;
    cout << "Enter the new number and its index: " << endl;
    cin >> num >> index;
    for(int i = size; i >= index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = num;

    for(int i = 0; i <= size; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}

