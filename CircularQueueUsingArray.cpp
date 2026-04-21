#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int curSize = 0;
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (curSize == SIZE) {
        cout << "Queue is full\n";
        return;
    }

    if (curSize == 0) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    curSize++;

    cout << value << " inserted\n";
}

void dequeue() {
    if (curSize == 0) {
        cout << "Queue is empty\n";
        return;
    }

    cout << queue[front] << " deleted\n";

    if (curSize == 1) {
        front = 0;
        rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }

    curSize--;
}

void display() {
    if (curSize == 0) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Circular Queue: ";

    // This prints entire array, even empty/old values. 
    // Circular queue should only print valid elements
    //for(int i = 0; i < SIZE; i++) {
    //    cout << queue[i] << " ";
    //}

    // Loop runs until rear is printed, since no NULL in circular queue

    int i = front;

    // Circular queue has no NULL end, so run loop manually
    while (true) {
        cout << queue[i] << " ";

        // Stop when rear is reached (last valid element)
        if (i == rear)
           break;

        // Move circularly
        i = (i + 1) % SIZE;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}