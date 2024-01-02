#include<iostream>
#define SIZE 5
using namespace std;
class Queue{
    private:
    int rear,front;
    int que_arr[SIZE];
    public:
    Queue(){
        rear= -1;
        front=-1;
        }
    bool isEmpty(){
        return front==-1 && rear==-1;
    }
    bool isFull(){
        return rear==SIZE -1;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<" Queue full ";
            return;
        }
        else if(isEmpty()){
            front = 0;
        }
        que_arr[++rear]=val;
        cout<<"varkhar queued "<<que_arr[rear]<<endl;

    }
    int dequeue(){
        if(isEmpty()){
            return 0;
        }
        else if(front==rear){
            int x=que_arr[front];
            front = rear =-1;
            return x;
        }
        else{
            return que_arr[front++];
        }
    }
};
int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    cout<<q.dequeue();

    
}