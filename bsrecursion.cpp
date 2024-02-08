#include <iostream>
using namespace std;

int binarysearch(int arr[], int &start, int &end, int &size, int &key) {
    int middle = (start + end) / 2;
    if(arr[middle] == key) return middle;
     if(start == end){
         return -1;
    };
    if(arr[middle] < key) {
            start = middle + 1;
        }else {
            end = middle - 1;
        }
    return binarysearch(arr, start, end, size, key);
};

int main() {
    int n, x = 0, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int  arr[n];
    while(x < n && cin >> arr[x]) x++;
    
    cout << "Enter the number to find in the array: ";
    cin >> key;

    int start = 0;
    int end = n - 1;
    int bres = binarysearch(arr, start, end, n, key);
    if(bres == -1) 
        cout << "Item not found" << endl;
    else 
    cout << "Item found at index " << bres;


    return 0;
}