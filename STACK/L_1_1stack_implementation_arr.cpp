#include <iostream>
#define SIZE 5
using namespace std;
class Stack{
    int stack[5];
    int top;
    public:
    Stack(){
        top=-1;
        }
    private:
    bool stackisfull(){
        return top == SIZE -1 ;
    }
    bool stackempty(){
        return top==-1;
    }
    public:
    void push(int element){
        if(!stackisfull()){
        top++;
        stack[top]=element;
        cout<<"You have pushed "<<stack[top]<< " in the stack"<<endl;
        }
    else{
        cout<<"Stack is full"<<endl;
        }
    }
    void pop(){
        if(!stackempty()){
            cout<<"Popped element is "<<stack[top]<<endl;
            top--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    void peek(){
        cout<<"Element at the top of the stack is "<<stack[top]<<endl;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    s.peek();
    return 0;
}