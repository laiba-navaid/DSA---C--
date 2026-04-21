// LINEAR PROBING 

#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void initialize() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;   // -1 means empty
    }
}

// Insert function
void insertKey(int key) {
    int index = key % SIZE;

    while(hashTable[index] != -1 && hashTable[index] != -2) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
    cout << "Key " << key << " inserted at index " << index << endl;
}

// Search function
void searchKey(int key) {
    int index = key % SIZE;
    int startIndex = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            cout << "Key " << key << " found at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;

        if(index == startIndex)
            break;
    }

    cout << "Key " << key << " not found." << endl;
}

// Delete function
void deleteKey(int key) {
    int index = key % SIZE;
    int startIndex = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            hashTable[index] = -2;   // Mark as deleted
            cout << "Key " << key << " deleted successfully.\n";
            return;
        }
        index = (index + 1) % SIZE;

        if(index == startIndex)
            break;
    }

    cout << "Key " << key << " not found.\n";
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

// Main function
int main() {
    int choice, key;
    initialize();

    while(true) {
        cout << "============ MENU ============";
        cout << "\n1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insertKey(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                searchKey(key);
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
