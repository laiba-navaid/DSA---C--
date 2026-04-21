// Circular Linked List 
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* list = NULL;   // head pointer

// INSERT (at end)
void insert(int value)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->data = value;

    // Agar list empty hai
    if (list == NULL)
    {
        list = tmp;
        tmp->next = list;   // circular link (self)
    }
    else
    {
        Node* current = list; // traversal ke liye

        // last node tak jana (jo head ko point karta ho)
        while (current->next != list)
        {
            current = current->next;
        }

        current->next = tmp; // last -> new
        tmp->next = list;    // new -> head
    }
}

// DISPLAY
void display()
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = list;
    cout << "Circular Linked List: ";

    do
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    while (current != list);

    cout << "(back to head)" << endl;
}

// SEARCH
void search(int key)
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = list;
    int pos = 1;

    do
    {
        if (current->data == key)
        {
            cout << "Value found at position " << pos << endl;
            return;
        }
        current = current->next;
        pos++;
    }
    while (current != list);

    cout << "Value not found" << endl;
}

// DELETE
void deleteValue(int key)
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = list;
    Node* prev = NULL;

    // Agar sirf aik hi node ho
    if (list->data == key && list->next == list)
    {
        free(list);
        list = NULL;
        cout << "Value deleted" << endl;
        return;
    }

    // Head delete karna ho
    if (list->data == key)
    {
        Node* last = list;

        // last node dhundhna
        while (last->next != list)
        {
            last = last->next;
        }

        Node* temp = list;
        list = list->next;     // head change

        last->next = list;    // circular link maintain
        free(temp);

        cout << "Value deleted" << endl;
        return;
    }

    // Beech ya last node delete
    prev = list;
    current = list->next;

    while (current != list && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == list)
    {
        cout << "Value not found" << endl;
        return;
    }

    prev->next = current->next;
    free(current);
    cout << "Value deleted" << endl;
}

// Main Function 
int main()
{
    int n;                                
    int value;   
    
    // cout << "========== MENU ===========" << endl;
    // cout << "1. Insert" << endl;
    // cout << "2. Search" << endl;
    // cout << "3. Delete" << endl;
    // cout << "4. Display" << endl;
    // cout << "5. Exit" << endl;

    /* Real-world programs mein:
       Menu repeat hota hai taake user dobara dekh sake
       Is liye aksar menu loop ke andar hota ha 
    */

    int choice;
    
    do {
        cout << "========== MENU ===========" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << " Enter your choice: ";
        cin >> choice;

        switch(choice) {
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

    } while (choice!= 5)     
    ;

    return 0;

    // cout << "Total values: ";

    // cin >> n;  

    // // Loop to take values for the list                           
    // for (int i = 0; i < n; i++)
    // {
    //     cout << " Enter value: ";
    //     cin >> value;                      
    //     insert(value); // to insert that value into the list                    
    // }

    //  display();  
    
    // cout << "Enter value to search: ";
    // cin >> key;
    // search(key);

    //  return 0;                             

    //     int n, value, key;

    //     cout << "Enter total number of values: ";
    //     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter value: ";
//         cin >> value;
//         insert(value);
//     }

//     display();

//     cout << "Enter value to search: ";
//     cin >> key;
//     search(key);

//     cout << "Enter value to delete: ";
//     cin >> key;
//     deleteValue(key);

//     display();

//     return 0;
}