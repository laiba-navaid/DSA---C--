#include <iostream>
using namespace std;
#define Max 5
int stack[Max];
int top = -1;
void push(int value)
{
    if (top == Max - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = value;
        cout << value << " pushed into the stack" << endl;
    }
}
void pop (){
    if(top==-1){
        cout <<" Stack underflow"<<endl;
        return;
    }
    else{
        cout<<stack[top]<<endl;
        top--;
    }
}

void display(){
    if(top==-1){
        cout<<"stack  is empty"<<endl;
    
    }
    else{
        for(int i=top;i>=0;i--){
            cout<<stack[i]<<" ";
        }

    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    display();

    return 0;
}