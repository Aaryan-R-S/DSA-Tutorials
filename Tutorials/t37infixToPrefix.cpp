#include<iostream>
#include<cmath>
using namespace std;

// same as postix but: 
// 1.carry conversion on reverse string and return revese result and 
// 2.equal precedence in the stack push() will be waived off 
// 3.opposite parenthesis
// 4.equal precedence in the stack push() will be added for ^ 

class Stack{
    public:

    int size = 20;
    int topVar = -1;
    char* varArr = new char[size];
    int topOpt = -1;
    char* optrArr = new char[size];

    string reverseStr(string s){
        char temp;
        for (int i=0; i<s.length()/2; i++)
        {
            temp = s[i];
            s[i] = s[s.length()-i-1];
            s[s.length()-i-1] = temp;
        }
        // cout<<s<<endl;
        return s;
    };

    void check(char c){
        if(c=='*'||c=='/'){
            this->push(c, 2);
        }
        else if(c=='+'||c=='-'){
            this->push(c, 1);
        }
        else if(c=='^'){
            this->push(c,3);
        }
        else if(c=='('){
            this->push(c,4);
        }
        else if(c==')'){
            this->push(c,4);
        }
        else{
            this->push(c, 0);
        }
    };
    void pop(char c){
        this->topOpt-=2;
        if(c!=')'){
            this->topVar++;
            this->varArr[this->topVar] = c;
        }
    };
    void push(char c, int b){
        if(b==0){
            this->topVar++;
            this->varArr[this->topVar] = c;
            return;
        }
        else if (this->topOpt!=-1){
            if (b==4)
            {
                if(c=='('){
                    while(this->optrArr[this->topOpt-1] != ')'){
                        pop(this->optrArr[this->topOpt-1]);
                    }
                    pop(this->optrArr[this->topOpt-1]);
                    return;
                }
            }
            else if (b==3)
            {
                while(int(this->optrArr[this->topOpt]) >= b && this->topOpt!=-1){
                    pop(this->optrArr[this->topOpt-1]);
                }
            }
            else{
                while(int(this->optrArr[this->topOpt]) > b && this->topOpt!=-1 && this->optrArr[this->topOpt-1] != ')'){
                    pop(this->optrArr[this->topOpt-1]);
                }
            }
        }
        this->topOpt++;
        this->optrArr[topOpt] = c;
        this->topOpt++;
        this->optrArr[topOpt] = b;
    };

    string conversion(string myExpression){
        string converted = "";
        myExpression = reverseStr(myExpression);
        for (int i=0; i<myExpression.length(); i++)
        {
            check(myExpression[i]);
        }
        while (this->topOpt!=-1)
        {
            this->topVar++;
            this->varArr[this->topVar] = this->optrArr[this->topOpt-1];
            this->topOpt-=2;
        }
        
        for (int i = 0; i <= this->topVar; i++)
        {
            converted+=this->varArr[i];
        }
        
        converted = reverseStr(converted);
        return converted;
    };
};

class StackEval{
public:
    int top=-1;
    float *arr = new float[20];

    void push(float f){
        this->top++;
        this->arr[this->top] = f;
    };

    float pop(char op){
        float op1, op2;
        op1 = this->arr[this->top];
        op2 = this->arr[this->top-1];
        this->top-=2;
        if(op=='*'){
            return op1*op2;
        }
        else if(op=='/'){
            return op1/op2;
        }
        else if(op=='+'){
            return op1+op2;
        }
        else if(op=='-'){
            return op1-op2;
        }
        else{
            return pow(op1, op2);
        }
    };
    float ans(string myExpression){
        for (int i=myExpression.length()-1; i>=0; i--)
        {
            if (myExpression[i]=='*'||myExpression[i]=='/'||myExpression[i]=='^'||myExpression[i]=='+'||myExpression[i]=='-')
            {
                float a = pop(myExpression[i]);
                push(a);
            }else{
                int ia = myExpression[i] - '0';
                push(float(ia));
            }
        }
        return this->arr[this->top];
    };
};

int main()
{
    Stack* inToPre = new Stack();

    printf("Enter the infix: ");
    string myExpression;
    cin>>myExpression;

    printf("Prefix: ");
    string converted = inToPre->conversion(myExpression);
    cout<<converted<<endl;

    StackEval* myStack = new StackEval();
    printf("Eval: ");
    float a = myStack->ans(converted);
    cout<<a;

    return 0;
}