//Code to implement preorder,postorder and inorder using queue
#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
class tree{
private:
struct node{
char data;
struct node*left;
struct node*right;
}*root;
public:
tree(){
root=NULL;
}
void insert(char);
void inorder(node*);
void inorder_display();
void preorder(node*);
void preorder_display();
void postorder(node*);
void postorder_display();
int search(node*,char);
void search_display(char);
};
int main(){
tree obj;
int choice;
char value;
char key;
do{
printf("\nMENU\n\n1.Insert\n2.Inorder\n3.Preorder\n4.Postdorder\n5.Search\n6.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter the element to be inserted:\n");
scanf(" %c",&value);
obj.insert(value);
printf("The value %c is inserted",value);
break;
case 2:
obj.inorder_display();
break;
case 3:
obj.preorder_display();
break;
case 4:
obj.postorder_display();
break;
case 5:
printf("Enter the key:\n");
scanf(" %c",&key);
obj.search_display(key);
break;
case 6:
printf("Exiting the program\n");
break;
}
}while(choice!=6);
}
void tree::insert(char value){
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->left=newnode->right=NULL;
if(root==NULL){
root=newnode;
return;
}
queue <struct node*> q;
q.push(root);
while(!q.empty()){
struct node*temp=q.front();
q.pop();
if(temp->left==NULL){
temp->left=newnode;
return;
}
else{
q.push(temp->left);
}
if(temp->right==NULL){
temp->right=newnode;
return;
}
else{
q.push(temp->right);
}
}
}
void tree::inorder(struct node*root){
if(root!=NULL){
inorder(root->left);
printf("%c",root->data);
inorder(root->right);
}
}
void tree::inorder_display(){
inorder(root);
}
void tree::preorder(struct node*root){
if(root!=NULL){
printf("%c",root->data);
preorder(root->left);
preorder(root->right);
}
}
void tree::preorder_display(){
preorder(root);
}
void tree::postorder(struct node*root){
if(root!=NULL){
postorder(root->left);
postorder(root->right);
printf("%c",root->data);
}
}
void tree::postorder_display(){
postorder(root);
}
int tree::search(struct node* root, char key) {
if (root == NULL) {
return 0;
}
if (root->data == key) {
return 1;
}

int left = search(root->left, key);
if (left) {
return 1;
}

return search(root->right, key);
}

// Function to display the result of the search
void tree::search_display(char key) {
int display = search(root, key);
if (display == 1) {
printf("Key found\n");
} else {
printf("Key not found.\n");
}
}
