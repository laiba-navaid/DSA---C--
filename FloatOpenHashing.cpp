#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define SIZE 5

struct Node {
    float data;
    Node* next;
};

Node hashTable[SIZE];   // Each slot acts as head node
bool occupied[SIZE];

// Initialize hash table
void initHashTable() {
    for(int i = 0; i < SIZE; i++){
        occupied[i] = false;
        hashTable[i].next = NULL;
    }
}

// Preprocess float for hashing
int preprocess(float key) {
    int intKey = floor(key * 1000); // preserve 3 decimal places
    if(intKey < 0) intKey = -intKey;
    return intKey;
}

// Hash function
int hashFunction(float key) {
    int intKey = preprocess(key);
    return intKey % SIZE;
}

// Insert float into chaining table
void insert(float key) {
    int index = hashFunction(key);

    if(!occupied[index]) {
        hashTable[index].data = key;
        hashTable[index].next = NULL;
        occupied[index] = true;
        cout << fixed << setprecision(3);
        cout << "Inserted: " << key << " at index " << index << endl;
        return;
    } else {
        Node* temp = new Node;
        temp->data = key;
        temp->next = NULL;

        Node* curr = &hashTable[index];
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        cout << fixed << setprecision(3);
        cout << "Inserted: " << key << " at index " << index << " in chain" << endl;
    }
}

// Search float in chaining table
void search(float key) {
    int index = hashFunction(key);

    if(!occupied[index]) {
        cout << "Value Not Found!" << endl;
        return;
    }

    Node* curr = &hashTable[index];
    while(curr != NULL){
        if(abs(curr->data - key) < 0.0001){  // epsilon comparison
            cout << fixed << setprecision(3);
            cout << "Key found at index " << index << endl;
            return;
        }
        curr = curr->next;
    }

    cout << fixed << setprecision(3);
    cout << key << " not found\n";
}

// Display table
void display() {
    cout << "Hash Table:" << endl;
    cout << fixed << setprecision(3);
    for(int i = 0; i < SIZE; i++){
        cout << i << " -> ";
        if(!occupied[i]){
            cout << "NULL";
        } else {
            Node* curr = &hashTable[i];
            while(curr != NULL){
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL";
        }
        cout << endl;
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
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}