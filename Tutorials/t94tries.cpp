#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
    class Node{
    public:
        Node* next[26];
        bool end;
        Node(){
            this->end = false;
            for (int i = 0; i < 26; i++)
            {
                this->next[i] = NULL;
            }
        }
    };
    Node* root;
    Trie(){
        this->root = new Node();
    }
    
    void insert(string s){
        int i = 0;
        Node* it = this->root;
        while(i<s.size()){
            if(it->next[s[i]-'a']==NULL){
                it->next[s[i]-'a'] = new Node();
            }
            it = it->next[s[i]-'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string s){
        int i = 0;
        Node* it = this->root;
        while(i<s.size()){
            if(it->next[s[i]-'a']==NULL){
                return false;
            }
            it = it->next[s[i]-'a'];
            i++;
        }
        return it->end;
    }

};

int main()
{
    // Trie* myTrie = new Trie();
    // vector<string> words = {"hello","zip","aami","hel"};
    // for (auto i : words)
    // {
    //     myTrie->insert(i);
    // }
    // myTrie->search("hello")?cout<<"ok\n":cout<<"no\n";
    // myTrie->search("bye")?cout<<"ok\n":cout<<"no\n";
    // myTrie->search("hel")?cout<<"ok\n":cout<<"no\n";
    // myTrie->search("aami")?cout<<"ok\n":cout<<"no\n";
    // myTrie->search("aamif")?cout<<"ok\n":cout<<"no\n";
    // myTrie->search("zip")?cout<<"ok\n":cout<<"no\n";

    return 0;
}