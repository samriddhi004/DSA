#include<iostream>
#define SIZE 50
using namespace std;
class Stack{
    int stack[SIZE];
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
        // cout<<"You have pushed "<<stack[top]<< " in the stack"<<endl;
    }
    else{
        cout<<"Stack is full"<<endl;
    }
    }
    void pop(){
        if(!stackempty()){
            cout<<stack[top]<<"  ";
            top--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    void peek(){
        cout<<"Element at the top of the stack is "<<stack[top]<<endl;
    }
void prime_fact(int num){
    int k = num;
    int i =2;
    while(num!=1){
        while(num%i == 0){
            push(i);
            num = num/i;
        }
        i++;
    }
    printf("\nThe prime factors of %d in descending order are ",k);
    for(int j=0;j<=top+j;j++){
        pop();
    }
     
}
void print(){
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}
};

int main(){
    Stack s;
    s.prime_fact(1027);
    return 0;
}