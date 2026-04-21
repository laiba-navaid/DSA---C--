#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 3, 1, 4, 2};
    int n = 5;

    // Loop second element se start hoti hai
    for (int i = 1; i < n; i++) {

        int key = arr[i];     // Current element
        int j = i - 1;

        // Jab tak left side ka element bara ho
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Element ko right shift karo
            j--;
        }

        // Key ko uski correct position pe insert karo
        arr[j + 1] = key;
    }

    // Sorted array print karo
    cout << "Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

