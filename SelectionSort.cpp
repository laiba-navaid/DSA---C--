#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 3, 1, 4, 2};
    int n = 5;

    // Outer loop: array ke har index ke liye
    for (int i = 0; i < n - 1; i++) {

        // Assume ke current index pe minimum value hai
        int minIndex = i;

        // Remaining array mein minimum value dhoondo
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;   // New minimum mil gaya
            }
        }

        // Minimum value ko current position se swap karo
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Sorted array print karo
    cout << "Selection Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

