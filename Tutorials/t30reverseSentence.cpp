#include <iostream>
#include <string>
#include <stack>
using namespace std;

// REVERSE A SENTENCE
void reverseSentence(string s)
{
    stack<string> st;
    int i = 0;
    while (i < s.length())
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
        i++;
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

// REVERSE A STACK
void insertAtBottom(stack<int> &st, int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, elem);
    st.push(topElem);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int elem = st.top();
    st.pop();
    reverseStack(st);;
    insertAtBottom(st, elem);
}

int main()
{
    // string s = "Hey, how are you doing?";
    // reverseSentence(s);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

    return 0;
}