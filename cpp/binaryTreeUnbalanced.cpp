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
int findNode(node*,int);
node* findMin(node*);
node* deleteNode(node*, int);
int main(void){
    node* head = NULL;
    head = addNode(head,10);head = addNode(head,03);
    head = addNode(head,0);head = addNode(head,30);
    head = addNode(head,80);head = addNode(head,13);
    head = addNode(head,7);head = addNode(head,06);
    printInOrder(head);cout<<endl;
    //printPreOrder(head);cout<<endl;
    //printPostOrder(head);cout<<endl;
    head =deleteNode(head,30);
    printInOrder(head);cout<<endl;
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
int findNode(node* head,int data){
    if(head==NULL)
        return -1;
    if(data == head->data)
        return data;
    if(data < head->data)
        return findNode(head->left,data);
    if(data> head->data) 
        return findNode(head->right,data);
}
node *findMin(node* head){
    while(head->left!=NULL){
        head = head->left;
    }
    return head;

}
node* deleteNode(node* head, int data){
    
    if(head==NULL)
        return head;
    else if(data < head->data)
        head = deleteNode(head->left,data);
    else if(data> head->data) 
        head = deleteNode(head->right,data);

    else{    // found the child 
        if(head->left==NULL && head->right == NULL){ //no child 
            delete head;
        }
        else if(head->left==NULL){ //no left child
            head = head->right;
        }
        else if(head->right == NULL){ //no right child
            head = head->left;
        }
        else{
            node* temp = findMin(head->right);
            head->data = temp->data;
            head->right = deleteNode(head->right,temp->data);
        }

    }

    return head;
}