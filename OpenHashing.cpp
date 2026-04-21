#include <iostream>
#include <stdlib.h>
using namespace std;

const int SIZE = 10; 


struct Node {
    int key;
    Node* next;
};

Node* hashTable[SIZE] = {NULL}; 


// Hash Function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert
void insert(int key) {
    int index = hashFunction(key);
        
    // Node* newNode = new Node; // memory allocate 
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->key = key;

    // Insert at beginning of linked list
    newNode->next = hashTable[index]; 
    hashTable[index] = newNode;

    cout << key << " inserted at index " << index << endl;
}

// Search
void search(int key) {
    int index = hashFunction(key);
    Node* current = hashTable[index];

    while (current != NULL) {
        if (current->key == key) {
            cout << key << " found at index " << index << endl;
            return;
        }
        current = current->next;
    }

    cout << key << " not found" << endl;
}

// Delete key
void deleteKey(int key) {
    int index = hashFunction(key);
    Node* current = hashTable[index];
    Node* prev = NULL;

    while(current != NULL) {
        if(current->key == key) {
            if(prev == NULL) { // first remove kr rhy 
                hashTable[index] = current->next;
            } else { // beech mein kr rhy
                prev->next = current->next;
            }

            delete current;
            cout << "Deleted " << key << "from index " << index << endl;
            return;
        }

        prev = current;
        current = current->next;
    }

    cout<< key << " not found in table " << endl;
} 

// Display hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* current = hashTable[i];

        while (current != NULL) {
            cout << current->key << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}


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
            deleteKey(value);
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



// // Mian function
// int main() {
//     // HashTable ht(7);

//     insert(15);
//     insert(25);
//     insert(35);
//     insert(5);

//     cout << "\nHash Table:\n";
//     display();
    
//     search(25);

//     deleteKey(25);
//     display();

//     search(25);

//     return 0;
// }
