#include <iostream>
using namespace std;

// priority function
int prec(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// infix → postfix
string infixToPostfix(string s) {
    char st[100];   // stack (operators)
    int top = -1;

    string post = "";

    for(int i = 0; i < s.length(); i++) {

        // agar number ho
        if(s[i] >= '0' && s[i] <= '9') {
            post = post + s[i];
        }

        // '('
        else if(s[i] == '(') {
            top++;
            st[top] = s[i];
        }

        // ')'
        else if(s[i] == ')') {
            while(st[top] != '(') {
                post = post + st[top];
                top--;
            }
            top--; // '(' remove
        }

        // operator
        else {
            while(top != -1 && prec(st[top]) >= prec(s[i])) {
                post = post + st[top];
                top--;
            }
            top++;
            st[top] = s[i];
        }
    }

    // remaining stack
    while(top != -1) {
        post = post + st[top];
        top--;
    }

    return post;
}

// postfix evaluation
int evaluate(string post) {
    int st[100];
    int top = -1;

    for(int i = 0; i < post.length(); i++) {

        // number
        if(post[i] >= '0' && post[i] <= '9') {
            top++;
            st[top] = post[i] - '0';
        }

        // operator
        else {
            int b = st[top]; top--;
            int a = st[top]; top--;

            if(post[i] == '+') st[++top] = a + b;
            else if(post[i] == '-') st[++top] = a - b;
            else if(post[i] == '*') st[++top] = a * b;
            else if(post[i] == '/') st[++top] = a / b;
        }
    }

    return st[top];
}

int main() {
    string infix;

    cout << "Enter expression: ";
    cin >> infix;

    string post = infixToPostfix(infix);
    cout << "Postfix: " << post << endl;

    cout << "Answer: " << evaluate(post);

    return 0;
}
