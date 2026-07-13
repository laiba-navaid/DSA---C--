#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* list = NULL;

void insert(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;

    if (list == NULL) {
        list = temp;
        return;
    }
    node* curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

int partition(int arr[], int st, int end) {
    int idx = st;
    int pivot = arr[end];
    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            swap(arr[j], arr[idx]);
            idx++;
        }
    }
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(int arr[], int st, int end) {
    if (st < end) {
        int pivotIndex = partition(arr, st, end);
        quickSort(arr, st, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

void sortList() {
    if (list == NULL) return;

    // step 1 — count nodes
    int n = 0;
    node* curr = list;
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }

    // step 2 — copy linked list into array
    int arr[n];
    curr = list;
    for (int i = 0; i < n; i++) {
        arr[i] = curr->data;
        curr = curr->next;
    }

    // step 3 — sort the array
    quickSort(arr, 0, n - 1);

    // step 4 — copy sorted array back into linked list
    curr = list;
    for (int i = 0; i < n; i++) {
        curr->data = arr[i];
        curr = curr->next;
    }
}

void display() {
    if (list == NULL) {
        cout << "List is empty\n";
        return;
    }
    node* curr = list;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    insert(9);
    insert(2);

    cout << "Before sorting: ";
    display();

    sortList();

    cout << "After sorting:  ";
    display();

    return 0;
}