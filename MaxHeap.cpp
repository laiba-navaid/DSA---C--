#include <iostream>
using namespace std;

int arr[100];
int size = 0;

void upHeapify(int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && arr[i] > arr[parent]) {
        swap(arr[i], arr[parent]);
        upHeapify(parent);
    }
}

void downHeapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        downHeapify(largest);
    }
}

void insert(int val) {
    arr[size] = val;
    upHeapify(size);
    size++;
}

void deleteRoot() {
    arr[0] = arr[size - 1];
    size--;
    downHeapify(0);
}

int main() {
    insert(55);
    insert(28);
    insert(76);
    insert(99);

    deleteRoot();

    return 0;
}