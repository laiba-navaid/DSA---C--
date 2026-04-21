#include <iostream> 
#include <cstdlib>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* cur = NULL;

BSTNode* createNode(int value) {
    BSTNode* temp = (BSTNode*) malloc(sizeof(BSTNode));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert 
BSTNode* insert(BSTNode* cur, int value) 
{
    if(cur == NULL)
        return createNode(value);
    if(value < cur->data) 
        cur->left = insert(cur->left, value);
    else
        cur->right = insert(cur->right, value);

    return cur;
}

// Search
bool search(BSTNode* cur, int value) {
    if(cur == NULL) {
        return false;
    }

    if(cur->data == value) {
        return true;
    }

    if(value < cur->data) 
        return search(cur->left, value);
    else
        return search(cur->right, value);

}

// Traversal 

void preorder(BSTNode* cur) {
    // if(cur == NULL) {
    //     return;
    // }

    if(cur != NULL) {
        cout<< cur->data << " ";
        preorder(cur->left);
        preorder(cur->right);
    }
}

void inorder(BSTNode* cur) {
    // if(cur == NULL) {
    //     return;
    // }

    if(cur != NULL) {
        inorder(cur->left);
        cout<< cur->data << " ";
        inorder(cur->right);
    }
}

void postorder(BSTNode* cur) {
    // if(cur == NULL) {
    //     return;
    // }

    if(cur != NULL) {
        postorder(cur->left);
        postorder(cur->right);
        cout << cur->data << " ";
    }
}
// Minimum 
BSTNode* findMin(BSTNode* cur) {
    while(cur->left != NULL) 
        cur = cur->left
    return cur;
}

// Delete
Node* deleteNode(Node* cur, int value) {
    if (cur == NULL)
        return NULL;

    if (value < cur->data)
        cur->left = deleteNode(cur->left, value);

    else if (value > cur->data)
        cur->right = deleteNode(cur->right, value);

    else {
        // Case 1: No child
        if (cur->left == NULL && cur->right == NULL) {
            delete cur;
            return NULL;
        }
        // Case 2: One child
        else if (cur->left == NULL) {
            Node* temp = cur->right;
            delete cur;
            return temp;
        }
        else if (cur->right == NULL) {
            Node* temp = cur->left;
            delete cur;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(cur->right);
            cur->data = temp->data;
            cur->right = deleteNode(cur->right, temp->data);
        }
    }
    return cur;
}

int main() {
    int choice, value;

    do {
        cout << "========== MENU ===========" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Prefix" << endl;
        cout << "4. Infix" << endl;
        cout << "5. Postfix" << endl;
        cout << "6. Exit" << endl;
        cout << " Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            cur = insert(cur, value);
            break;

            case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if(search(cur, value)) {
                cout << "Value Found\n";
            } else {
                cout << "Not Found\n"; 
            }
            break;

            case 3: 
            cout << "PreOrder: ";
            preorder(cur);
            cout << endl;
            break;

            case 4: 
            cout << "InOrder: ";
            inorder(cur);
            cout << endl;
            break;

            case 5:
            cout << "PostOrder: ";
            postorder(cur);
            cout << endl;
            break;

            case 6: 
            cout << "Enter value to delete: ";
            cin >> value;
            cur = deleteNode(cur, value);
            break;

            case 7:
            cout << "Program Exit!" << endl;
            break;

            default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7)     
    ;

    return 0;
}