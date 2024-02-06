#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int middle = (start + end) / 2;
    while(start <= end) {
        if(arr[middle] == key) return middle;
        if(arr[middle] < key) {
            start = middle + 1;
        }else {
            end = middle - 1;
        }

        middle = (start + end) / 2;
    }

    return -1;
};

int main() {
    int n, x = 0, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int  arr[n];
    while(x < n && cin >> arr[x]) x++;
    
    cout << "Enter the number to find in the array: ";
    cin >> key;

    int bres = binarysearch(arr, n, key);
    cout << bres << endl;


    return 0;
}