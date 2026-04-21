#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Global pointers
Node* front = NULL;
Node* rear = NULL;

// Enqueue (Insert at rear)
void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted\n";
}

// Dequeue (Delete from front)
void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << front->data << " deleted\n";

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

// Front function (Peek)
void getFront() {
    if (front == NULL) {
        cout << "Queue is empty\n";
    }
    else {
        cout << "Front element: " << front->data << endl;
    }
}

// Display queue
void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << "Queue: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    getFront();

    dequeue();
    getFront();

    display();

    return 0;
}