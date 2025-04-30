//Program to implement round robin scheduling
#include<cstdio>
#include"cir_link.h"
#include<cstdlib>
cir_link::cir_link(){
    head=NULL;
}
void insert(int,cir_link& );
void execute(int,cir_link& );
int main(){
    cir_link obj;
    int choice;
    int num;
    int slot=0;
    printf("enter the time slot\n");
    scanf("%d", &slot);
    do{
        printf("\nMENU\n");
        printf("1.Insert\n2.Execute\n3.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted:\n");
                scanf("%d",&num);
                insert(num,obj);
                break;
            case 2:
                execute(slot,obj);
                break;
            case 3:
                printf("Exiting the program...\n");
        }
}while(choice!=3);
}
void insert(int num, cir_link& obj)
{
    obj.cir_link::insert_at_end(num);
    obj.cir_link::display();
}

void execute(int slot, cir_link& obj)
{
    int x = obj.gethead();
    if (x != 0)  
    {
        int ret = obj.delete_at_beg();  
        if (ret != -1)  
        {
            ret = ret - slot;
            if (ret <= 0)  
            {
                printf("Operation was successful\n");
                obj.cir_link::display();
            }
            else  
            {
                obj.insert_at_end(ret);
                printf("Operation was successful\n");
                obj.cir_link::display();
            }
        }
    }
    else  
    {
        obj.cir_link::display();
        printf("The Queue is empty\n");
    }
}

