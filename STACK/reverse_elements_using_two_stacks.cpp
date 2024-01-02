#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node* next_addr;
        node(int val){
            data = val;
            next_addr = NULL;
        }    
};
class stack{
    node* top_addr;
    int length;
    public:
    stack(){
        top_addr = NULL;
        length=0;        // just to know the no. of elements
    }
    bool isEmpty() const {
        return top_addr == nullptr;
    }
    void push(int x){
        length++;
        node* new_node_addr = new node(x);
        //new_node_addr points to the newly created node
        new_node_addr->next_addr = top_addr;
        // new_node_addr points to a node and is not a node in itself
        // through this pointer tho, one can access members of the node object.
        top_addr = new_node_addr;
    }
    void print(){
        node* temp;
        temp = top_addr;
        cout<<"The stack elements are ";
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next_addr;
        }
        cout<<endl;
    }
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Top element is "<<top_addr->data<<endl;
        }
    }
    int pop(){
        if (isEmpty()) {
            cerr << "Stack underflow" << endl;
            return -1; // or any suitable value for underflow
        }
        node* temp;
        temp = top_addr;
        top_addr = temp->next_addr;
        int poppedval = temp->data;
        delete temp;
        length--;
        return poppedval;
    }
    void reverse(){
        stack s1,s2;
        while(!isEmpty()){
            s1.push(pop());
        }
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        while(!s2.isEmpty()){
            push(s2.pop());
        }   
    }
    ~stack() {
    while (!isEmpty()) {
        pop();
    }
}


};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.reverse();
    s.print();

    return 0;
}

