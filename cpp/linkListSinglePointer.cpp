#include<iostream>
using namespace std;
struct node{
	int data;
	node* link;
};
node* createNode(int);
node* addToHead(node*,int);
void printAll(node*);
int main(){
	node* head = NULL;
	head=addToHead(head,10);head=addToHead(head,15);
	head=addToHead(head,14);head=addToHead(head,25);	
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