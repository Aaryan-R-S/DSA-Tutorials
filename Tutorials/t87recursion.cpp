#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

// Refer Algorithms - Apni Kaksha
int pow(int a, int b){
    if(b==0){return 1;}
    return a*pow(a, b-1);
};

int powFast(int a, int b){
    if(b==0){return 1;}
    if(b%2==0){return powFast(a*a, b/2);}
    return a*powFast(a*a, (b-1)/2);
};

void floodFill(int a[8][8], int m, int n, int preFill, int toFill){
    if (m<0 || m>7 || n<0 || n>7){ return; }
    if (a[m][n] != preFill){ return; }
    a[m][n] = toFill;
    floodFill(a, m-1, n, preFill, toFill);
    floodFill(a, m, n-1, preFill, toFill);
    floodFill(a, m+1, n, preFill, toFill);
    floodFill(a, m, n+1, preFill, toFill);
};

string interchange(string s, int a, int b){
    int n = s.length();
    char char_array[n];

    // copying the contents of the string to char array
    strcpy(char_array, s.c_str());

    // interchange
    char temp = char_array[a];
    char_array[a] = char_array[b];
    char_array[b] = temp;

    // convert back to string
    string ss = "";
    for (int i = 0; i < n; i++) {
        ss += char_array[i];
    }
    return ss;
};

// Method - 1
void permutationOfString(string s, int l, int r){
    if(l==r){ cout<<s<<endl; return; }
    for (int i = l; i <= r; i++)
    {
        s = interchange(s, l, i);
        permutationOfString(s, l+1, r);
        s = interchange(s, l, i);  // Backtracking
    }
};

// Method - 2 (Good)
void permutationOfString(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string r = s.substr(0, i) + s.substr(i+1, s.length());
        permutationOfString(r, ans+c);
    }

    return;
}

// Permutation of DISTINCT integer arrays 
vector<vector<int>> ans;
void permutationOfIntArr(vector<int> &v, int index){
    if (index == v.size()){
        ans.push_back(v);
        return;
    }
    for (int i = index; i < v.size(); i++)
    {

        swap(v[i], v[index]);
        permutationOfIntArr(v, index+1);
        swap(v[i], v[index]);
    }
    return;
}

// Permutation of GENERAL integer arrays
void helper(vector<int> v, vector<vector<int>> &answer, int index){
    if (index == v.size()){
        answer.push_back(v);
        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        if(i!=index and v[i]==v[index]){
            continue;
        }
        swap(v[i], v[index]);
        helper(v, answer, index+1);
    }
    return;
}

vector<vector<int>> permute(vector<int> nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    helper(nums, answer, 0);
    return answer;
}

// STL Trick - works in all cases
void permutationOfIntArr(vector<int> &v){
    sort(v.begin(), v.end());
    do
    {
        ans.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
    return;   
}

int main()
{
    // cout<<pow(3, 10000)<<endl;      // 10001 steps
    // cout<<powFast(3, 10000)<<endl;  // 15 steps

    // int a[8][8] = {
    //     {1,1,1,1,1,1,1,1},
    //     {1,1,1,1,1,1,0,0},
    //     {1,0,0,1,1,0,1,1},
    //     {1,2,2,2,2,0,1,0},
    //     {1,1,1,2,2,0,1,0},
    //     {1,1,1,2,2,2,2,0},
    //     {1,1,1,1,1,2,1,1},
    //     {1,1,1,1,1,2,2,1},
    // };
    // floodFill(a, 0, 0, 1, 7);
    // floodFill(a, 4, 3, 2, 3);
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // string s = "123";
    // permutationOfString(s, 0, s.length()-1);
    // string s = "ABCD";
    // permutationOfString(s, "");

    // int n;
    // cin>>n;
    // vector<int> v(n);
    // for (auto &i : v)
    // {
    //     cin>>i;
    // }
    // permutationOfIntArr(v, 0);
    // permutationOfIntArr(v);
    // for (auto &k : ans)
    // {
    //     for (auto &i : k)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // int n;
    // cin>>n;
    // vector<int> nums(n);
    // for (auto &i : nums)
    // {
    //     cin>>i;
    // }
    // vector<vector<int>> answer = permute(nums);
    // for (auto &k : answer)
    // {
    //     for (auto &i : k)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}