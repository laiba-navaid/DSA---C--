 // Doubly Linked List
#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure
struct Node
{
    int data;        // data store karega
    Node* next;      // next node ka address
    Node* prev;      // previous node ka address
};

Node* list = NULL;   // head pointer (starting node)

/* ================= INSERT (at end) ================= */
void insert(int value)
{
    // Node* tmp = new Node();
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = NULL;
    tmp->prev = NULL;

    // Agar list empty ho
    if (list == NULL)
    {
        list = tmp;          // head ban gaya
    }
    else
    {
        Node* current = list;

        // last node tak jana
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = tmp;  // last -> next = new
        tmp->prev = current;  // new -> prev = last
    }
}

/* ================= DISPLAY ================= */
void display()
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = list;
    cout << "Doubly Linked List: ";

    while (current != NULL)
    {
        cout << current->data << " <-> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

/* ================= SEARCH ================= */
void search(int key)
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = list;
    int pos = 1;

    while (current != NULL)
    {
        if (current->data == key)
        {
            cout << "Value found at position " << pos << endl;
            return;
        }
        current = current->next;
        pos++;
    }

    cout << "Value not found" << endl;
}

/* ================= DELETE ================= */
void deleteValue(int key)
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = list;

    // Head delete karna ho
    if (current->data == key)
    {
        list = current->next;

        // Agar next node exist karta ho
        if (list != NULL)
            list->prev = NULL;

        free(current);
        cout << "Value deleted" << endl;
        return;
    }

    // Beech ya last node delete
    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    // Links adjust karna
    current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    cout << "Value deleted" << endl;
}

/* ================= MAIN FUNCTION ================= */
int main()
{
    int choice, value;

    do
    {
        cout << "\n========== MENU ===========" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteValue(value);
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Program Exit!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
  
