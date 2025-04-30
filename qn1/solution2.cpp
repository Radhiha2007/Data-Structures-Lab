Input:
#include<iostream>
#include"sort.h"
int linear(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int binary(int arr[],int n,int target){
    bubbleSort(arr,n);
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, choice,target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to be searched:\n");
    scanf("%d",&target);
 do {
        printf("\nMenu:\n");
        printf("1. Linear search\n");
        printf("2. Binary search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(int result=linear(arr, n,target);result==-1){

                    printf("element not found\n");
                }
                else{
                    printf("It is found at %d",result);
                }
                break;
            case 2:
                if(int output=binary(arr, n,target);output==-1){
                    printf("element not found\n");
                }
                else{
                    printf("It is found at %d",output);
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
