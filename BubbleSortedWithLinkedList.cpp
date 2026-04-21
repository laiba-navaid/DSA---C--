// Bubble sort linked list
#include <iostream> 
#include <cstdlib>      
using namespace std;

struct Node {
    int data;           
    Node* next;         
};
Node* list = NULL;

void insert(int value)
{
    Node* tmp;                              

    tmp = (Node*) malloc(sizeof(Node));

    tmp->data = value;                     
    tmp->next = NULL;                      

    if (list == NULL)
    {
        list = tmp;                        
    }
    else
    {
        Node* current = list;   

        while (current->next != NULL)
        {
            current = current->next;       
        }

        current->next = tmp;               
    }
}

void display()
{
    Node* current = list;                  

    cout << "Linked List: ";               

    while (current != NULL)
    {
        cout << current->data << " -> "; 
        current = current->next;           
    }

    cout << "NULL" << endl;                       
}


void bubbleSort()
{
    if (list == NULL) {
        cout << "List is empty";
        return;
    }

    bool swapped;
    Node* p1;
    Node* p2 = NULL;

    do
    {
        swapped = false;
        p1 = list;

        while (p1->next != p2)
        {
            if (p1->data > p1->next->data)
            {
                int temp = p1->data;
                p1->data = p1->next->data;
                p1->next->data = temp;

                swapped = true;
            }
            p1 = p1->next;
        }
        p2 = p1;

    } while (swapped);
}

int main()
{
    int n;                                
    int value;                             
    cout << "Total values: ";
    cin >> n;                             
    for (int i = 0; i < n; i++)
    {
        cout << " Enter value: ";
        cin >> value;                      
        insert(value);                     
    }
     display();  
     
     bubbleSort();
     display();
     
     return 0;  
     
}