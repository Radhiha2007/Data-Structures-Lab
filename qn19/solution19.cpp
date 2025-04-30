//Code to implement given function
#include<cstdio>
#include"stack_sll.h"
#include<iostream>
#include<string>
using namespace std;
void question(string Input){
    stack_sll s;
    for(int i=0;i<Input.length();i++){
        char ch=Input[i];
        if(ch =='+'){
            s.pop();
        }
        else{
            s.push((int)ch);
        }
    }
    string result="";
    while(!s.isEmpty()){
        result+=s.peek();
        s.pop();
    }
    cout << "\nOutput string: " << result << endl; 

}
int main(){
    string Input;
    cout << "Enter the Input string:\n";
    cin >> Input; 
    question(Input);
    return 0;
}
