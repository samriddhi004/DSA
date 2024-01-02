#include <iostream>
#define SIZE 50
using namespace std;
class Stack{
    int stack[SIZE];
    int top;
    public:
    Stack():top(-1){};
    bool stackisfull(){
        return top == SIZE -1 ;
    }
    bool stackempty(){
        return top==-1;
    }
    void push(int element){
        if(!stackisfull()){
        top++;
        stack[top]=element;
        // cout<<"You have pushed "<<stack[top]<< " in the stack"<<endl;
    }
    else{
        cout<<"Stack is full"<<endl;
    }
    }
    void pop(){
        if(!stackempty()){
            cout<<stack[top];
            top--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
   
};
 void dec_to_bin(Stack& s,int num){
        int k =num;
        while(num!=0){
            s.push(num%2);
            num = num/2;
        }
    printf("\nThe binary equivalent of %d is ",k);
    while(!s.stackempty()){
        s.pop();
    }
    }
int main(){
    Stack s;
    int dec;
    cout<<"Enter decimal number: ";
    cin>>dec;
    dec_to_bin(s,dec); 
    return 0;
}