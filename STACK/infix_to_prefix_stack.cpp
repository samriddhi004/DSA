// /*
// exp = (a+b)*c-d+f
// step1: reverse the exp: f+d-c*(b+a)
// step2: same as postfix

// */
#include <iostream>
#include <string>
#include <algorithm>  // Add this line
#define SIZE 100
using namespace std;
string prefix = "";

class Stack {
    char stack[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }
    bool stackisfull() {
        return top == SIZE - 1;
    }
    bool stackempty() {
        return top == -1;
    }
    void push(char element) {
        if (!stackisfull()) {
            top++;
            stack[top] = element;
        } else {
            cout << "Stack is full" << endl;
        }
    }
    char pop() {
        if (!stackempty()) {
            return stack[top--];
        } else {
            cout << "Stack is empty" << endl;
            return '\0';
        }
    }
    char peek() {
        return stack[top];
    }
};

void print() {
    cout << "The equivalent prefix expression is "<<prefix;
}

int precedence(char op) {
    switch (op) {
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

void inToPre(Stack& s, string infix) {
     cout << "Before reversal: " << infix << endl;
    reverse(infix.begin(), infix.end());
    cout << "After reversal: " << infix << endl;
    // reverse(infix.begin(), infix.end());

    for (char& ch : infix) {
        if (ch == '(') {
            ch = ')';
        } else if (ch == ')') {
            ch = '(';
        }
    }

    int j = 0;
    char top;

    for (char ch : infix) {
        switch (ch) {
            case '(':
                s.push(ch);
                break;
            case ')':
                while ((top = s.pop()) != '(' && !s.stackempty()) {
                    prefix += top;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!s.stackempty() && (precedence(s.peek()) > precedence(ch))) {
                    prefix += s.pop();
                }

                s.push(ch);
                break;
            default:
                prefix += ch;
                break;
        }
    }

    while (!s.stackempty()) {
        prefix += s.pop();
    }
    reverse(prefix.begin(), prefix.end());
}


int main() {
    Stack s;
    string infix = "a*b+c/d";
    inToPre(s, infix);
    print();
    return 0;
}
