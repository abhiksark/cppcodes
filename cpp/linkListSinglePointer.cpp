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
	node *head = NULL;
	head=addToHead(head,10);
	return 0;
}
node* createNode(int data){
	node newNode = new Node;
	newNode->link = NULL; newNode->data = data;
	return newNode;
}
node* addToHead(node* head, int data){}
