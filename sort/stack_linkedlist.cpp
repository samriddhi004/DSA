#include <iostream>
using namespace std;
class node{
    private:
    public:
    int data;
    node* previous;
    node(int val ){
        data =val;
        previous = NULL;
    }
};
class stack{
    private:
    public:
        node* top;
        int length;
        stack(){
            top=NULL;
            length=0;
        }
        void peek(){
            if(top==NULL){
                cout<<"stack empty"<<endl;
            }
            cout<<top->data<<endl;
        }
        void push(int x){
            length++;
            node* n = new node(x);
            if(top==NULL){
                top =n;
                return;
            }
            n->previous=top;
            top=n;
            
        }
        void pop(){
                if(top==NULL){
                    cout<<"empty stack"<<endl;
                    return;
                }
                node* todelete = this->top;
                top = top->previous;
                delete todelete;
                length--;
        }
        void isempty(){
            if((top==NULL)){
            cout<<" empty stack"<<endl;}
            else{
                cout<<"stack isn't empty"<<endl;
            }
        }
        void displaystack(){
            node* curr = top;
            while(curr!=NULL){
                cout<<curr->data<<endl;
                curr= curr->previous;
            }
            cout<<"length of stack = "<<length<<endl;

        }
};


int main(){
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.displaystack();
    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.isempty();
    s1.displaystack();
    return 0;
}