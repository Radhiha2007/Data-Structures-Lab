//Code to impelemt stack functions using singly linked list
#include<cstdio>
#include<cstdlib>
class stack_sll{
    struct node{
        int data;
        struct node*next;
    };node*top;
public:
    stack_sll(){
        top=NULL;
    }
    void push(int);
    void pop();
    void peek();
};
int main(){
    stack_sll obj;
    int num;
    int choice;
    do{
    printf("\nMENU\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
    printf("ENTER YOUR CHOICE:\n");
    scanf("%d",&choice);
    
        switch(choice){           
            case 1:
                printf("Enter the element to be pushed into the stack:\n");
                scanf("%d",&num);
                obj.push(num);
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                obj.peek();
                break;
            case 4:
                printf("Exiting the program....");
                break;
            default:
                printf("Invalid choice\n");
            }
        }while(choice!=4);
}
void stack_sll::push(int num){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Stack overflow\n");
        return;
    }
    newnode->data=num;
    newnode->next=top;
    top=newnode;
    printf("The element %d is pushed into the stack\n",num);
}
void stack_sll::pop(){
    if(top==NULL){
        printf("Stack underflow\n");
        return;
    }
    struct node*temp=top;
    printf("The deleted element is %d",temp->data);
    top=top->next;
    free(temp);
}
void stack_sll::peek(){
    if(top==NULL){
        printf("The list is empty\n");
        return;
    }
    printf("The top element of the stack is:%d",top->data);
}
