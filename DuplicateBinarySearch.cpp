// Duplicates Binary Search 
#include <iostream> // ye input/output ke liye library hai (cin, cout).
using namespace std; // ye std namespace ko directly use karne ke liye, varna har line me std::cout type karna parta

int main() { // Ye main function hai jahan se program start hota hai.
    
    // Sorted array with duplicate values (jismy "Binary Search" krengy)
    int input[10] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8}; 

    // Left and right boundaries for binary search, and middle index
    int l = 0, r = 9, mid;

    // Variable to store the number user wants to search
    int target;

    // Ask user for target number
    cout << "Enter a target number: ";
    cin >> target;

    // Variables to store first and last occurrence indexes
    int first = -1; // -1 means not found yet
    int last = -1;

    
    // Find First Occurrence
    l = 0, r = 9; // Reset boundaries for search (kyunki pehle bhi variables change hue ho skty)

    while(l <= r) { // Loop until left boundary crosses right
        mid = l + (r - l) / 2; // Calculate middle index safely

        if(input[mid] == target) {
            first = mid;       // Temporarily store this as first occurrence (first occurrence ka temporary index store kiya)
            r = mid - 1;       // Check left side to see if target occurs earlier (left side me check karenge, shayad aur pehle occurrence ho).
        } 
        else if(input[mid] < target) { // Agar middle element target se chota hai, target right side me hai -> left boundary update.
            l = mid + 1;       // Target must be in the right half
        } 
        else { // (input[mid] > target) // Agar middle element target se bara hai, target left side me hai -> right boundary update.
            r = mid - 1;       // Target must be in the left half
        }
    }
    
    
    // Find Last Occurrence
    l = 0, r = 9; // Reset boundaries for search again

    while(l <= r) {   // Loop until left <= right
        mid = l + (r - l) / 2; // Calculate middle index

        if(input[mid] == target) {
            last = mid;      // Temporarily store this as last occurrence
            l = mid + 1;     // Check right side to see if target occurs later (right side me check karenge, shayad aur baad me occurrence horhi ho.)
        } // Agar target chota ya bara hai -> boundaries update karke left/right search karenge.
        else if(input[mid] < target) {
            l = mid + 1;     // Target must be in the right half
        } 
        else { // input[mid] > target
            r = mid - 1;     // Target must be in the left half
        }
        
    }

    
    // Print result
    if(first == -1) { // Target not found
        cout << "Target not found" << endl;
    } else {          // Target found
        cout << "Target found from index " << first << " to " << last << endl;
    }
    
    return 0; // Program ends
}

/* Summary:

1. Binary search do baar chalaya:
Pehli baar -> first occurrence
Dusri baar -> last occurrence

2. Array sorted hai, isliye binary search kaam karta hai

3. Agar target array me hai -> first to last index print karega

4. Agar nahi → Target not found
*/