#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    // string s = "jnJNoiLOInofo";

    // ------------------- Ascending -------------------
    // sort(s.begin(), s.end());
    // cout<<s<<endl;

    // ------------------- Descending -------------------
    // sort(s.begin(), s.end(), greater<char>());
    // cout<<s<<endl;

    // ------------------- Upper -------------------
    // transform(s.begin(), s.end(), s.begin(), ::toupper);
    // cout<<s<<endl;
    // OR
    /*
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]<='z' && s[i]>='a'){
            s[i] -= 'a'-'A';   // 32
        }
    }
    cout<<s<<endl;
    */
    
    // ------------------- Lower -------------------
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout<<s<<endl;

    // ------------------- IMP FUNCS -------------------
    // cout<<s.substr(0, 4)<<endl;
    // cout<<s.append("koi")<<endl;
    // s += "koi";
    // cout<<s<<endl;
    // cout<<s.insert(4, "HI")<<endl;
    // cout<<s.find("HI")<<endl;
    // cout<<s.erase(4, 2)<<endl;   // del HI
    // s.clear();
    // cout<<s<<endl;
    // cout<<s.empty()<<endl;

    // ------------------- Max frequency Char -------------------

    string s = "dviaov av soivs vs vsioodjvsxi";
    int freq[26];

    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]-'a']++;
    }
    char c = 'a';
    int cf = 0;

    for (int i = 0; i < 26; i++)
    {
        if(freq[i]>cf){
            cf = freq[i];
            c = i+'a';
        }
    }
    cout<<c<<" "<<cf<<endl;
    
    
    return 0;
}