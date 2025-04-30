#include "tree.h" 
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
string postfix()
{
    string post;
    char temp[100];
    printf("enter a valid postfix expression: ");
    scanf("%99s", temp);
    post = temp;
    return post;
}
void consttree(string post, tree& obj) 
{
    obj.sethead(obj.exptree(post, NULL, '\0'));
}
int main()
{
    string post;
    int chc;
    tree obj; 
    do
    {
        printf("enter: \n\t 1. for entering postfix expression\n\t 2. construction of expression tree\n\t 3. inorder\n\t 4. preorder\n\t 5. postorder\n\t 6. exit\n");
        printf("enter the choice\n");
        scanf("%d",&chc);
        switch(chc)
        {
            case 1:
            {
                post=postfix();
                break;
            }
            case 2:
            {
                consttree(post, obj);
                break;
            }
            case 3:
            {
                obj.inorder(obj.gethead());
                printf("\n");
                break;
            }
            case 4:
            {
                obj.preorder(obj.gethead());
                printf("\n");
                break;
            }
            case 5:
            {
                obj.postorder(obj.gethead());
                printf("\n");
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("invalid Input\n");
            }
        }
    }while(1);
}
