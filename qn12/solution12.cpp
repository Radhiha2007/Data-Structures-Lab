//Code to implement stack functions using list adt 
#include<cstdio>
class stack_list{
private:
    int top;
    int arr[5];

public:
    stack_list(){
        top=-1;
    }
void push(int);
void pop();
void peek();
};
int main(){
    stack_list obj;
    int element;
    int choice;
    do{
    printf("\nMENU\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
    printf("ENTER YOUR CHOICE:\n");
    scanf("%d",&choice);
    
        switch(choice){           
            case 1:
                printf("Enter the element to be pushed into the stack:\n");
                scanf("%d",&element);
                obj.push(element);
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
//Function to push
void stack_list::push(int element){
    if(top==4){
        printf("Stack overflow\n");
    }
    else{
        arr[++top]=element;
        printf("The element which is added to the stack is %d\n",arr[top]);
    }
}
//Function to pop
void stack_list::pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
       int pop_element= arr[top--];
       printf("The element which is deleted from the stack is %d\n",pop_element);
    }
}
//Function to peek
void stack_list::peek(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("The top element in the array is:%d",arr[top]);
    }
}
