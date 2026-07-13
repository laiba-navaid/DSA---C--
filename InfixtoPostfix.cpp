#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* top = NULL;   

void push(char x) {
    Node* temp = new Node;   
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop() {
    if(top == NULL) {
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

char peek() {
    if(top == NULL)
        return '\0';
    return top->data;
}
bool isEmpty() {
    return (top == NULL);
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return 0;
    }
}

bool isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    return false;
}

int main() {

    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = "";

    for(int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        if(isalnum(ch)) {
            postfix += ch;
        }

        else if(ch == '(') {
            push(ch);
        }

        else if(ch == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix += peek();
                pop();
            }
            pop();  
        }

        else if(isOperator(ch)) {

            while(!isEmpty() &&
                  precedence(peek()) >= precedence(ch)) {

                postfix += peek();
                pop();
            }

            push(ch);
        }
    }

    while(!isEmpty()) {
        postfix += peek();
        pop();
    }

    cout << "Postfix Expression: " << postfix;

    return 0;
}