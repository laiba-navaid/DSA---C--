#include <iostream>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node* next;
};

// Normal recursive display
void display(Node* head)
{
    if (head == NULL)   // Base case
        return;

    cout << head->data << " ";
    display(head->next);
}

// Reverse recursive display
void displayReverse(Node* head)
{
    if (head == NULL)   // Base case
        return;

    displayReverse(head->next);
    cout << head->data << " ";
}

int main()
{
    // Creating nodes manually
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Assigning values
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    cout << "Normal Order: ";
    display(head);

    cout << endl;

    cout << "Reverse Order: ";
    displayReverse(head);

    return 0;
}

