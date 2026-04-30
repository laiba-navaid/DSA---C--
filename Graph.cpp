#include <iostream>
using namespace std;

#define SIZE 10

char vertices[SIZE];
int matrix[SIZE][SIZE] = {0};
int vCount = 0;

// Get index of vertex
int getIndex(char v) {
    for (int i = 0; i < vCount; i++)
        if (vertices[i] == v)
            return i;
    return -1;
}

// Add vertex
void addVertex(char v) {
    if (getIndex(v) != -1) {
        cout << "Vertex exists!\n";
        return;
    }
    vertices[vCount++] = v;
}

// Add edge (undirected)
void addEdge(char v1, char v2) {
    int i = getIndex(v1);
    int j = getIndex(v2);

    if (i == -1 || j == -1) {
        cout << "Invalid vertices\n";
        return;
    }

    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

// Remove edge
void removeEdge(char v1, char v2) {
    int i = getIndex(v1);
    int j = getIndex(v2);

    if (i == -1 || j == -1) return;

    matrix[i][j] = 0;
    matrix[j][i] = 0;

    cout << "Edge removed\n";
}

// Remove vertex
void removeVertex(char v) {
    int idx = getIndex(v);
    if (idx == -1) return;

    // Shift vertices
    for (int i = idx; i < vCount - 1; i++)
        vertices[i] = vertices[i + 1];

    // Shift rows up
    for (int i = idx; i < vCount - 1; i++)
        for (int j = 0; j < vCount; j++)
            matrix[i][j] = matrix[i + 1][j];

    // Shift cols left
    for (int j = idx; j < vCount - 1; j++)
        for (int i = 0; i < vCount; i++)
            matrix[i][j] = matrix[i][j + 1];

    vCount--;

    cout << "Vertex removed\n";
}

void display() {
    cout << "\nMatrix:\n   ";
    for (int i = 0; i < vCount; i++)
        cout << vertices[i] << " ";
    cout << endl;

    for (int i = 0; i < vCount; i++) {
        cout << vertices[i] << "  ";
        for (int j = 0; j < vCount; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}


void findDegree(char v) {
    int i = getIndex(v);
    if (i == -1) return;

    int degree = 0;
    for (int j = 0; j < vCount; j++)
        if (matrix[i][j] == 1)
            degree++;

    cout << "Degree of " << v << " = " << degree << endl;
}



bool isAdjacent(char v1, char v2) {
    int i = getIndex(v1);
    int j = getIndex(v2);

    if (i == -1 || j == -1) return false;

    if (matrix[i][j] == 1) {
        cout << "Adjacent\n";
        return true;
    }
    cout << "Not Adjacent\n";
    return false;
}


void findNeighbours(char v) {
    int i = getIndex(v);
    if (i == -1) return;

    cout << "Neighbours of " << v << ": ";

    for (int j = 0; j < vCount; j++) {
        if (matrix[i][j] == 1)
            cout << vertices[j] << " ";
    }
    cout << endl;
}



void BFS(char start) {
    bool visited[SIZE] = {false};
    int queue[SIZE], front = 0, rear = 0;

    int s = getIndex(start);
    if (s == -1) return;

    queue[rear++] = s;
    visited[s] = true;

    cout << "BFS: ";

    while (front < rear) {
        int curr = queue[front++];
        cout << vertices[curr] << " ";

        for (int i = 0; i < vCount; i++) {
            if (matrix[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}


void DFS(char start) {
    bool visited[SIZE] = {false};
    int stack[SIZE], top = -1;

    int s = getIndex(start);
    if (s == -1) return;

    stack[++top] = s;

    cout << "DFS: ";

    while (top != -1) {
        int curr = stack[top--];

        if (!visited[curr]) {
            visited[curr] = true;
            cout << vertices[curr] << " ";

            for (int i = vCount - 1; i >= 0; i--) {
                if (matrix[curr][i] == 1 && !visited[i])
                    stack[++top] = i;
            }
        }
    }
    cout << endl;
}



void findPath(char src, char dest) {
    bool visited[SIZE] = {false};
    int stack[SIZE], top = -1;

    int path[SIZE], len = 0;

    int s = getIndex(src);
    int d = getIndex(dest);

    stack[++top] = s;

    while (top != -1) {
        int curr = stack[top--];

        if (!visited[curr]) {
            visited[curr] = true;
            path[len++] = curr;

            if (curr == d) {
                cout << "Path: ";
                for (int i = 0; i < len; i++)
                    cout << vertices[path[i]] << " ";
                cout << endl;
                return;
            }

            for (int i = 0; i < vCount; i++) {
                if (matrix[curr][i] == 1 && !visited[i])
                    stack[++top] = i;
            }
        }
    }

    cout << "No Path\n";
}


bool isConnected(char v1, char v2) {
    bool visited[SIZE] = {false};
    int stack[SIZE], top = -1;

    int s = getIndex(v1);
    int d = getIndex(v2);

    stack[++top] = s;

    while (top != -1) {
        int curr = stack[top--];

        if (!visited[curr]) {
            visited[curr] = true;

            if (curr == d) {
                cout << "Connected\n";
                return true;
            }

            for (int i = 0; i < vCount; i++)
                if (matrix[curr][i] == 1 && !visited[i])
                    stack[++top] = i;
        }
    }

    cout << "Not Connected\n";
    return false;
}


bool isGraphConnected() {
    bool visited[SIZE] = {false};
    int queue[SIZE], front = 0, rear = 0;

    queue[rear++] = 0;
    visited[0] = true;

    while (front < rear) {
        int curr = queue[front++];

        for (int i = 0; i < vCount; i++) {
            if (matrix[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    for (int i = 0; i < vCount; i++) {
        if (!visited[i]) {
            cout << "Graph NOT connected\n";
            return false;
        }
    }

    cout << "Graph connected\n";
    return true;
}


bool isCyclic() {
    bool visited[SIZE] = {false};
    int parent[SIZE] = {-1};

    int stack[SIZE], top = -1;

    stack[++top] = 0;

    while (top != -1) {
        int curr = stack[top--];

        if (!visited[curr]) {
            visited[curr] = true;

            for (int i = 0; i < vCount; i++) {
                if (matrix[curr][i] == 1) {
                    if (!visited[i]) {
                        parent[i] = curr;
                        stack[++top] = i;
                    }
                    else if (parent[curr] != i) {
                        cout << "Cycle Found\n";
                        return true;
                    }
                }
            }
        }
    }

    cout << "No Cycle\n";
    return false;
}

int main() {
    int choice;
    char v1, v2;

    do {
        cout << "\n========= MATRIX GRAPH MENU =========";
        cout << "\n1. Add Vertex";
        cout << "\n2. Add Edge";
        cout << "\n3. Remove Vertex";
        cout << "\n4. Remove Edge";
        cout << "\n5. Display Graph";
        cout << "\n6. Find Degree";
        cout << "\n7. Check Adjacent";
        cout << "\n8. Find Neighbours";
        cout << "\n9. BFS";
        cout << "\n10. DFS";
        cout << "\n11. Find Path";
        cout << "\n12. Check Connected (Two Vertices)";
        cout << "\n13. Check Graph Connected";
        cout << "\n14. Check Cycle";
        cout << "\n15. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter vertex: ";
            cin >> v1;
            addVertex(v1);
            break;

        case 2:
            cout << "Enter two vertices: ";
            cin >> v1 >> v2;
            addEdge(v1, v2);
            break;

        case 3:
            cout << "Enter vertex to remove: ";
            cin >> v1;
            removeVertex(v1);
            break;

        case 4:
            cout << "Enter edge (v1 v2): ";
            cin >> v1 >> v2;
            removeEdge(v1, v2);
            break;

        case 5:
            display();
            break;

        case 6:
            cout << "Enter vertex: ";
            cin >> v1;
            findDegree(v1);
            break;

        case 7:
            cout << "Enter two vertices: ";
            cin >> v1 >> v2;
            isAdjacent(v1, v2);
            break;

        case 8:
            cout << "Enter vertex: ";
            cin >> v1;
            findNeighbours(v1);
            break;

        case 9:
            cout << "Enter start vertex: ";
            cin >> v1;
            BFS(v1);
            break;

        case 10:
            cout << "Enter start vertex: ";
            cin >> v1;
            DFS(v1);
            break;

        case 11:
            cout << "Enter source and destination: ";
            cin >> v1 >> v2;
            findPath(v1, v2);
            break;

        case 12:
            cout << "Enter two vertices: ";
            cin >> v1 >> v2;
            isConnected(v1, v2);
            break;

        case 13:
            isGraphConnected();
            break;

        case 14:
            isCyclic();
            break;

        case 15:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 15);

    return 0;
}
