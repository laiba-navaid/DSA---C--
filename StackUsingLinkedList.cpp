*Stack using Linked List* 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;   // stack ka top

// PUSH function
void push(int value)
{
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = top;
    top = tmp;

    cout << value << " pushed into stack.\n";
}

// POP function
void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow! (Stack is empty)\n";
        return;
    }

    Node* temp = top;
    cout << top->data << " popped from stack.\n";

    top = top->next;
    delete temp;
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element is: " << top->data << endl;
}

(optional) 
void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty.\n";
        return;
    }

    Node* temp = top;
    cout << "Stack (top to bottom): ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    pop();
    pop();
    pop();   // underflow check

    return 0;
}

*menu driven 

int main()
{
    int choice, value;

    while (true)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            peek();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}