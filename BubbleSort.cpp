#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 3, 1, 4, 2};
    int n = 5;

    // Outer loop: total passes (n-1)
    for (int i = 0; i < n - 1; i++) {

        // Inner loop: compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {

            // Agar left element bara ho right se
            if (arr[j] > arr[j + 1]) {

                // Dono elements swap karo
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Har pass ke baad largest element end pe chala jata hai
    }

    // Sorted array print karo
    cout << "Bubble Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

