#include<bits/stdc++.h>
using namespace std;
class Queue{
    int rear,front;
    int size;
    int arr[5];
public:    Queue(){
        front = rear =-1;
        size = 5;
    }

    void enQueue(int value){
        if((front==0 && rear ==size-1)||(rear == front-1)){
            cout<<"Overflow"<<endl;
            return;
        }
        else if(front == -1){
            front = rear =0;
            arr[rear]=value;
        }
        else if(rear == size-1 && front !=0){
            rear =0;
            arr[rear]=value;
        }
        else {
            rear++;
            arr[rear]=value;
        }
    }
    void deQueue(){
        if(front==rear){
            cout<<"UnderFlow";
        }
        else if(rear==size-1){
            cout<<arr[rear]<<"  ";
        }
        else{
            cout<<arr[rear]<<"  ";
            rear--;
        }
    }
    void printAll(){
        if(front<rear){
         for(int i=front;i<=rear;i++)
            cout<<arr[i]<<"  ";
        }
        else{
        for(int i=front;i<size-1;i++)
            cout<<arr[i]<<"  ";
        for(int i=0;i<rear;i++)
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }

};
int main(){
    Queue q;
    q.enQueue(10);q.enQueue(20);q.enQueue(30);q.enQueue(40);
    q.printAll();
    q.deQueue();q.deQueue();cout<<endl;
    q.printAll();
    q.enQueue(10);q.enQueue(20);q.enQueue(30);q.enQueue(40);
    q.deQueue();cout<<endl;
    q.printAll();
}
