#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
class Queue{
    public: Node *front,*rear;
};
void enQueue(Queue *q, int value ){
    Node *newNode = new Node;
    newNode->data = value; newNode->next=NULL;
    if(q->front== NULL){
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next =newNode;
    q->rear = newNode;
}
int deQueque(Queue *q){
    if(q->front==NULL){
        cout<<"Underflow";
        return INT_MIN;
    }
    if(q->front==q->rear){
        int value;
        value=q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
        return value;
    }
    int value;
    Node *temp = new Node;
    value=q->front->data;
    temp= q->front;
    q->front = q->front->next;
    free(temp);
    return value;
}
void displayQueue(Queue *q){
    Node *temp = q->front;
    cout<<"\nElements in Circular Queue are: ";
    while (temp->next!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
}
int main(){
    Queue *q = new Queue;
    q->front=q->rear = NULL;
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);
    displayQueue(q);
    cout<<endl<<deQueque(q);
    cout<<endl<<deQueque(q);
    enQueue(q, 5);
    enQueue(q, 10);
    displayQueue(q);
    cout<<endl<<deQueque(q);
    enQueue(q, 6);
    enQueue(q, 90);
    displayQueue(q);
    return 0;
}
