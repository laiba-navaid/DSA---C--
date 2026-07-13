using namespace std;
#include <stdlib.h>
#include <iostream>

struct LL_Node {
    int data;
    LL_Node* next;
};

LL_Node* list = NULL;

// =====================
// INSERT (YOUR CODE)
// =====================
void insert(int value) {
    LL_Node* temp;
    temp = (LL_Node*)malloc(sizeof(LL_Node));
    temp->data = value;
    temp->next = NULL;
    if(list == NULL) {
        list = temp;
    } else {
        LL_Node* curr = list;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// =====================
// DISPLAY (YOUR CODE)
// =====================
void display() {
    if(list == NULL) {
        cout << "List is empty!!";
        return;
    }
    LL_Node* curr = list;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// =====================
// FIND MIDDLE
// =====================
LL_Node* findMiddle(LL_Node* head) {
    LL_Node* slow = head;
    LL_Node* fast = head;

    while(fast->next != NULL &&
          fast->next->next != NULL) {
        slow = slow->next;        // 1 step
        fast = fast->next->next;  // 2 steps
    }
    return slow;  // slow = middle!
}

// =====================
// MERGE
// =====================
LL_Node* merge(LL_Node* left, LL_Node* right) {
    // base cases
    if(left == NULL) return right;
    if(right == NULL) return left;

    if(left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    }
    else {
        right->next = merge(left, right->next);
        return right;
    }
}

// =====================
// MERGE SORT
// =====================
LL_Node* mergeSort(LL_Node* head) {
    // base case
    if(head == NULL ||
       head->next == NULL)
        return head;

    // find middle
    LL_Node* mid = findMiddle(head);

    // split into two halves
    LL_Node* leftHalf  = head;
    LL_Node* rightHalf = mid->next;
    mid->next = NULL;  // break the link!

    // sort each half
    leftHalf  = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    // merge and return
    return merge(leftHalf, rightHalf);
}

// =====================
// MAIN
// =====================
int main() {
    // insert values
    insert(4);
    insert(2);
    insert(5);
    insert(1);

    // display original
    cout << "Before sorting: ";
    display();
    cout << endl;

    // sort!
    // update global list with sorted result
    list = mergeSort(list);

    // display sorted
    cout << "After sorting:  ";
    display();
    cout << endl;

    return 0;
} linked list merge sort