#include <iostream>
#include <cmath>
#include <iomanip> // for setprecision
using namespace std;

#define SIZE 10 // size of hash table

float hashTable[SIZE];
bool occupied[SIZE];

// Initialize hash table
void initHashTable() {
    for(int i = 0; i < SIZE; i++)
        occupied[i] = false;
}

// Hash function for float key
int hashFunction(float key) {
    int index = (int)(key * 1000) % SIZE;
    if(index < 0){
        index+=SIZE;
    }
    return index;
}

// Insert element into hash table (linear probing)
void insert(float key) {
    int index = hashFunction(key);
    int startIndex = index;

    while(occupied[index]) { // collision resolution
        index = (index + 1) % SIZE;
        if(index == startIndex) {
            cout << "Hash table is FULL! Cannot insert " << key << endl;
            return;
        }
    }

    hashTable[index] = key;
    occupied[index] = true;
    cout << fixed << setprecision(3); // 3 decimal places
    cout << "Inserted: " << key << " at index " << index << endl;
}

// Search for a float key
void search(float key) {
    int index = hashFunction(key);
    int startIndex = index;

    while(occupied[index]) {
        if(abs(hashTable[index] - key) < 0.0001) { // handle float comparison
            cout << fixed << setprecision(3);
            cout << "Found " << key << " at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if(index == startIndex) break; // came back to start → not found
    }

    cout << fixed << setprecision(3);
    cout << key << " not found in hash table" << endl;
}

// Display hash table
void display() {
    cout << fixed << setprecision(3);
    cout << "Hash Table:" << endl;
    for(int i = 0; i < SIZE; i++){
        if(occupied[i]){
            cout << "Index " << i << ": " << hashTable[i] << endl;
        }
        else{
            cout << "Index " << i << ": " << "Empty" << endl;
        }
    }
}

// MAIN MENU
int main() {
    initHashTable();
    int choice;
    float value;

    while(true){
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter float value to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Enter float value to search: ";
                cin >> value;
                search(value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}