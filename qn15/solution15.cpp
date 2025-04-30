//Program to solve parenthesis question using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define MAX_SIZE 100
using namespace std;

class parenthesis {
private:
    char arr[MAX_SIZE]; 
    int top; 

public:
    parenthesis() {
        top = -1;
    }

void push(char);
void pop();
bool isEmpty();
bool isvalid(string);
};
int main(){
    parenthesis obj;
    int choice;
    string Input;
    do{
        printf("MENU\n1.Check Balance\n2.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                cout << "Enter a string:\n ";
                cin >> Input;  
                cout << "You entered: \n" << Input << endl;
                if(obj.isvalid(Input)){
                    printf("Balanced\n");
                }
                else{
                    printf("Not Balanced\n");
                }
                break;
            case 2:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice!Try again\n");

        }
    }while(choice!=2);
}
void parenthesis::push(char ch){
    if(top>=MAX_SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    arr[++top]=ch;
}
void parenthesis::pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return;
    }
    top--;
}
bool parenthesis::isEmpty() {
    return top == -1;
}

bool parenthesis::isvalid(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            push(str[i]);
        }
        else if(str[i]==')'){
            if(isEmpty()){
                return false;
            }
            pop();
        }
    }
    return isEmpty();
}
