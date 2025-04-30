//Code to implement and find the highest
#include<cstdio>
void solve(){
    int n;
    printf("Enter the total number of players:\n");
    scanf("%d",&n);
    int a[n];
    int first_max=0;
    int second_max=0;
    for(int i=0;i<n;i++){
        printf("Enter player %d:",i+1);
        scanf("%d",&a[i]);
        if(a[i]>first_max){
            second_max=first_max;
            first_max=a[i];
        }
        else if(a[i]>second_max){
            second_max=a[i];
        }
    }
    for (int i=0;i<n;i++){
        if(a[i]==first_max){
            printf("%d",a[i]-second_max);
        }
        else{
            printf("%d",a[i]-first_max);
        }
        printf("\n");
    }
}
int main(){
    int testcase;
    printf("Enter number of testcases:\n");
    scanf("%d",&testcase);
    while(testcase--){
        solve();
    }
}
