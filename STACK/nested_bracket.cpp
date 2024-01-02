// checking the validity of the expression containing nested brackets
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
using namespace std;
class Stack{
    int stack[5];
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
            top--;
            return stack[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return;
        }
    }
    char peek(){
        // cout<<"Element at the top of the stack is "<<stack[top]<<endl;
        return stack[top];
    }
};
int check_balance(Stack& s,string& expr){
    for(char ch: expr){
        if(ch == '(' || ch== '{'|| ch == '['){
            s.push(ch);
        }
        else if(ch == ')' || ch== '}'|| ch == ']'){
            if(s.stackempty()){
                cout<<"Right brackets are more than left brackets";
                return 0; // UNBALANCED
            }
            char oBracket = s.pop();

            if((ch == ')' && oBracket != '(') ||
               (ch == '}' && oBracket != '{') ||
               (ch == ']' && oBracket != '[')){
                return 0; //UNBALANCED
               }
        }
    }
    return s.stackempty() ? 1 : 0 ;
}
int main(){
    Stack s;
    string expr;
    cout<<"Enter algebraic expression: "<<endl;
    cin>>expr;
    int balance = check_balance(s,expr);
    if (balance) {
        cout << "Expression is balanced." << endl;
    } else {
        cout << "Expression is not balanced." << endl;
    }

    return 0;


}
