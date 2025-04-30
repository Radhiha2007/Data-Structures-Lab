#include<cstdio>
class list{
    int arr[5];
    int num;
    int curr;
public:
    list(){
    curr=-1;
    };
    void insert_at_beg(int);
    void insert_at_end(int);
    void insert_at_pos(int,int);
    void delete_at_beg();
    void delete_at_end();
    void delete_at_pos(int);
    void search(int);
    void display(int);
    void rotate(int);
};
int main(){
    int choice;
    int pos,num;
    list obj;
do{
printf("\nMENU\n");
printf("1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n");
printf("7.Search\n8.Display\n9.Rotate\n");
printf("10.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
    printf("Enter the number to be inserted at the beginning:\n");
    scanf("%d",&num);
    obj. insert_at_beg(num);
    printf("The number is inserted successfully\n");
    break;
case 2:
    obj.insert_at_end(num);
    printf("The number is inserted successfully\n");
    break;
case 3:
    obj.insert_at_pos(num,pos);
    break;
case 4:
    obj.delete_at_beg();
    printf("The number is deleted successfully\n");
    break;
case 5:
    obj.delete_at_end();
    printf("The number is deleted successfully\n");
    break;
case 6:
    printf("Enter the position to delete:\n");
    scanf("%d",&pos);
    obj.delete_at_pos(pos);
    printf("the element deleted successfully\n");
    break;
case 7:
    printf("Enter the number to search:\n");
    scanf("%d",&num);
    obj.search(num);
    break;
case 8:
    obj.display(num);
    break;
case 9:
    obj.rotate(num);
    printf("The list is rotated successfully\n");
    break;
case 10:
    printf("You have chose option 10....Thank you\n");
    break;
default:
    printf("Invalid...Please Try again\n");
}
}
while(choice!=10);
}
void list::insert_at_beg(int num){
    if(curr==4){
    printf("The array is full\n");
    }
    if(curr==-1){
    arr[0]=num;
    curr=0;
    }
    for(int i=curr;i>=0;i--){
    arr[i]=arr[i-1];}
    arr[0]=num;
    curr ++;
}

void list :: insert_at_end(int num){
    if(curr==4){
    printf("The list is full\n");
}
    if(curr==-1){
    insert_at_beg(num);
    curr++;
}
    else{
    printf("Enter the number to be inserted at the end:\n");
    scanf("%d",&num);
    curr++;
    arr[curr]=num;
}
}
void list::insert_at_pos(int num,int pos){
    printf("Enter the position:\n");
    scanf("%d",&pos);
    if(curr==4 || pos<0||pos>4){
    printf("Invalid choice\n");
}
    else{
    printf("Enter the number:\n");
    scanf("%d",&num);
    for(int i=curr;i>=pos;i--){
    arr[i+1]=arr[i];
}
    arr[pos]=num;
    curr++;

}
}
void list:: delete_at_beg(){
    if(curr==-1){
    printf("The list is empty\n");
}
    for(int i=0;i<curr;i++){
    arr[i]=arr[i+1];
}
    curr--;

}
void list:: delete_at_end(){
    if(curr==-1){
    printf("the list is empty\n");
}
    curr--;
}
void list:: delete_at_pos(int pos){
    if(curr==-1||pos<0||pos>curr){
        printf("Invalid position\n");
    }
    for(int i=pos;i<curr;i++){
        arr[i]=arr[i+1];
        }
        curr--;
    
    
}
void list::search(int num){
    int count=0;
    if(curr==-1){
        printf("The list is empty:\n");
    }
    else{
        for(int i=0;i<=curr;i++){
            if(arr[i]==num){
                printf("The element is found at index:%d",i);
                count++;
            }
            if(count=0){
            
                printf("The element not found\n");
            }
        }
    }
}
void list:: display(int num){
   if(curr==-1){
    printf("The list is empty\n");
}
    else{
    for(int i=0;i<=curr;i++){
    printf("%d\n",arr[i]);
}
    printf("\n");
}
}
void list::rotate(int num){
    if (curr==-1)
{
    printf("The list is empty\n");
}
    else{
    for(int i = 0; i<num; i++)
{
    int temp=arr[curr];
    for(int j = curr; j>=0; j--)
{
    arr[j]=arr[j-1];
}
    arr[0]=temp;
}
}
}
