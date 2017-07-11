#include<iostream>
using namespace std;
struct node{
	int data;
	node* link;
};
node* createNode(int);
node* addToHead(node*,int);
node* addToTail(node*,int);
node* deleteTail(node*);
node* deleteHead(node*);
void printAll(node*);
int main(){
	node* head = NULL;
	head=addToHead(head,10);head=addToHead(head,15);
	head=addToHead(head,14);head=addToHead(head,25);
	head=addToTail(head,-15);head=addToTail(head,-10);
    printAll(head); cout<<endl;
    head=deleteTail(head); head = deleteHead(head);
	printAll(head);
	return 0;
}
node* createNode(int data){
	node* newNode = new node;
	newNode->link = NULL; newNode->data = data;
	return newNode;
}
node* addToHead(node* head, int data){
	node* newNode = createNode(data);
	if(head==NULL){
		head= newNode;
		return head;
	}
	newNode->link = head;
	head = newNode;
	return head;
}
void printAll(node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->link;
	}
}
node* addToTail(node* head, int data){
    node* newNode = createNode(data);
    node* traverse = head;
    if(head==NULL){
        head = newNode;
        return head;
    }
    while(traverse->link!=NULL){traverse= traverse->link;}
    traverse->link = newNode;
    return head;
}
node* deleteTail(node* head){
    node* current = head;
    node* prev = head;
    if(head==NULL){
        return head;
    }
    while(current->link!=NULL){
        prev=current;
        current= current->link;
    }
    prev->link=NULL;
    delete current;
    return head;
}
node* deleteHead(node* head){
    node* current = head;
    if(head==NULL){
        return head;
    }
    head = current->link;
    delete current;
    return head;
}
