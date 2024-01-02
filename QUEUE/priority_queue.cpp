/*
fifo data structure--serves elements with the highest
priority first before elements with lower priorities
* Task scheduling in operating systems.
* Dijkstra's algorithm for finding the shortest path in a graph.
* Huffman coding for data compression.
* A* algorithm in pathfinding.
* Job scheduling in parallel processing.
* Network routing algorithms.*/
#include <iostream>
class Node{
    public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p): data(d),priority(p),next(nullptr){}
};

class PriorityQueue{
    private: Node* front;
    public:
    PriorityQueue() : front(nullptr){}

    void enqueue(int data, int priority){
        Node* newNode = new Node(data, priority);
        if(!front || priority > front->priority){
            newNode->next = front;
            front = newNode;
        }
        else{
            //need to find the correct pos to insert element
            Node* temp = front;
            while(temp->next && temp->next->priority > priority){
                temp = temp->next;
            }
            //temp is the new front basically at the lasttt position
            // 7 elements, needs to be inserted in after 5th pos, temp= 5th pos
            // temp->next => (6th elemnt) now needs to be new node 
            newNode->next = temp->next; // o_o_0_o_o
            temp->next = newNode;       // o_o_o_o_o
        }
    }
    
    int dequeue(){
        if(!front){
            std::cout<<"Empty priority queue"<<std::endl;
            return 0;
        }
        Node* temp = front;
        int data = temp->data;
        front = front->next;
        delete temp;

        return data;
    }

    bool isEmpty(){ return front == nullptr;}

};

int main(){
    PriorityQueue pq;
    pq.enqueue(5,2);
    pq.enqueue(3, 1);
    pq.enqueue(8, 3);
    pq.enqueue(1, 2);

    while(!pq.isEmpty()){
        std::cout<< pq.dequeue()<<" ";
    }
    return 0;
}