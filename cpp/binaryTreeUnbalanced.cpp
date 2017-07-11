#include<iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
node *createNode(int);
node *addNode(node*,int);
void printAll(node*);
int main(void){
    node* head = NULL;
    head = addNode(head,10);
    printAll(head);
    return 0;
}
node *createNode(int data){
    node* newNode = new node;
    newNode->data = data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
node *addNode(node *head,int data){
    node* newNode = createNode(data);
    if(head==NULL){
        head = newNode;
        return head;
    }
    //
}
void printAll(node *head){
    if(head==NULL)
        return;
    printAll(head->left);
    cout<<head->data;
    printAll(head->right);
}
