//Program to find the number of elements removed to make a sequence distinct
#include<cstdio>
int main(){
    int testcase;
    int count=0;
    printf("Enter the number of testcases:\n");
    scanf("%d",&testcase);
    while(testcase--){
        int n;
        printf("Enter the total number of integers:\n");
        scanf("%d",&n);
        int a[n];
        for (int i=0;i<n;i++){
            printf("Enter the element %d:",i+1);
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    count=i+1;
                }
            }
        }
        printf("The Number of elements needed to be removed to find all unique events:%d",count);
    }
}
