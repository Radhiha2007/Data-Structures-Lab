//Program to create a menu driven program to calculate area for cube,square,rectangle,cuboid
#include<iostream>

class area{
   private:
     int length;
     int breadth;
     int height;
   public:
    area(){
        length=1,breadth=1,height=1;
    }
    void setlength(int len){
        length=len;
     }
      void setbreadth(int bre){
       breadth=bre;
     }
      void setheight(int hei){
        height=hei;
     }
     int cube(int length){
           return length*length*length;
     }
     int cuboid(int length,int breadth,int height){
        return length*breadth*height;
     }
     int square(int length){
        return length*length;
     }
     int rectangle(int length,int breadth){
        return length*breadth;
     }

};
int main(){
    area obj;
    int choice;
    do{
        printf("\nMenu\n");
        printf("1.To find the area of the cube\n");
        printf("2.To find the area of the cuboid\n");
        printf("3.To find the area of the square\n");
        printf("4.To find the area of the rectangle\n");
        printf("5.Exit...\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
    switch(choice){
           case 1:
               int len;
               printf("Enter the length of the cube:",len);
               scanf("%d",&len);
               obj.setlength(len);
               printf("The area of the cube is:%d\n",obj.cube(len));
               break;
            case 2:
                len;
                int bre,hei;
                printf("Enter the length of the cuboid:",len);
                scanf("%d",&len);
                obj.setlength(len);
                printf("Enter the breadth of the cuboid:",bre);
                scanf("%d",&bre);
                obj.setbreadth(bre);
                printf("Enter the height of the cube:",hei);
                scanf("%d",&hei);
                obj.setheight(hei);
                printf("The area of the cuboid is:%d\n",obj.cuboid(len,bre,hei));
                break;
            case 3:
                printf("Enter the length of the square:",len);
                scanf("%d",&len);
                obj.setlength(len);
                printf("The area of the square is:%d\n",obj.square(len));
                break;
            case 4:
                printf("Enter the length of the rectangle:",len);
                scanf("%d",&len);
                obj.setlength(len);
                printf("Enter the breadth of the rectangle:",bre);
                scanf("%d",&bre);
                obj.setbreadth(bre);
                printf("The area of the rectangle is:%d\n",obj.rectangle(len,bre));
                break;
            case 5:
                 printf("Exiting the program....BYE BYE!!!!");
                 break;
               }
    }
    while(choice!=6);
    return 0;

