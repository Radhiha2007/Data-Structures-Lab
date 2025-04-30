//Code to implement circular queue adt
#include<cstdio>
class cir_queue{
    private:
        int arr[5];
        int front;
        int rear;
    public:
        cir_queue(){
            front=-1;
            rear=-1;
        }
void enqueue(int);
void dequeue();
void peek();
void display();
};
int main(){
    cir_queue obj;
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
void cir_queue::enqueue(int value){
    if((rear +1)% 5==front){
        printf("The queue is full\n");
        return;
    }
    else if(front ==-1 && rear==-1){
        front =0;
    }
    rear=(rear+1)%5;
    arr[rear]=value;
    
}
void cir_queue::dequeue(){
    if(front==-1){
        printf("The list is empty\n ");
        return;
    }
    else if(front ==rear) {
        front=-1;
        rear=-1;
    }
    front=(front+1)%5;
}
void cir_queue::peek() {  
    if (front == -1 || front > rear) { 
        printf("The list is empty\n");
        return; 
    }
    printf("The topmost element is: %d\n", arr[front]); 
}
void cir_queue::display(){
    if(front==-1){
        printf("The list is empty\n");
    }
    for (int i = front; ; i = (i + 1) % 5) {
        printf("%d ", arr[i]);
        if (i == rear) break; 
    }
    printf("\n");
}
