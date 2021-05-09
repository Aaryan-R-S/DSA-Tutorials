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

        bool pop(){
            if(this->top == -1){
                return false;
            }
            else{
                this->top--;
                return true;
            };
        };
};

bool parenthesisMatch(Stack* myStack){
    for (int i = 0; myStack->expression[i] != '\0'; i++)
    {
        if(myStack->expression[i]=='('){
            bool v = myStack->push(myStack->expression[i]);
            if (v==0){
                return false;
            }
        }
        else if (myStack->expression[i]==')'){
            bool v = myStack->pop();
            if (v==0){
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
    char a[] = "(5*3/(6-4))";

    for (int i = 0; a[i]!='\0'; i++)
    {
        myStack->expression[i] = a[i];
    }

    if(parenthesisMatch(myStack)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    
    return 0;
}