//Program to implement two list and to do various operations
#include <cstdio>
#include <cstdlib>
#include "header.h"

listadt::listadt() 
{
    head = NULL;
}

struct listadt::node* listadt::gethead()
{
    return head;
}

int main() 
{
    int chc;
    listadt obj, obj1, obj2;
    do {
        printf("Enter: \n\t 1. for Inserting into list 1\n\t 2. for Inserting into list 2\n\t 3. for Merging\n\t 4. for Display\n\t 5. for Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("Enter the number to be inserted\n");
                scanf("%d", &num);
                if (obj1.insert_list1(num)) 
                {
                    printf("Insertion was successful\n");
                } else 
                {
                    printf("Insertion was unsuccessful\n");
                }
                break;
            }
            case 2: 
            {
                int num;
                printf("Enter the number to be inserted\n");
                scanf("%d", &num);
                if (obj2.insert_list2(num)) 
                {
                    printf("Insertion was successful\n");
                } else 
                {
                    printf("Insertion was unsuccessful\n");
                }
                break;
            }
            case 3:
                obj.merge_2(obj1,obj2);
                break;
            case 4:
                obj.display();
                return 0;
            case 5:
                return 0;
            default:
                printf("Invalid Input\n");
                break;
        }
    } while (chc < 4);
}
//function to insert list 1
int listadt::insert_list1(int num)
{
    return insert(num);
}
//function to insert list 2
int listadt::insert_list2(int num)
{
    return insert(num);
}
//Function to merge
void listadt::merge_2(listadt& obj1, listadt& obj2)
{
    return merge(obj1, obj2);
}
