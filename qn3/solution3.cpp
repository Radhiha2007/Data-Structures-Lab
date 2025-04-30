#include<cstdio>
#include<cmath>
#include<stdlib.h>
int digits(int *num){
int *digits;
digits=(int*)malloc(sizeof(int));
while((*num)>0){
(*num)/=10;
(*digits)++;
}
return *digits;
}
void sum(int *num){
int *temp=(int*)malloc(sizeof(int));
*temp=*num;
int *original;
original=(int*)malloc(sizeof(int));
int *sum=(int*)malloc(sizeof(int));
*sum=0;
*original=*num;
printf("%d\n",*original);
int result=digits(num);
while((*original)>0){
int *rem;
rem=(int*)malloc(sizeof(int));
*rem=(*original)%10;
*sum +=pow(*rem,result);
(*original)/=10;
free(rem);
}
if(*sum == *temp){
printf("It is an armstrong number\n");
}
else{
printf("It is not a armstrong number\n");
}}
//program for pallindrome
int ori_num(int *number){
    int *reversed_num=(int*)malloc(sizeof(int));
    int *remainder=(int*)malloc(sizeof(int));
    int *re=(int*)malloc(sizeof(int));
    *re=*number;
    int *temp=(int*)malloc(sizeof(int));
    *temp=*number;
    while((*temp)>0){
    *remainder=(*temp)%10;
    *reversed_num=(*reversed_num)*10+(*remainder);
    (*temp)/=10;}
    if(*reversed_num ==*re){
        printf("It is an pallindrome\n");
        }
    else{
        printf("it is not a pallindrome\n");
        }
        return *reversed_num;
}
//program for perfect number
void perfect_number(int *value){
    int *sum;
    sum=(int*)malloc(sizeof(int));
    *sum=0;
    int *i=(int*)malloc(sizeof(int));
    for(*i=1;(*i)<(*value);(*i)++){
        if((*value)%(*i)==0){
            *sum+=*i;
            printf("The sum:%d\n",*sum);
        }
    }
     if(*sum==*value){
         printf("It is a perfect number\n");
     }  
     else{
         printf("It is not a perfect number\n");
     }
    
}
int main(){
int choice;
do{
printf("Menu...\n");
printf("1.Armstrong Number\n");
printf("2.Pallindrome\n");
printf("3.Perfect Number\n");
printf("4.Exit...BYEBYE\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice){
    case 1:
        int *num;
         num=(int*)malloc(sizeof(int));
         printf("Enter the number:\n");
         scanf("%d",num);
         sum(num);
        break;
    case 2:
        int *number;
        number=(int*)malloc(sizeof(int));
        printf("Enter the number:\n");
        scanf("%d",number);
        int *result;
        result=(int*)malloc(sizeof(int));
        *result=ori_num(number);
         printf("The reversed number is :%d\n",*result);
        break;
    case 3:
        int *num2;
        num2=(int*)malloc(sizeof(int));
        printf("Enter the number to check whether it is perfect or not:\n");
        scanf("%d",num2);
        perfect_number(num2);
        break;
    case 4:
        printf("Exiting the program.....Bye Bye <3\n");
        break;
    default:
        printf("Invalid choice\n");

}
}
while(choice!=4);
}
