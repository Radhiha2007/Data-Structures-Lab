//Program to implement singly linked list using List ADT
#include<cstdio>
#include<cstdlib>
class sll{
struct node{
int data;
struct node*next;
}*head;
public:
sll(){
head=NULL;
}
void insert_at_beg(int);
void insert_at_end(int);
void display();
void insert_at_pos(int,int);
void search(int);
void delete_at_beg();
void delete_at_end();
void reverse_link();
void display_rev();
void delete_at_pos(int);
};
int main(){
sll obj;
int choice,num,pos;
do{
printf("MENU\n");
printf("1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n");
printf("7.Search\n8.Display\n9.Reverse link\n10.Display Reverse\n");
printf("11.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);

switch(choice){
case 1:
    obj.insert_at_beg(num);
    break;
case 2:
    obj.insert_at_end(num);
    break;
case 3:
    obj.insert_at_pos(num,pos);
    break;
case 4:
    obj.delete_at_beg();
    break;
case 5:
    obj.delete_at_end();
    break;
case 6:
    obj.delete_at_pos(pos);
    break;
case 7:
    obj.search(num);
    break;
case 8:
    obj.display();
    break;
case 9:
    obj.reverse_link();
    break;
case 10:
    obj.display_rev();
    break;
case 11:
    printf("\nYou have pressed option 11: THANK YOU\n");
    break;
}
}while(choice!=11);
}
//Function to insert at beginning
void sll:: insert_at_beg(int num){
printf("Enter the number to be inserted at the beginning:\n");
scanf("%d",&num);
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=num;
if(head==NULL){
newnode->next=NULL;
head=newnode;
}
else{
//newnode->data=num;
newnode->next=head;
head=newnode;
}
printf("The node %d is inserted successfully\n",num);
}
//Function to insert at end
void sll::insert_at_end(int num){
if(head==NULL){
insert_at_beg(num);
}
else{
printf("Enter the number to be inserted at the end:\n");
scanf("%d",&num);
struct node*curr=head;
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=num;
while(curr->next!=NULL){
curr==curr->next;
}
curr->next=newnode;
newnode->next=NULL;
printf("the number %d is inserted at the end\n",num);
}
}
//Function to insert at position
void sll::insert_at_pos(int pos,int num){
printf("Enter the position:\n");
scanf("%d",&pos);
if(pos<=0){
printf("Invalid position\n");
}
else if(pos==1){
insert_at_beg(num);
}
else{
struct node*temp=head;
for(int i=2;i<pos-1&&temp!=NULL;i++){
temp=temp->next;}
if(temp==NULL){
insert_at_end(num);
}
else{
printf("Enter the number to be inserted:\n");
scanf("%d",&num);
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=num;
newnode->next=temp->next;
temp->next=newnode;

}
}
}
//Function to implement deletion at beginning
void sll:: delete_at_beg(){
if(head==NULL){
printf("The list is empty\n");
}
else{
struct node*temp=head;
head=temp->next;
free(temp);
}
}
//Function to implement deletion at end
void sll::delete_at_end(){
if(head==NULL){
printf("The list is empty\n");
}
else{
struct node*temp=head;
while(temp->next->next!=NULL){
temp=temp->next;
}
temp->next=NULL;

}
}
//Function to implement delete at position
void sll::delete_at_pos(int pos) {
    printf("Enter the position to be deleted:\n");
    scanf("%d",&pos);
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (pos == 1) {
        delete_at_beg();
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct node* node = temp->next;
    temp->next = temp->next->next;
    free(node); 
}

//Function to implement search function
void sll::search(int num){
if(head==NULL){
printf("The list is empty\n");
}
else{
printf("Enter the number to be searched:\n");
scanf("%d",&num);
struct node*temp=head;
while(temp!=NULL){
if(temp->data==num){
printf("The number is found\n");
return;
}temp=temp->next;
}printf("The element is not found\n");
}
}
//Function to implement display
void sll::display(){
if(head==NULL){
printf("The list is empty\n");
}
else{
struct node*temp=head;
while(temp!=NULL){
printf("%d ->",temp->data);
temp=temp->next;
} printf("NULL\n");
}
}
//Function to implement reverse link
void sll::reverse_link(){
if(head==NULL){
printf("The list is empty\n");
return;
}
struct node*curr=head;
struct node*prev=NULL;
struct node*temp=NULL;
while(curr!=NULL){
temp=curr->next;
curr->next=prev;
prev=curr;
curr=temp;
}head=prev;
}
//Function to implement display reverse
void sll::display_rev(){
reverse_link();
display();
reverse_link();
}
