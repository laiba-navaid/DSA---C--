#include<iostream>
using namespace std;

#define SIZE 100

struct Vertex;

struct Edge {
    Vertex* v;
    Edge* next;
};

struct Vertex {
    char data;
    Edge* edgeList;
    Vertex* next;
    bool visited;
};

Vertex* Graph = NULL;

Vertex* findVertex(char data) {
    Vertex* curr = Graph;
    while (curr != NULL) {
        if (curr->data == data)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void resetVisited() {
    Vertex* curr = Graph;
    while (curr != NULL) {
        curr->visited = false;
        curr = curr->next;
    }
}


void addVertex(char data) {
    if (findVertex(data) != NULL) {
        cout << "Vertex already exists!\n";
        return;
    }

    Vertex* newV = new Vertex();
    newV->data = data;
    newV->edgeList = NULL;
    newV->next = NULL;
    newV->visited = false;

    if (Graph == NULL)
        Graph = newV;
    else {
        Vertex* temp = Graph;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newV;
    }
}


void addEdgeAtEnd(Vertex* src, Vertex* dest) {
    Edge* e = new Edge();
    e->v = dest;
    e->next = NULL;

    if (src->edgeList == NULL)
        src->edgeList = e;
    else {
        Edge* temp = src->edgeList;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = e;
    }
}


void addUndirectedEdge(char a, char b) {
    Vertex* v1 = findVertex(a);
    Vertex* v2 = findVertex(b);

    if (!v1 || !v2) return;

    addEdgeAtEnd(v1, v2);
    addEdgeAtEnd(v2, v1);
}

/*
 * removeEdge – delete ONE directed edge from src → dest.
 *
 * Steps:
 *  1. Find src and dest vertices.
 *  2. Walk src's edgeList looking for an edge whose v == dest.
 *  3. Keep track of the previous edge so we can re-link.
 *  4. On match: bypass the node and delete it.
 *  5. For undirected graphs call twice (both directions).
 */
void removeEdge(char srcData, char destData) {
    Vertex* src  = findVertex(srcData);
    Vertex* dest = findVertex(destData);

    if (src == NULL || dest == NULL) {
        cout << "One or both vertices not found!" << endl;
        return;
    }

    Edge* curr = src->edgeList;
    Edge* prev = NULL;               // tracks the edge before 'curr'

    while (curr != NULL) {
        if (curr->v == dest) {       // found the edge to remove
            if (prev == NULL)
                src->edgeList = curr->next;   // it was the first edge
            else
                prev->next = curr->next;       // bypass it

            delete curr;
            cout << "Edge " << srcData << " -> " << destData << " removed." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Edge not found!" << endl;
}

/*
 * removeUndirectedEdge – remove both directions (A↔B).
 */
void removeUndirectedEdge(char a, char b) {
    removeEdge(a, b);
    removeEdge(b, a);
}

/*
 * removeVertex – delete a vertex AND every edge connected to it.
 *
 * Steps:
 *  1. Find the vertex in the global list.
 *  2. Delete all edges IN the vertex's own edgeList (outgoing edges).
 *  3. Loop through every OTHER vertex and remove edges pointing TO us
 *     (incoming edges) — same logic as removeEdge but without print.
 *  4. Remove the vertex node from the global linked list.
 */
void removeVertex(char data) {
    Vertex* target = findVertex(data);
    if (target == NULL) { cout << "Vertex not found!" << endl; return; }

    // Step 2: free all outgoing edges of this vertex
    Edge* e = target->edgeList;
    while (e != NULL) {
        Edge* temp = e;
        e = e->next;
        delete temp;
    }
    target->edgeList = NULL;

    // Step 3: remove incoming edges from every other vertex
    Vertex* curr = Graph;
    while (curr != NULL) {
        if (curr == target) { curr = curr->next; continue; }

        Edge* edge = curr->edgeList;
        Edge* prev = NULL;
        while (edge != NULL) {
            if (edge->v == target) {        // this edge points to our target
                if (prev == NULL)
                    curr->edgeList = edge->next;
                else
                    prev->next = edge->next;
                Edge* tmp = edge;
                edge = edge->next;
                delete tmp;
            } else {
                prev = edge;
                edge = edge->next;
            }
        }
        curr = curr->next;
    }

    // Step 4: remove the vertex from the global list
    if (Graph == target) {
        Graph = target->next;              // it was the head
    } else {
        Vertex* v = Graph;
        while (v->next != target)
            v = v->next;
        v->next = target->next;            // bypass it
    }

    delete target;
    cout << "Vertex " << data << " and all its edges removed." << endl;
}

/*
 * isAdjacent – check if there is a DIRECT edge from src to dest.
 *
 * Steps:
 *  1. Find src vertex.
 *  2. Scan its edgeList.
 *  3. If any edge's v == dest vertex, return true.
 */
bool isAdjacent(char srcData, char destData) {
    Vertex* src  = findVertex(srcData);
    Vertex* dest = findVertex(destData);

    if (src == NULL || dest == NULL) {
        cout << "One or both vertices not found!" << endl;
        return false;
    }

    Edge* e = src->edgeList;
    while (e != NULL) {
        if (e->v == dest) {
            cout << srcData << " and " << destData << " ARE adjacent." << endl;
            return true;
        }
        e = e->next;
    }
    cout << srcData << " and " << destData << " are NOT adjacent." << endl;
    return false;
}

/*
 * findNeighbours – print all vertices directly connected
 *                  to the given vertex.
 *
 * Steps:
 *  1. Find the vertex.
 *  2. Walk its edgeList and print each neighbour's data.
 */
void findNeighbours(char data) {
    Vertex* v = findVertex(data);
    if (v == NULL) { cout << "Vertex not found!" << endl; return; }

    cout << "Neighbours of " << data << ": ";
    Edge* e = v->edgeList;
    if (e == NULL) { cout << "None" << endl; return; }
    while (e != NULL) {
        cout << e->v->data << " ";
        e = e->next;
    }
    cout << endl;
}

/*
 * searchVertex – tell the user whether a vertex exists.
 *
 * Steps:
 *  1. Use findVertex helper.
 *  2. Print result.
 */
void searchVertex(char data) {
    if (findVertex(data) != NULL)
        cout << "Vertex " << data << " EXISTS in the graph." << endl;
    else
        cout << "Vertex " << data << " does NOT exist." << endl;
}


/*
 * outputAll – print every vertex and its adjacency list.
 *
 * Steps:
 *  1. Walk the global vertex list.
 *  2. For each vertex, print its data then walk its edgeList.
 */
void outputAll() {
    if (Graph == NULL) { cout << "Graph is empty!" << endl; return; }

    cout << "\n===== GRAPH ADJACENCY LIST =====" << endl;
    Vertex* curr = Graph;
    while (curr != NULL) {
        cout << "[" << curr->data << "] -> ";
        Edge* e = curr->edgeList;
        if (e == NULL) cout << "NULL";
        while (e != NULL) {
            cout << e->v->data;
            if (e->next != NULL) cout << " -> ";
            e = e->next;
        }
        cout << endl;
        curr = curr->next;
    }
    cout << "================================\n" << endl;
}


/*
 * findOutDegree – count edges GOING OUT from vertex 'data'.
 *                 (Same as the findDegree for directed graphs.)
 *
 * Steps:
 *  1. Find the vertex.
 *  2. Walk its edgeList and count every edge.
 */
void findOutDegree(char data) {
    Vertex* v = findVertex(data);
    if (v == NULL) { cout << "Vertex not found!" << endl; return; }

    int count = 0;
    Edge* curr = v->edgeList;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    cout << "Out-Degree of " << data << " = " << count << endl;
}

/*
 * findInDegree – count edges COMING IN to vertex 'data'.
 *
 * Steps:
 *  1. Find target vertex.
 *  2. Loop through ALL vertices.
 *  3. For each vertex, scan its edgeList.
 *  4. If any edge points to our target, increment count.
 */
void findInDegree(char data) {
    Vertex* target = findVertex(data);
    if (target == NULL) { cout << "Vertex not found!" << endl; return; }

    int count = 0;
    Vertex* curr = Graph;
    while (curr != NULL) {                   // for every vertex in graph
        Edge* e = curr->edgeList;
        while (e != NULL) {                  // for every edge of that vertex
            if (e->v == target)              // does this edge point to target?
                count++;
            e = e->next;
        }
        curr = curr->next;
    }
    cout << "In-Degree of " << data << " = " << count << endl;
}

/*
 * findDegree – total degree (in + out) for undirected graphs.
 *              Simply reuses the two functions above.
 */
void findDegree(char data) {
    Vertex* v = findVertex(data);
    if (v == NULL) { cout << "Vertex not found!" << endl; return; }

    // Out-degree: edges leaving this vertex
    int outDeg = 0;
    Edge* e = v->edgeList;
    while (e != NULL) { outDeg++; e = e->next; }

    // In-degree: edges from other vertices pointing here
    int inDeg = 0;
    Vertex* curr = Graph;
    while (curr != NULL) {
        Edge* edge = curr->edgeList;
        while (edge != NULL) {
            if (edge->v == v) inDeg++;
            edge = edge->next;
        }
        curr = curr->next;
    }

    cout << "Degree of " << data
         << " | In=" << inDeg
         << " | Out=" << outDeg
         << " | Total=" << (inDeg + outDeg) << endl;
}


// QUEUE (FOR BFS)

Vertex* queue[SIZE];
int front = -1, rear = -1;

void enqueue(Vertex* v) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

Vertex* dequeue() {
    if (front == -1 || front > rear) return NULL;
    Vertex* temp = queue[front++];
    if (front > rear) front = rear = -1;
    return temp;
}

bool isEmptyQueue() {
    return (front == -1 || front > rear);
}


// STACK (FOR DFS)

Vertex* stackArr[SIZE];
int top = -1;

void push(Vertex* v) {
    if (top == SIZE - 1) return;
    stackArr[++top] = v;
}

Vertex* pop() {
    if (top == -1) return NULL;
    return stackArr[top--];
}

bool isEmptyStack() {
    return (top == -1);
}


void BFS(char startData) {
    Vertex* start = findVertex(startData);
    if (!start) return;

    resetVisited();

    enqueue(start);
    start->visited = true;

    cout << "BFS: ";

    while (!isEmptyQueue()) {
        Vertex* curr = dequeue();
        cout << curr->data << " ";

        Edge* e = curr->edgeList;
        while (e != NULL) {
            if (!e->v->visited) {
                e->v->visited = true;
                enqueue(e->v);
            }
            e = e->next;
        }
    }
    cout << endl;
}


void DFS(char startData) {
    Vertex* start = findVertex(startData);
    if (!start) return;

    resetVisited();

    push(start);

    cout << "DFS: ";

    while (!isEmptyStack()) {
        Vertex* curr = pop();

        if (!curr->visited) {
            curr->visited = true;
            cout << curr->data << " ";

            Edge* e = curr->edgeList;
            while (e != NULL) {
                if (!e->v->visited)
                    push(e->v);
                e = e->next;
            }
        }
    }
    cout << endl;
}


// FIND PATH (DFS)
/*
Idea: DFS karo, aur jaise hi destination mil jaye → stop.
DFS chalao
Har visit ko path me daalte jao
Dest mila → DONE
*/
void findPath(char srcData, char destData) {
    Vertex* src = findVertex(srcData);
    Vertex* dest = findVertex(destData);

    if (!src || !dest) return;

    resetVisited();

    Vertex* stack[SIZE];
    int top = -1;

    char path[100];
    int len = 0;

    stack[++top] = src;

    while (top != -1) {
        Vertex* curr = stack[top--];

        if (!curr->visited) {
            curr->visited = true;
            path[len++] = curr->data;

            if (curr == dest) {
                cout << "Path: ";
                for (int i = 0; i < len; i++) {
                    cout << path[i];
                    if (i < len - 1) cout << " -> ";
                }
                cout << endl;
                return;
            }

            Edge* e = curr->edgeList;
            while (e != NULL) {
                if (!e->v->visited)
                    stack[++top] = e->v;
                e = e->next;
            }
        }
    }

    cout << "No Path Found\n";
}


// IS CONNECTED (SRC → DEST)
// Same DFS, bas true/false return karna hai
bool isConnected(char srcData, char destData) {
    Vertex* src = findVertex(srcData);
    Vertex* dest = findVertex(destData);

    if (!src || !dest) return false;

    resetVisited();

    push(src);

    while (!isEmptyStack()) {
        Vertex* curr = pop();

        if (!curr->visited) {
            curr->visited = true;

            if (curr == dest) {
                cout << "Connected\n";
                return true;
            }

            Edge* e = curr->edgeList;
            while (e != NULL) {
                if (!e->v->visited)
                    push(e->v);
                e = e->next;
            }
        }
    }

    cout << "Not Connected\n";
    return false;
}


// GRAPH CONNECTED (WHOLE GRAPH)
// BFS use karo
/* 
Simple idea:
BFS start from first node
Agar koi node visit nahi hua → graph broken
*/
bool isGraphConnected() {
    if (Graph == NULL) return true;

    resetVisited();

    enqueue(Graph);
    Graph->visited = true;

    while (!isEmptyQueue()) {
        Vertex* curr = dequeue();

        Edge* e = curr->edgeList;
        while (e != NULL) {
            if (!e->v->visited) {
                e->v->visited = true;
                enqueue(e->v);
            }
            e = e->next;
        }
    }

    Vertex* temp = Graph;
    while (temp != NULL) {
        if (!temp->visited) {
            cout << "Graph NOT connected\n";
            return false;
        }
        temp = temp->next;
    }

    cout << "Graph connected\n";
    return true;
}

// CYCLE DETECTION (DFS)
/* 
Trick: Agar visited node dobara mile (parent ko ignore karke) → cycle
Visited neighbour ≠ parent → 🔁 cycle
*/
bool isCyclic() {
    if (Graph == NULL) return false;

    resetVisited();

    Vertex* stack[SIZE];
    Vertex* parent[SIZE];

    int top = -1;

    stack[++top] = Graph;
    parent[top] = NULL;

    while (top != -1) {
        Vertex* curr = stack[top];
        Vertex* par = parent[top];
        top--;

        if (!curr->visited) {
            curr->visited = true;

            Edge* e = curr->edgeList;
            while (e != NULL) {
                if (!e->v->visited) {
                    stack[++top] = e->v;
                    parent[top] = curr;
                }
                else if (e->v != par) {
                    cout << "Cycle Found\n";
                    return true;
                }
                e = e->next;
            }
        }
    }

    cout << "No Cycle\n";
    return false;
}

/*
===== SUMMARY =====
| Function        | Logic                        |
| --------------- | ---------------------------- |
| Path            | DFS until destination        |
| isConnected     | DFS → destination mila?      |
| Graph Connected | BFS → sab visit hue?         |
| Cycle           | DFS + visited + parent check |

*/


void display() {
    Vertex* curr = Graph;

    while (curr != NULL) {
        cout << curr->data << " -> ";

        Edge* e = curr->edgeList;
        while (e != NULL) {
            cout << e->v->data << " ";
            e = e->next;
        }
        cout << endl;

        curr = curr->next;
    }
}


int main() {
    int choice;
    char v1, v2;

    do {
        cout << "\n========= GRAPH MENU =========";
        cout << "\n1. Add Vertex";
        cout << "\n2. Add Edge (Undirected)";
        cout << "\n3. Display Graph";
        cout << "\n4. Find Degree";
        cout << "\n5. BFS Traversal";
        cout << "\n6. DFS Traversal";
        cout << "\n7. Find Path";
        cout << "\n8. Check Connected (Two Vertices)";
        cout << "\n9. Check Graph Connected";
        cout << "\n10. Check Cycle";
        cout << "\n11. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter vertex: ";
            cin >> v1;
            addVertex(v1);
            break;

        case 2:
            cout << "Enter two vertices (A B): ";
            cin >> v1 >> v2;
            {
                Vertex* src = findVertex(v1);
                Vertex* dest = findVertex(v2);

                if (src == NULL || dest == NULL)
                    cout << "Invalid vertices!\n";
                else
                    addUndirectedEdge(v1, v2);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Enter vertex: ";
            cin >> v1;
            findDegree(v1);
            break;

        case 5:
            cout << "Enter start vertex: ";
            cin >> v1;
            BFS(v1);
            break;

        case 6:
            cout << "Enter start vertex: ";
            cin >> v1;
            DFS(v1);
            break;

        case 7:
            cout << "Enter source and destination: ";
            cin >> v1 >> v2;
            findPath(v1, v2);
            break;

        case 8:
            cout << "Enter two vertices: ";
            cin >> v1 >> v2;
            isConnected(v1, v2);
            break;

        case 9:
            isGraphConnected();
            break;

        case 10:
            isCyclic();
            break;

        case 11:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 11);

    return 0;
}
