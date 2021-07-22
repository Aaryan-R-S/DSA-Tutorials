#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

// Precedence checker
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')){
            result += s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while (!st.empty() && st.top()!='(')
            {
                result += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while (!st.empty() && prec(st.top()) >= prec(s[i]) )
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

string infixToPrefix(string s){
    // difference here reverse string
    reverse(s.begin(), s.end());
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')){
            result += s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while (!st.empty() && st.top()!=')')
            {
                result += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            // difference here > not >=
            while (!st.empty() && prec(st.top()) > prec(s[i]) )
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    // difference here reverse string again
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infixToPostfix("a-b/c*d")<<endl;
    cout<<infixToPrefix("a-b/c*d")<<endl;
    return 0;
}