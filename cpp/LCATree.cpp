#include<bits/stdc++.h>
using namespace std;
struct Tree{
    int data;
    Tree *left,*right;
};
Tree* addTree(Tree *t,int value){
    Tree *newNode = new Tree;
    newNode->data=value;newNode->left=newNode->right=NULL;
    if(t==NULL){
        t= newNode;
    }
    else if(t->data > value){
        t->left = addTree(t->left,value);
    }
    else{
        t->right = addTree(t->right,value);
    }
    return t;
}
void printInorder(Tree *t){
    if(t==NULL)
        return;
    printInorder(t->left);
    cout<<t->data<<" ";
    printInorder(t->right);
}
bool findPath(Tree*t, vector<int> &path, int value ){
    if(t==NULL){
        return false;
    }
    path.push_back(t->data);
    if(t->data == value)
        return true;
    if((t->left&&findPath(t->left,path,value)) || (t->right&&findPath(t->right,path,value))){
        return true;
    }
    path.pop_back();
    return false;

}
int findLCS(Tree *t,int value1,int value2){
    vector<int> path1,path2;

    if(!findPath(t,path1,value1)||!findPath(t,path2,value2))
        return -1;
    int i;
    for(i=0;i<path1.size()&&i<path2.size();i++)
        if(path1[i]!=path2[i])
            break;
    return path1[i-1];
}
int main(){
    Tree *t = new Tree;
    t=NULL;
    t=addTree(t,14);t=addTree(t,111);t=addTree(t,4);t=addTree(t,-1);t=addTree(t,34);t=addTree(t,64);
    t=addTree(t,124);t=addTree(t,101);t=addTree(t,21);t=addTree(t,-9);t=addTree(t,-4);t=addTree(t,24);
    printInorder(t);
    cout<<endl<<findLCS(t,64,124);
    return 0;
}
