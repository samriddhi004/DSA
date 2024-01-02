#include<iostream>
#define SIZE 4
using namespace std;
class CircularQueue{
    private:
    int rear,front;
    int que_arr[SIZE];
    public:
    CircularQueue(){
        rear= -1;
        front=-1;
        }
    bool isEmpty(){
        return front==-1 && rear==-1;
    }
    bool isFull(){
        return (rear+1)%SIZE==front; //IF REAR<FRONT ie also full queue
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"Queue full. Cannot enqueue"<<endl;
            return;
        }
        else if(isEmpty()){
            front = 0;
        }
        rear = (rear+1)%SIZE;
        que_arr[rear]=val;
        cout<<"varkhar enqueued "<<que_arr[rear]<<endl;

    }
    int dequeue(){
        int x;
        if(isEmpty()){
            return 0;
        }
        else if(front==rear){
            x=que_arr[front];
            front = rear =-1;
            return x;
        }
        else{
            x = que_arr[front];
            front = (front+1)%SIZE;
        }
        return x;
    }
    void display(){
        cout<<"The elements of queue are: ";
        for(int i =0;i<SIZE;i++){
            cout<<que_arr[i]<<" ";
        }
    }
};
int main(){
    CircularQueue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(9);
    q.enqueue(7);
    q.enqueue(8);
    q.display();
}