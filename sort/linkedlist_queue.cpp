#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
    node* front;
    node* back;
    public:
    queue(){
        front =NULL;
        back =NULL;
    }
    void push(int x){     //pointer-variable = new data-type(value);
    node* n =new node(x); // initializes memory for node and returns to n 
    if(front==NULL){
        back = n;
        front = n;
        return;
    }
    back->next=n;   //pointer_name-> variable_name
    back=n;
    }

    void pop(){
        if(front==NULL){
            cout<<"queue overflow"<<endl;
            return;
        }
        node* todelete= front;
        front=front->next; 

        delete todelete;

    }
    int peek(){
        if(front==NULL){
            cout<<"no element in queue"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
    void displayqueue(){
        if(front==NULL){
            cout<<"empty queue"<<endl;
            return;
        }
        node* currnode = front;
        while(currnode!=NULL){
            cout<<  currnode->data;
            currnode = currnode->next;
        }

    }
    

};



int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.displayqueue();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty();
    return 0;
}