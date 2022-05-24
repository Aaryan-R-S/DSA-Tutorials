#include<bits/stdc++.h>
using namespace std;

// Application: Autocomplete
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

    vector<string> find(string s){
        vector<string> wordsFound;
        int i = 0;
        Node* it = this->root;
        while(i<s.size()){
            if(it->next[s[i]-'a']==NULL){
                return wordsFound;
            }
            it = it->next[s[i]-'a'];
            i++;
        }
        helperOfFind(it, wordsFound, s);
        return wordsFound;
    }

    void helperOfFind(Node*it, vector<string> &wordsFound, string curr){
        if(it==NULL){
            return;
        }
        if(it->end){
            wordsFound.push_back(curr);
        }
        for (int i = 0; i < 26; i++)
        {
            if(it->next[i]){
                helperOfFind(it->next[i], wordsFound, curr+char('a'+i));
            }
        }
        return;
    }
};

// Improvement Node also store the word formed till it

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

    Trie* myTrie = new Trie();
    vector<string> words;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        string w; cin>>w;
        myTrie->insert(w);
    }
    int q; cin>>q;
    for (int i = 0; i < q; i++)
    {
        string w; cin>>w;
        vector<string> wordsFound = myTrie->find(w);
        if(wordsFound.size()==0){
            myTrie->insert(w);
            cout<<"No suggestions!"<<endl;
        }
        else{
            for (auto i : wordsFound)
                cout<<i<<endl;
        }
    }


    return 0;
}