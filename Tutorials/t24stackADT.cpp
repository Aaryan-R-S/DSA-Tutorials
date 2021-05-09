#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        int* arr;

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
    void push(){};
    void pop(){};
};

int main()
{
    Stack* myStack = new Stack();
    myStack->size = 10;
    myStack->top = -1;
    myStack->arr = new int[myStack->size];

    // for (int i = 0; i < myStack->size; i++)
    // {
    //     myStack->arr[0] = i;
    //     myStack->top++;
    // }
    

    if(myStack->checkEmpty()){
        cout<<"It's Empty!"<<endl;
    };
    if(myStack->checkFull()){
        cout<<"It's Full!"<<endl;
    };
    return 0;
}