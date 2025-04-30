//Code to implement queue using linked lists
#include<cstdio>
#include<cstdlib>
class queue_ll{
    struct node{
    int data;
    struct node*next;
    }*head;
private:
    node* front; 
    node* rear;
public:
    queue_ll(){
        front = rear = NULL;
    }
void enqueue(int);
void dequeue();
void peek();
};
int main(){
    queue_ll obj;
    int choice,data;
    do{
    printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
    printf("Enter your choice:");
scanf("%d",&choice);

switch(choice){
case 1:
    printf("Enter the value to be inserted:\n");
    scanf("%d",&data);
    obj.enqueue(data);
    printf("The number %d is inserted",data);
    break;
case 2:
    obj.dequeue();
    break;
case 3:
    obj.peek();
    break;
case 4:
    printf("Exiting the program\n");
    break;
}
    }while(choice!=4);
}
void queue_ll::enqueue(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }    
    newnode->data=data;
    newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode;
    }
    rear->next=newnode;
    rear=newnode;
}
void queue_ll::dequeue(){
    if(front==NULL){
        printf("The queue is empty\n");
    }
    struct node *temp=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
        }
    
    free(temp);
}
void queue_ll::peek(){
    if(front==NULL){
        printf("The queue is empty\n");
        return;
    }
    printf("The top element is %d\n",front->data);
}

