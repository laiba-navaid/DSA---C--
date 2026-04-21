#include <iostream>
#include <cstdlib>
using namespace std;


struct TNode {
    char data;
    TNode* left;
    TNode* right;
};

// Stack Node (for TNode*)
struct Node {
    TNode* data;
    Node* next;
};

Node* top = NULL;


void push(TNode* value) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = top;
    top = tmp;
}


TNode* pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return NULL;
    }

    Node* tmp = top;
    TNode* val = top->data;
    top = top->next;
    delete tmp;

    return val;
}


TNode* createNode(char val) {
    TNode* newNode = new TNode;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}


TNode* buildTree(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // Operand
        if (!isOperator(ch)) {
            push(createNode(ch));
        }
        // Operator
        else {
            TNode* right = pop();
            TNode* left = pop();

            TNode* newNode = createNode(ch);
            newNode->left = left;
            newNode->right = right;

            push(newNode);
        }
    }

    return pop(); // root
}

// Inorder traversal to check 
void inorder(TNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

int main() {
    string postfix = "ab+c*";

    TNode* root = buildTree(postfix);

    cout << "Inorder Expression: ";
    inorder(root);

    return 0;
}
