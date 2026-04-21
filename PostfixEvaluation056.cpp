#include <iostream>
using namespace std;

int prec(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string s) {
    char st[100];
    int top = -1;
    string post = "";

    for(int i = 0; i < s.length(); i++) {

        if(s[i] >= '0' && s[i] <= '9') {
            post += s[i];
        }
        else if(s[i] == '(') {
            st[++top] = s[i];
        }
        else if(s[i] == ')') {
            while(st[top] != '(') {
                post += st[top--];
            }
            top--;
        }
        else {
            while(top != -1 && prec(st[top]) >= prec(s[i])) {
                post += st[top--];
            }
            st[++top] = s[i];
        }
    }

    while(top != -1) {
        post += st[top--];
    }

    return post;
}

int evaluate(string post) {
    int st[100];
    int top = -1;

    for(int i = 0; i < post.length(); i++) {

        if(post[i] >= '0' && post[i] <= '9') {
            st[++top] = post[i] - '0';
        }
        else {
            int b = st[top--];
            int a = st[top--];

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