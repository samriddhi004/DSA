// PRIORITY of operators ^ , *&/ , +*-
#include <iostream>
#include<string>
#define SIZE 100
using namespace std;
string post = "";

class Stack{
    char stack[SIZE];
    int top;
    public:
    Stack(){
        top=-1;
        }
    bool stackisfull(){
        return top == SIZE -1 ;
    }
    bool stackempty(){
        return top==-1;
    }
    void push(char element){
        if(!stackisfull()){
        top++;
        stack[top]=element;
        // cout<<"You have pushed "<<stack[top]<< " in the stack"<<endl;
        }
    else{
        cout<<"Stack is full"<<endl;
        }
    }
    char pop(){
        if(!stackempty()){
            // cout<<"Popped element is "<<stack[top]<<endl;
            return stack[top--];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return '\0';
        }
    }
    char peek(){
        return stack[top];
    }
};
void print(){
    int i=0;
    cout<<"The equivalent postfix expression is ";
    while(post[i]!='\0'){
        cout<<post[i++];
    }
    // for(char ch:post){
    //     cout<<ch;
    // }

}
int precedence(char symbol){
    switch (symbol)
    {
    case '^':
        return 3;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '-':
    case '+':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
void inToPost(Stack& s, string& infix){
    char top;
    int j=0;
    for(char ch: infix){
        switch(ch){
            case '(':
                s.push(ch);
                break;
            case ')':
                while((top=s.pop()) != '('){
                    post[j++] = top;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!s.stackempty() && (precedence(s.peek()) >= precedence(ch))){
                    post[j++] = s.pop();
                }
                s.push(ch);
                break;
            default:
            post[j++]=ch;
            break;
        }
    }
    while(!s.stackempty()){
        post[j++]=s.pop();
    }
    post[j++]='\0';
} 

int main(){
    Stack s;
    string infix="a*b+c/d^e";
    inToPost(s,infix);
    print();
    return 0;
    }

