#include <iostream>
using namespace std;

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
        cout << "Queue FULL!\n";
        return;
    }
    if (q.front == -1) q.front = 0;
    q.data[++q.rear] = value;
}

int dequeue(Queue &q) {
    if (q.front == -1 || q.front > q.rear) {
        return -1;
    }
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

void push(Stack &s, int value) {
    if (s.top == MAX - 1) return;
    s.data[++s.top] = value;
}

int pop(Stack &s) {
    if (s.top == -1) return -1;
    return s.data[s.top--];
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}


void initializeGraph(Graph &g){
    g.vertexCount = 0;
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            g.matrix[i][j]=0;
}

void addVertex(Graph &g){
    if(g.vertexCount >= MAX) return;
    for(int i=0;i<g.vertexCount;i++){
        g.matrix[g.vertexCount][i]=0;
        g.matrix[i][g.vertexCount]=0;
    }
    g.vertexCount++;
}

void addEdge(Graph &g , int from , int to){
    if(from<0||to<0||from>=g.vertexCount||to>=g.vertexCount) return;
    g.matrix[from][to]=1;
    if(!g.isDirected)
        g.matrix[to][from]=1;
}

void removeVertex(Graph &g , int v){
    if(v<0||v>=g.vertexCount) return;

    for(int i=v;i<g.vertexCount-1;i++)
        for(int j=0;j<g.vertexCount;j++)
            g.matrix[i][j]=g.matrix[i+1][j];

    for(int i=0;i<g.vertexCount-1;i++)
        for(int j=v;j<g.vertexCount-1;j++)
            g.matrix[i][j]=g.matrix[i][j+1];

    g.vertexCount--;
}

void removeEdge(Graph &g , int from , int to){
    if(from<0||to<0||from>=g.vertexCount||to>=g.vertexCount) return;
    g.matrix[from][to]=0;
    if(!g.isDirected)
        g.matrix[to][from]=0;
}

void displayGraph(Graph &g){
    cout<<"\nMatrix:\n  ";
    for(int i=0;i<g.vertexCount;i++) cout<<i<<" ";
    cout<<endl;

    for(int i=0;i<g.vertexCount;i++){
        for(int j=0;j<g.vertexCount;j++)
            cout<<g.matrix[i][j]<<" ";
        cout<<endl;
    }
}


void BFS(Graph &g , int start){
    bool visited[MAX]={false};
    Queue q;
    initQueue(q);

    visited[start]=true;
    enqueue(q,start);

    cout<<"BFS: ";
    while(!isEmpty(q)){
        int cur=dequeue(q);
        cout<<cur<<" ";

        for(int j=0;j<g.vertexCount;j++){
            if(g.matrix[cur][j]==1 && !visited[j]){
                visited[j]=true;
                enqueue(q,j);
            }
        }
    }
    cout<<endl;
}


void DFS(Graph &g , int start){
    bool visited[MAX]={false};
    Stack s;
    initStack(s);

    push(s,start);
    visited[start]=true;

    cout<<"DFS: ";
    while(!isEmpty(s)){
        int cur=pop(s);
        cout<<cur<<" ";

        for(int j=0;j<g.vertexCount;j++){
            if(g.matrix[cur][j]==1 && !visited[j]){
                visited[j]=true;
                push(s,j);
            }
        }
    }
    cout<<endl;
}

// BFS based 
void findPath(Graph &g, int start, int end){
    bool visited[MAX]={false};
    int parent[MAX];

    for(int i=0;i<MAX;i++) parent[i]=-1;

    Queue q;
    initQueue(q);

    visited[start]=true;
    enqueue(q,start);

    while(!isEmpty(q)){
        int cur=dequeue(q);

        for(int j=0;j<g.vertexCount;j++){
            if(g.matrix[cur][j]==1 && !visited[j]){
                visited[j]=true;
                parent[j]=cur;
                enqueue(q,j);
            }
        }
    }

    if(!visited[end]){
        cout<<"No Path!\n";
        return;
    }

    Stack s;
    initStack(s);

    int v=end;
    while(v!=-1){
        push(s,v);
        v=parent[v];
    }

    cout<<"Path: ";
    while(!isEmpty(s)){
        cout<<pop(s);
        if(!isEmpty(s)) cout<<" -> ";
    }
    cout<<endl;
}


int main(){
    Graph g;
    int ch,from,to,v,start,end;

    initializeGraph(g);

    cout<<"Directed? (1/0): ";
    cin>>g.isDirected;

    while(true){
        cout<<"\n1.Add Vertex\n2.Add Edge\n3.Remove Edge\n4.Remove Vertex";
        cout<<"\n5.Display\n6.BFS\n7.DFS\n8.Find Path\n9.Exit\nChoice: ";
        cin>>ch;

        if(ch==1) addVertex(g);
        else if(ch==2){ cin>>from>>to; addEdge(g,from,to); }
        else if(ch==3){ cin>>from>>to; removeEdge(g,from,to); }
        else if(ch==4){ cin>>v; removeVertex(g,v); }
        else if(ch==5) displayGraph(g);
        else if(ch==6){ cin>>start; BFS(g,start); }
        else if(ch==7){ cin>>start; DFS(g,start); }
        else if(ch==8){ cin>>start>>end; findPath(g,start,end); }
        else if(ch==9) break;
    }
}
