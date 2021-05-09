#include<iostream>
using namespace std;

class Stack{
    public:
        int length = 20;
        int top = -1;
        char* expression = new char[length];

        bool push(char c){
            if(this->top == this->length-1){
                return false;
            }
            else{
                this->top++;
                this->expression[top] = c;
                return true;
            }
        };

        char pop(){
            char popChar = this->expression[this->top];
            this->top--;
            return popChar;
        };
};

bool match(char a, char b){
    if(a=='(' && b==')'){
        return 1;
    }
    else if(a=='[' && b==']'){
        return 1;
    }
    else if(a=='{' && b=='}'){
        return 1;
    }
    return 0;
};

bool parenthesisMatch(Stack* myStack, char expression[]){
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{'){
            bool v = myStack->push(expression[i]);
            if (v==0){
                return false;
            }
        }
        else if (expression[i]==')' || expression[i]==']' || expression[i]=='}'){
            if (myStack->top == - 1){
                return false;
            }
            char popChar = myStack->pop();
            if (!match(popChar, expression[i])){
                return false;
            }
        }
    }
    if(myStack->top!=-1){
        return false;
    }
    return true;
};


int main()
{
    Stack *myStack = new Stack();
    char expression[] = "(5{*[]}3/[{}](6-4))";
    if(parenthesisMatch(myStack, expression)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    
    return 0;
}