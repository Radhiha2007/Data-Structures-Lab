//Code to implement queue adt
#include<cstdio>
class queue{
    private:
        int arr[5];
        int front;
        int rear;
    public:
        queue(){
            front=-1;
            rear=-1;
        }
void enqueue(int);
void dequeue();
void peek();
void display();
};
int main(){
    queue obj;
    int choice,value;
    do{
    printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
    printf("Enter your choice:");
scanf("%d",&choice);

switch(choice){
case 1:
    printf("Enter the value to be inserted:\n");
    scanf("%d",&value);
    obj.enqueue(value);
    printf("The %d number is inserted",value);
    break;
case 2:
    obj.dequeue();
    break;
case 3:
    obj.peek();
    break;
case 4:
    obj.display();
    break;
case 5:
    printf("Exiting the program\n");
    break;
}
    }while(choice!=5);
}
void queue::enqueue(int value){
    if(rear==4){
        printf("The queue is full\n");
    }
    else if(front ==-1 && rear==-1){
        front =0;
    }
    rear++;
    arr[rear]=value;
    
}
void queue::dequeue(){
    if(front==-1 && rear==-1||front>rear){
        printf("The list is empty\n ");
    }
    else if(front ==rear) {
        front=-1;
        rear=-1;
    }
    front++;
}
void queue::peek() {  
    if (front == -1 || front > rear) { 
        printf("The list is empty\n");
        return; 
    }
    printf("The topmost element is: %d\n", arr[front]); 
}
void queue::display(){
    if(front==-1 || front>rear){
        printf("The list is empty\n");
    }
    for(int i=front;i<=rear;i++){
        printf("%d\n",arr[i]);
    }
}
