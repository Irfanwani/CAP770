#include <iostream>
using namespace std;

int main() {
    int arr[20];
    for(int i = 1; i <= 20; i++) {
        arr[i-1] = i;
    }

    for(int i = 0; i < 20; i++) {
        if(arr[i] == 1) {
            arr[i] = 0;
        }
        if(arr[i]*arr[i] > 20) break;
        else {
            for(int j = i+1; j <= 20; j++) {
                if(arr[j] % arr[i] == 0) arr[j] = 0;
            }
        }

    }

    for(int i : arr) {
        if(i != 0)cout << i << endl;
    }

    return 0;
}
