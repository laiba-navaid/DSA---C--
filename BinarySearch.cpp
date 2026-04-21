// Binary Search
#include <iostream> 
using namespace std;

int main() {
    
    int input[10] = { 11, 20, 27, 33, 36, 67, 72, 82, 89, 98}; // Sorted Array 
    // int l = 0; 
    // int r = 9;
    // int mid;
    int l = 0, r = 9, mid;

    int target;
    cout << "Enter a target number: ";
    cin >> target;
    
    bool found = false;

    while(l <= r) {
        mid = l + (r - l) / 2; // Ye hamesha sahi middle index dega aur overflow ky lye bhi safe hai.
        // mid = (l + r) / 2; 

        if(input[mid] == target) {
            cout << "Target found at index " << mid << endl;
            found = true;
            break;
        }
        else if(input[mid] < target) {
            l = mid + 1; // target is at right part
        }
        else { // (input[mid] > target) 
            r = mid - 1; // target is at left part
        }
    }
    
    if(!found) {
        cout << "Target not found" << endl;
    }
    
    return 0;
} 