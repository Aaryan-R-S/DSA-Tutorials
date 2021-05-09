#include<iostream>
using namespace std;

void rev_str(string s){
    if(s.length()==0){
        return;
    }
    rev_str(s.substr(1, s.length()));
    cout<<s[0];
}

void replace_Pi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replace_Pi(s.substr(2, s.length()));
    }
    else{
        cout<<s[0];
        replace_Pi(s.substr(1, s.length()));
    }
}

void tower_of_hanoi(int n, char src, char hepler, char dest){
    if(n==0){
        return;
    }
    tower_of_hanoi(n-1, src, dest, hepler);
    cout<<"Move ring no. "<<n<<" from "<<src<<" to "<<dest<<endl;
    tower_of_hanoi(n-1, hepler, src, dest);
}

string remove_duplicates(string s){
    if(s.length()==0){
        return "";
    }

    char c = s[0];
    string ans = remove_duplicates(s.substr(1, s.length()));

    if(c == ans[0]){
        return ans;
    }
    else{
        return (c+ans);
    }
}

string move_all_x_to_end(string s){
    if(s.length()==0){
        return "";
    }

    char c = s[0];
    string ans = move_all_x_to_end(s.substr(1, s.length()));

    if(c == 'x'){
        return (ans+c);
    }
    else{
        return (c+ans);
    }
}

void subseq_str(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char c = s[0];
    string r = s.substr(1, s.length());

    subseq_str(r, ans);
    subseq_str(r, ans+c);
}

void subseq_str_ascii(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char c = s[0];
    int ascii = c;

    string r = s.substr(1, s.length());

    subseq_str_ascii(r, ans);
    subseq_str_ascii(r, ans+c);
    subseq_str_ascii(r, ans+to_string(ascii));
}

int main()
{
    // rev_str("binod");
    // replace_Pi("pipokmcwpmcpoaurppincacfcniuwfn");
    // tower_of_hanoi(3, 'A', 'B', 'C');
    // cout<<remove_duplicates("aaaabbbbccccddddeeeefgggg")<<endl;
    // cout<<move_all_x_to_end("xjhvljxjlxzkjlhslx")<<endl;
    // subseq_str("abcd", "");
    // subseq_str_ascii("ab", "");
    
    return 0;
}