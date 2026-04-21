
#include <iostream> 
#include <cstdlib>      
using namespace std;

// Node ka structure 
struct Node {
    int data;  // value store karne ke liye         
    Node* next;  // next node ka address 
};

Node* list = NULL;

// INSERT FUNCTION 
void insert(int value)
{
    Node* tmp;                              

    tmp = (Node*) malloc(sizeof(Node));

    tmp->data = value;  // data set kara                    
    tmp->next = NULL;        // last node hoga               

    // agar list empty ho
    if (list == NULL)
    {
        list = tmp;     // list ko tmp bana do                    
    }
    else
    {
        Node* current = list;   // traversal ke liye 

        // To increment the current (current++)
        while (current->next != NULL) // last node tak jana 
        {
            current = current->next;       
        }

        current->next = tmp;   // tmp ko last sy jor diya             
    }
}

// DISPLAY FUNCTION
void display()
{
    // agar list empty ho
    if (list == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = list;                  

    cout << "Linked List: ";               

    while (current != NULL)
    {
        cout << current->data << " -> "; 
        current = current->next;           
    }

    cout << "NULL" << endl;                   
}

// SEARCH FUNCTION
void search(int key)
{
    Node* current = list;
    int pos = 1;

    while (current != NULL)
    {
        if (current->data == key)
        {
            cout << "Value " << key << " found at position " << pos << endl;
            return;
        }
        current = current->next;
        pos++;
    }

    cout << "Value " << key << " not found" << endl;
}

// DELETE FUNCTION
void deleteValue(int value) {
    Node* current = list;

    if(value == list->data) {
        list = list->next;
        free(current);
        return;
    }

    Node* prev = list;
    current = list->next;

    while(current != NULL) {

        if(value == current->data) {
            prev->next = current->next;
            free(current);
            break;
        }

        current = current->next;
        prev = prev->next;

    }
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
}


 



    


