#include <iostream>
#include <stack>
using namespace std;

// Tree node
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

// Function to check operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Build expression tree
Node* buildTree(string postfix) {
    stack<Node*> st;

    for (char ch : postfix) {
        // Operand
        if (!isOperator(ch)) {
            st.push(new Node(ch));
        }
        // Operator
        else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();

            Node* newNode = new Node(ch);
            newNode->left = left;
            newNode->right = right;

            st.push(newNode);
        }
    }

    return st.top();
}

// Inorder traversal (to check tree)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

int main() {
    string postfix = "ab+c*";

    Node* root = buildTree(postfix);

    cout << "Inorder (expression): ";
    inorder(root);

    return 0;
}