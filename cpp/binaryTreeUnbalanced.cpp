#include<iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
node *createNode(int);
node *addNode(node*,int);
void printPostOrder(node*);
void printPreOrder(node*);
void printInOrder(node*);
int main(void){
    node* head = NULL;
    head = addNode(head,10);head = addNode(head,03);
    head = addNode(head,0);head = addNode(head,30);
    printInOrder(head);cout<<endl;
    printPreOrder(head);cout<<endl;
    printPostOrder(head);cout<<endl;
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
    if(data <= head->data ){
        head->left=addNode(head->left,data);
    }
    else {
        head->right=addNode(head->right,data);
    }
}
void printInOrder(node *head){
    if(head==NULL)
        return;
    printInOrder(head->left);
    cout<<head->data<<" ";
    printInOrder(head->right);
}
void printPreOrder(node *head){
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    printPreOrder(head->left);
    printPreOrder(head->right);
}
void printPostOrder(node *head){
    if(head==NULL)
        return;
    printPostOrder(head->left);
    printPostOrder(head->right);
    cout<<head->data<<" ";
}
