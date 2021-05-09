#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        int* arr;

    void display(bool reverse = false){
        if(reverse==true){
            int i = this->top;
            while (i>=0)
            {
                printf("%d ", this->arr[i]);
                i--;
            }
        }
        else{
            int i = 0;
            while (i <= this->top)
            {
                printf("%d ", this->arr[i]);
                i++;
            }
        }
        printf("\n");
    };
    void peek(int n, bool reverse = false){
        if (reverse)
        {
            printf("%d", this->arr[this->top-n+1]);
        }
        else
        {
            printf("%d", this->arr[n]);
        }
        printf("\n");
    };

    bool checkEmpty(){
        if(this->top == -1){
            return 1;
        }
        return 0;
    };
    bool checkFull(){
        if(this->top == this->size-1){
            return 1;
        }
        return 0;
    };

    Stack* push(int n){
        if(this->checkFull()){
            cout<<"It's Full!"<<endl;
            return this;
        }
        else{
            this->top++;
            this->arr[top] = n;
            return this;
        };
    };
    Stack* pop(){
        if(this->checkEmpty()){
            cout<<"It's Empty!"<<endl;
            return this;
        }
        else{
            this->top--;
            return this;
        };
    };

    int stackTop(){
        return this->arr[this->top];
    };
    int stackBottom(){
        return this->arr[0];
    };
};

int main()
{
    Stack* myStack = new Stack();
    myStack->size = 10;
    myStack->top = -1;
    myStack->arr = new int[myStack->size];

    myStack->push(0);
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->display();

    myStack->pop();
    myStack->display();
    myStack->display(true);

    myStack->peek(2);
    myStack->peek(2, true);
    cout<<myStack->stackTop()<<endl;
    cout<<myStack->stackBottom()<<endl;

    return 0;
}