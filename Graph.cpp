using namespace std;
#include<iostream>

const int MAX = 10;

struct Graph{
    int matrix[MAX][MAX];
    int vertexCount;
    bool isDirected;
};

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

void enqueue(Queue &q, int value) {
    if (q.rear == MAX - 1) {
        cout << "Queue is FULL!" << endl;
        return;
    }
    if (q.front == -1) {
        q.front = 0;
    }
    q.rear++;
    q.data[q.rear] = value;
}

int dequeue(Queue &q) {
    if (q.front == -1 || q.front > q.rear) {
        cout << "Queue is EMPTY!" << endl;
        return -1;
    }
    int value = q.data[q.front];
    q.front++;
    if (q.front > q.rear) {
        q.front = q.rear = -1;
    }
    return value;
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

void push(Stack &s, int value) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    s.data[++s.top] = value;
}

int pop(Stack &s) {
    if (s.top == -1) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return s.data[s.top--];
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

void initializeGraph(Graph &g){
     g.vertexCount = 0;
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j< MAX ; j++){
            g.matrix[i][j] = 0;
        }
    }
}

void addVertex(Graph &g){
    if(g.vertexCount >= MAX){
        cout<<"FULL";
        return;
    }
    // Loop 1 - new row
    for(int i = 0; i < g.vertexCount; i++) {
        g.matrix[g.vertexCount][i] = 0;
    }

    // Loop 2 - new column
    for(int i = 0; i < g.vertexCount; i++) {
        g.matrix[i][g.vertexCount] = 0;
    }

    g.vertexCount++;
}

void addEdge(Graph &g , int from , int to){
    if(from >= g.vertexCount || from < 0){
        cout << "Invalid Number !!!";
        return;
    }
    if(to >= g.vertexCount || to < 0){
        cout << "Invalid Number !!!";
        return;
    }

    g.matrix[from][to] = 1;
    if(g.isDirected == false ){
    g.matrix[to][from] = 1;
    }

}

void removeVertex(Graph &g , int vertex){
    if(vertex >= g.vertexCount || vertex < 0){
        cout << "Invalid vertex!!!";
        return;
    }
    for(int i = vertex ; i < g.vertexCount-1 ; i++){
        for(int j = 0; j < g.vertexCount ; j++){
        g.matrix[i][j] = g.matrix[i+1][j];
        }
    }
    for(int i = 0; i < g.vertexCount-1 ; i++){
        for(int j =vertex; j < g.vertexCount -1 ; j++){
        g.matrix[i][j] = g.matrix[i][j+1];
        }
    }
    g.vertexCount--;
}

void removeEdge(Graph &g , int from , int to){
    if(from >= g.vertexCount || from < 0){
        cout << "Invalid Number !!!";
        return;
    }
    if(to >= g.vertexCount || to < 0){
        cout << "Invalid Number !!!";
        return;
    }

    g.matrix[from][to] = 0;
    if(g.isDirected == false ){
    g.matrix[to][from] = 0;
    }

}

int findDegree(Graph &g , int vertex){
    int count = 0;
    if(vertex >= g.vertexCount || vertex < 0){
        cout << "Invalid vertex!!!";
        return -1;
    }
    
    for(int j = 0; j < g.vertexCount; j++){
        if(g.matrix[vertex][j] == 1){
            if(j == vertex){
                count += 2;   // self-loop counts as 2
            }
            else{
                count++;
            }
        }
    }

    return count;
}

int findInDegree(Graph &g , int vertex){
    int count = 0;
    if(vertex >= g.vertexCount || vertex < 0){
        cout << "Invalid vertex!!!";
        return -1;
    }
    
    for(int j = 0; j < g.vertexCount; j++){
        if(g.matrix[j][vertex] == 1){
                count++;
        }
    }

    return count;
}

int findOutDegree(Graph &g , int vertex){
    int count = 0;
    if(vertex >= g.vertexCount || vertex < 0){
        cout << "Invalid vertex!!!";
        return -1;
    }
    
    for(int j = 0; j < g.vertexCount; j++){
        if(g.matrix[vertex][j] == 1){
                count++;
        }
    }

    return count;
}

void displayGraph(Graph &g){
    cout<<"Graph Representation in Matrix Form : " <<endl;
    cout << "  ";  
    for(int i = 0; i < g.vertexCount; i++) {
    cout << i << " ";
    }
    cout << endl;
    for(int i = 0 ; i < g.vertexCount ; i++){
        for(int j = 0 ; j < g.vertexCount ; j++){
            cout << g.matrix[i][j];
        }
        cout<< endl;
    }
    
}

void BFS(Graph &g , int start){
    bool visited[MAX] = {false};
    Queue q;
    q = initQueue(q);
    visited[start] = true;
    enqueue(q , start);
    while(!isEmpty(q)){
        int current = dequeue(q);
        cout << current;
        for(int j = 0 ; j< g.vertexCount ; j++){
            if(g.matrix[current][j] == 1 && visited[j] == false){
                visited[j] = true;  
                enqueue(q, j);
            }
        }
    }
}

void DFS(Graph &g , int start){
    bool visited[MAX] = {false};
    Stack s;
    initStack(s);
    visited[start] = true;
    push(s, start);
    while(!isEmpty(s)){
        int current = pop(s);
        cout << current;
        for(int j = 0 ; j< g.vertexCount ; j++){
            if(g.matrix[current][j] == 1 && visited[j] == false){
                visited[j] = true;  
                push(s, j);
            }
        }
    }
}


int main(){
    Graph g;
    int ch, v, from, to, start;

    initializeGraph(g);

    cout << "Directed graph? (1 = Yes, 0 = No): ";
    cin >> g.isDirected;

    while(true){
        cout << "\n1. Add Vertex";
        cout << "\n2. Add Edge";
        cout << "\n3. Remove Edge";
        cout << "\n4. Remove Vertex";
        cout << "\n5. Find Degree";
        cout << "\n6. Find In-Degree";
        cout << "\n7. Find Out-Degree";
        cout << "\n8. Display Matrix";
        cout << "\n9. BFS";
        cout << "\n10. DFS";
        cout << "\n11. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        if(ch == 1){
            addVertex(g);
            cout << "Vertex added\n";
        }
        else if(ch == 2){
            cout << "Enter from and to: ";
            cin >> from >> to;
            addEdge(g, from, to);
        }
        else if(ch == 3){
            cout << "Enter from and to: ";
            cin >> from >> to;
            removeEdge(g, from, to);
        }
        else if(ch == 4){
            cout << "Enter vertex to remove: ";
            cin >> v;
        }
        else if(ch == 5){
            cout << "Enter vertex: ";
            cin >> v;
            cout << "Degree = " << findDegree(g, v);
        }
        else if(ch == 6){
            cout << "Enter vertex: ";
            cin >> v;
            cout << "In-Degree = " << findInDegree(g, v);
        }
        else if(ch == 7){
            cout << "Enter vertex: ";
            cin >> v;
            cout << "Out-Degree = " << findOutDegree(g, v);
        }
        else if(ch == 8){
            displayGraph(g);
        }
        else if(ch == 9){
            cout << "Enter starting vertex for BFS: ";
            cin >> start;
            BFS(g, start);
        }
        else if(ch == 10){
            cout << "Enter starting vertex for DFS: ";
            cin >> start;
            DFS(g, start);
        }
        else if(ch == 11){
            break;
        }
        else{
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
