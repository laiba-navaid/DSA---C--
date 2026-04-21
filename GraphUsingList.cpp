#include <iostream>
using namespace std;

const int MAX = 10;


struct Node {
    int vertex;
    Node* next;
};


struct Graph {
    Node* adjList[MAX];
    int vertexCount;
    bool isDirected;
};


struct Queue {
    int data[MAX];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

void enqueue(Queue &q, int val) {
    if (q.rear == MAX - 1) return;
    if (q.front == -1) q.front = 0;
    q.data[++q.rear] = val;
}

int dequeue(Queue &q) {
    if (q.front == -1 || q.front > q.rear) return -1;
    int val = q.data[q.front++];
    if (q.front > q.rear) q.front = q.rear = -1;
    return val;
}

bool isEmpty(Queue &q) {
    return q.front == -1;
}


struct Stack {
    int data[MAX];
    int top;
};

void initStack(Stack &s) {
    s.top = -1;
}

void push(Stack &s, int val) {
    if (s.top == MAX - 1) return;
    s.data[++s.top] = val;
}

int pop(Stack &s) {
    if (s.top == -1) return -1;
    return s.data[s.top--];
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}


void initializeGraph(Graph &g) {
    g.vertexCount = 0;
    for (int i = 0; i < MAX; i++)
        g.adjList[i] = NULL;
}

void addVertex(Graph &g) {
    if (g.vertexCount >= MAX) return;
    g.adjList[g.vertexCount] = NULL;
    g.vertexCount++;
}

void addEdge(Graph &g, int from, int to) {
    if (from < 0 || to < 0 || from >= g.vertexCount || to >= g.vertexCount)
        return;

    Node* newNode = new Node{to, g.adjList[from]};
    g.adjList[from] = newNode;

    if (!g.isDirected) {
        Node* newNode2 = new Node{from, g.adjList[to]};
        g.adjList[to] = newNode2;
    }
}

void displayGraph(Graph &g) {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < g.vertexCount; i++) {
        cout << i << " -> ";
        Node* temp = g.adjList[i];
        while (temp != NULL) {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}


void BFS(Graph &g, int start) {
    bool visited[MAX] = {false};
    Queue q;
    initQueue(q);

    visited[start] = true;
    enqueue(q, start);

    cout << "BFS: ";
    while (!isEmpty(q)) {
        int cur = dequeue(q);
        cout << cur << " ";

        Node* temp = g.adjList[cur];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                enqueue(q, temp->vertex);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}


void DFS(Graph &g, int start) {
    bool visited[MAX] = {false};
    Stack s;
    initStack(s);

    push(s, start);
    visited[start] = true;

    cout << "DFS: ";
    while (!isEmpty(s)) {
        int cur = pop(s);
        cout << cur << " ";

        Node* temp = g.adjList[cur];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                push(s, temp->vertex);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}


void findPath(Graph &g, int start, int end) {
    bool visited[MAX] = {false};
    int parent[MAX];

    for (int i = 0; i < MAX; i++) parent[i] = -1;

    Queue q;
    initQueue(q);

    visited[start] = true;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int cur = dequeue(q);

        Node* temp = g.adjList[cur];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                parent[temp->vertex] = cur;
                enqueue(q, temp->vertex);
            }
            temp = temp->next;
        }
    }

    if (!visited[end]) {
        cout << "No Path!\n";
        return;
    }

    Stack s;
    initStack(s);

    int v = end;
    while (v != -1) {
        push(s, v);
        v = parent[v];
    }

    cout << "Path: ";
    while (!isEmpty(s)) {
        cout << pop(s);
        if (!isEmpty(s)) cout << " -> ";
    }
    cout << endl;
}


int main() {
    Graph g;
    int ch, from, to, start, end;

    initializeGraph(g);

    cout << "Directed? (1/0): ";
    cin >> g.isDirected;

    while (true) {
        cout << "\n1.Add Vertex\n2.Add Edge\n3.Display";
        cout << "\n4.BFS\n5.DFS\n6.Find Path\n7.Exit\nChoice: ";
        cin >> ch;

        if (ch == 1) addVertex(g);
        else if (ch == 2) { cin >> from >> to; addEdge(g, from, to); }
        else if (ch == 3) displayGraph(g);
        else if (ch == 4) { cin >> start; BFS(g, start); }
        else if (ch == 5) { cin >> start; DFS(g, start); }
        else if (ch == 6) { cin >> start >> end; findPath(g, start, end); }
        else if (ch == 7) break;
    }
}
