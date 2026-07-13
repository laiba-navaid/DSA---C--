#include <iostream>
using namespace std;

#define SIZE 10  
#define DELETED -2
#define EMPTY -1

string hashTable[SIZE];

// Initialize table
void initHashTable() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Polynomial Rolling Hash Function
int hashFunction(string key) {
    int h = 0;
    for (char c : key){
        h = (h*31 + c)%SIZE;

    }
    return h;
}

// Insert using Linear Probing
void insert(string key) {
    int index = hashFunction(key);
    for(int i = 0 ; i<SIZE ; i++){
        int newIndex = (index + i) % SIZE;
        if(hashTable[i] == EMPTY || hashTable[i] == DELETED){
            hashTable[i] = key;
            cout<<"Inserted";
            return;
        }

    }
    cout<<"Hashtable is full!!!!";
}

// Search using Linear Probing
void search(string key) {

    int index = hashFunction(key);
    int startIndex = index;

    while(occupied[index]) {

        if(hashTable[index] == key) {
            cout << "Found \"" << key << "\" at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if(index == startIndex)
            break;
    }

    cout << "\"" << key << "\" not found.\n";
}

// Display table
void display() {
    cout << "\nHash Table:\n";
    for(int i = 0; i < SIZE; i++) {
        if(occupied[i])
            cout << "Index " << i << " : " << hashTable[i] << endl;
        else
            cout << "Index " << i << " : Empty\n";
    }
}

// Main Menu
int main() {

    initHashTable();

    int choice;
    string value;

    while(true) {

        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter string to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Enter string to search: ";
                cin >> value;
                search(value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}