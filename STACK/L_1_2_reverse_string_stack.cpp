#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;
    char items[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(char item) {
        if (!isFull()) {
            items[++top] = item;
        } else {
            std::cerr << "Stack overflow\n";
        }
    }

    char pop() {
        if (!isEmpty()) {
            return items[top--];
        } else {
            std::cerr << "Stack underflow\n";
            return '\0';  // or any suitable value for underflow
        }
    }

    void reverseString(char* str) {
        // Push characters onto the stack
        for (char* p = str; *p != '\0'; ++p) {
            push(*p);
        }

        // Pop characters from the stack and replace in the input string
        for (char* p = str; *p != '\0'; ++p) {
            *p = pop();
        }
    }
};

int main() {
    Stack charStack;
    char str[] = "Dostoevsky";

    std::cout << "Original string: " << str << std::endl;

    // Call the reverseString function
    charStack.reverseString(str);

    std::cout << "Reversed string: " << str << std::endl;

    return 0;
}
