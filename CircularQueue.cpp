#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue (Insert)
void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    // If queue is empty
    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front; // circular link
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // maintain circular
    }

    cout << value << " inserted\n";
}

// Dequeue (Delete)
void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    // Only one node
    if (front == rear) {
        cout << front->data << " deleted\n";
        delete front;
        front = rear = NULL;
    }
    else {
        Node* temp = front;
        cout << front->data << " deleted\n";
        front = front->next;
        rear->next = front; // maintain circular
        delete temp;
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

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << endl;
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}