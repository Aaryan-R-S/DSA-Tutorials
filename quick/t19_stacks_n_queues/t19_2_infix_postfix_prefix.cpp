#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

// 1. Infix to Postfix
// 2. Postfix eval value
// 3. Create a binary tree using infix/prefix/postfix [Refer Jenny's Lecture]
// 4. Tree inorder of infix = infix
// 5. Tree preorder of infix = prefix
// 6. Tree postorder of infix = postfix

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
            while (!st.empty() && (st.top()!='^' ? prec(st.top()) >= prec(s[i]) : prec(st.top()) > prec(s[i])) )
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
            // difference here > not >= for general case
            while (!st.empty() && (st.top()=='^' ? prec(st.top()) >= prec(s[i]) : prec(st.top()) > prec(s[i])) )
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
    cout<<infixToPostfix("a^b^c")<<endl;
    cout<<infixToPrefix("a^b^c")<<endl;
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infixToPostfix("a-b/c*d")<<endl;
    cout<<infixToPrefix("a-b/c*d")<<endl;
    return 0;
}