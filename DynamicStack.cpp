#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) 
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = top;
    top = tmp;

    cout<< value << " pushed into Stack.\n";
}

void pop() 
{
    if(top == NULL)
    {
        cout<< "Stack Underflow!\n"; // stack is empty
        return;
    }

    Node* tmp = top;
    cout<< top->data << " popped from stack. \n";

    top = top->next;
    delete tmp;
}

void display() 
{
    if(top == NULL) 
    {
        cout<< "Stack is empty.\n";
        return;
    }

    Node* tmp = top;
    cout<< "Stack (top to bottom): ";
    while(tmp != NULL)
    {
        cout<< tmp->data << " ";
        tmp = tmp->next;
    }
    
}

int main() {

    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    pop();
    pop();
    pop(); // underflow check

    return 0;
}