//Program to implement doubly linked list
#include<cstdio>
#include<cstdlib>
class dll{
private:
struct node{
int data;
struct node*prev;
struct node*next;
}*head,*tail;
public:
dll(){
head=NULL;
tail=NULL;
}
void insert_at_beg(int);
void insert_at_end(int);
void display();
void insert_at_pos(int,int);
void delete_at_beg();
void delete_at_end();
void delete_at_pos(int);
void search(int);
};
int main(){
dll obj;
int choice,num,pos;
do{
printf("\nMENU\n");
printf("1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n");
printf("7.Search\n8.Display\n");
printf("9.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);

switch(choice){
case 1:
    printf("Enter the number to be inserted at the beginning:\n");
    scanf("%d",&num);
    obj.insert_at_beg(num);
    break;
case 2:
    printf("Enter the number to be inserted at the end:\n");
    scanf("%d",&num);
    obj.insert_at_end(num);
    break;
case 3:
    printf("Enter the number:");
    scanf("%d",&num);
    printf("Enter the position:\n");
    scanf("%d",&pos);
    obj.insert_at_pos(num,pos);
    break;
case 4:
    obj.delete_at_beg();
    break;
case 5:
    obj.delete_at_end();
    break;
case 6:
    printf("Enter the position:\n");
    scanf("%d",&pos);
    obj.delete_at_pos(pos);
case 7:
    printf("Enter the number:");
    scanf("%d",&num);
    obj.search(num);
    break;
case 8:
    obj.display();
    break;
case 9:
    printf("\nYou have pressed option 9: THANK YOU\n");
}
}while(choice!=9);
}
//Function to insert at beginning
void dll::insert_at_beg(int num){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=NULL;
    if(head==NULL){
        newnode->next=NULL;
        tail=newnode;
        head=newnode;
    }
    else{
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    }
    printf("The number %d inserted successfully at the beginning..\n",num);
    }
//Function to display
void dll::display(){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d <->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
//Function to insert at end
void dll::insert_at_end(int num){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        insert_at_beg(num);
    }
    else{
        newnode->data=num;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
        printf("The number %d is successfully inserted at the end\n",num);
    }
}
//Function to insert at position
void dll::insert_at_pos(int num,int pos){
    if(pos<1){
        printf("The position is out of range.\n");
    }
    if(pos==1||head==NULL){
        insert_at_beg(num);
        return;
    }
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    struct node*temp=head;
    for(int i=1;i<pos-1&&temp!=NULL;i++){
        temp=temp->next;}
        if(temp==NULL){
        printf("Invalid\n");
        return;
    }
    if (temp->next == NULL)
    {
        insert_at_end(num);
    }
    else
    {
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
}
//Function to delete at beginning
void dll::delete_at_beg(){
    if(head==NULL){
        printf("The list is empty\n");
    }
    else{
        struct node*temp=head;
        if(head==tail){
        head=NULL;
        tail=NULL;
        }
    else{
    head=head->next;
    head->prev=NULL;
    }
    delete temp;
    }
    printf("The deletion is successfull");
    }
//Function to delete at end
void dll::delete_at_end(){
    if(head==NULL){
        printf("The list is empty\n");
    }
    else{
        struct node*temp=tail;
        if(head==tail){
        free(head);
        head=NULL;
        tail=NULL;
    }
    else{
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
    printf("The deletion is successfull at the end\n");
}
}
//Program to delete at a position
void dll::delete_at_pos(int pos){
    if(pos<1){
        printf("Position out of range\n");
        return;
    }
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    if(pos==1){
        if(head==tail){
            free(head);
            head=NULL;
            tail=NULL;
        }
        else{
            struct node*temp=head;
            head=head->next;
            head->prev=NULL;
            free(temp);
           
        }
        return;
    }
    struct node*temp=head;
    for(int i=1;i<pos-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid\n");
    }
    if(temp==tail){
        delete_at_end();
        return;
    }
    if(temp->prev!=NULL){
    temp->prev->next=temp->next;}
    if(temp->next!=NULL){
    temp->next->prev=temp->prev;}
    free(temp);
}
void dll::search(int num) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    int i = 1;
    bool found = false;
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == num) {
            printf("The element is found at index %d\n", i);
            found = true;
        }
        temp = temp->next;
        i++;
    }
    if (!found) {
        printf("The element is not found\n");
    }
}
