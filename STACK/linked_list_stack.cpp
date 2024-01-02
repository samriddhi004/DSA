/*
Why prefer linkedlist implementation instead of array
- We don't know the exact size of the elements on stack(on array we need to know)

Why prefer beginning of linked list at TOS?
- Time complexity is O(1) adding at the end of node or the start.
- BUT time complexity of removing the last node is O(n)
 **requires traversal**

*/
#include<iostream>
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
        if(top_addr==NULL){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Top element is "<<top_addr->data<<endl;
        }
    }
    void pop(){
        node* temp;
        temp = top_addr;
        top_addr = temp->next_addr;
        delete temp;
    }

};
int main(){
    stack s;
    s.push(1);
    s.push(10);
    s.push(100);
    s.print();
    s.pop();
    s.print();
    s.peek();
    return 0;
}
