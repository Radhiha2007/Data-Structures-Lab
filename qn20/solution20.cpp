//Code to implement stl in finding value in tower 1
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;
int main(){
int test_case;
printf("Enter the number of testcases:\n");
scanf("%d",&test_case);
for(int i=0;i<test_case;i++){
int n;
printf("Enter number of towers:\n");
scanf("%d",&n);
stack<int>towers;
int blocks[n];
for(int j=0;j<n;j++){
printf("Blocks %d:",j+1);
scanf("%d",&blocks[j]);
towers.push(blocks[i]);
}
int tower1=blocks[0];
for(int k=1;k<n;k++){
while(blocks[k]>0 && blocks[k]>tower1){
tower1++;
blocks[k]--;
}
}
printf("The maximum blocks transferred from every towers to first tower is %d\n",tower1);
}
}
