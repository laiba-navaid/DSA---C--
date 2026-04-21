// QUADRATIC PROBING

#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

// Initialize table
void initialize() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;   // -1 means empty
}

// Insert using Quadratic Probing
void insertKey(int key) {
    int index, i = 0;

    while(i < SIZE) {
        index = (key % SIZE + i * i) % SIZE;

        if(hashTable[index] == -1 || hashTable[index] == -2) {
            hashTable[index] = key;
            cout << "Key " << key << " inserted at index " << index << endl;
            return;
        }
        i++;
    }

    cout << "Hash Table is Full!\n";
}

// Search using Quadratic Probing
void searchKey(int key) {
    int index, i = 0;

    while(i < SIZE) {
        index = (key % SIZE + i * i) % SIZE;

        if(hashTable[index] == -1) {
            cout << "Key not found.\n";
            return;
        }

        if(hashTable[index] == key) {
            cout << "Key found at index " << index << endl;
            return;
        }

        i++;
    }

    cout << "Key not found.\n";
}

// Delete function
void deleteKey(int key) {
    int index, i = 0;

    while(i < SIZE) {
        index = (key % SIZE + i * i) % SIZE;

        if(hashTable[index] == -1) {
            cout << "Key not found.\n";
            return;
        }

        if(hashTable[index] == key) {
            hashTable[index] = -2;   // mark as deleted
            cout << "Key deleted successfully.\n";
            return;
        }

        i++;
    }

    cout << "Key not found.\n";
}

// Display function
void display() {
    cout << "\nHash Table:\n";
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] == -1)
            cout << "Index " << i << " : Empty\n";
        else if(hashTable[i] == -2)
            cout << "Index " << i << " : Deleted\n";
        else
            cout << "Index " << i << " : " << hashTable[i] << endl;
    }
}

// Main
int main() {
    int choice, key;
    initialize();

    while(true) {
        cout << "============= MENU ==============";
        cout << "\n1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                insertKey(key);
                break;

            case 2:
                cout << "Enter key: ";
                cin >> key;
                searchKey(key);
                break;

            case 3:
                cout << "Enter key: ";
                cin >> key;
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
