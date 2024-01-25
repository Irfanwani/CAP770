#include <iostream>
using namespace std;
int main() {

int a[11] = {1, 2, 3, 4, 5, 34, 23, 12, 56, 65};
int x = 2, f = 0;
// less efficient
for(int i = 0; i < 10; i++) {
    if (a[i] == x) {
        cout << "Index of " << x << " is: " << i << endl;
        f = 1;
        break;
    } 
}

if(f == 0) cout << "Element not found" << endl;

// more efficient way

a[10] = x;
int i = 0;
for(i = 0; a[i] != x; i++);
if(i != 11) {
    cout << "Item found at " << i << endl;
}else {
    cout << "Item not found" << endl;
}
return 0;
};