#include<bits/stdc++.h>
using namespace std;

// Standard Template Library:
// 1. Container - store data 
//      1.1 Sequential - vector, pair, stack, queue
//      1.2 Ordered - set, map, mutliset, mutlimap
//      1.3 Unordered - unordered map, unordered set
// 2. Iterator - iterate over sequential containers
// 3. Algorithm - useful inbuilt functions
// 4. Functors - classes that behave like functions (irrelevant)

// YT Playlist - https://youtube.com/playlist?list=PLauivoElc3gh3RCiQA82MDI-gJfXQQVnn

void myPair(){
    pair<int, string> p;
    // p = make_pair(2, "abs");
    p = {2, "abs"};
    cout<<p.first<<" "<<p.second<<endl;

    // pair<int, string> p_cp = p;   // copy
    pair<int, string> &p_cp = p;    // reference, so actual
    p_cp.first = 3;
    cout<<p.first<<" "<<p.second<<endl;
}

void myVector(){
    // Implemented using native array internally

    vector<int> v;
    // vector<int> v(3);
    // vector<int> v(5, -1);

    for(int i=0; i<5; i++){
        v.push_back(i+10);
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    // O(1) - v.size() and v.push_back();

    // O(n) - copying
    // vector<int> vv = v; // copy
    
    // O(1) - reference as it is actual
    // vector<int> &vv = v; // reference

    // vector<int> :: iterator it = v.begin();
    auto it = v.begin();
    for(; it!=v.end(); it++){
        cout<<*it<<" ";
        // assume vector<pair<int,int>> then: (*it).first <=> it->first
    }cout<<endl;

    // Range based loops --
    // for(int val:v){
    // for(auto val:v){             // you cannot change val by val++ (copy)
    for(auto &val:v){               // you can change val by val++ (reference)
        cout<<val<<" ";
    }cout<<endl;
}

void myMap(){
    // Implemented using Red Black Tree internally
    // Sorted always

    map<int, string> m;
    m[5] = "ghi";   // O(log(n))
    m[2];   // O(log(n)) -- by default empty string or 0 in case of int
    m[1] = "abc";
    m[3] = "def";

    // n*log(n) -- as n elems with access time of each as log(n)
    for (auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }

    // m.erase(1);   // O(log(n))           -- arg as an value
    auto itt = m.find(1);   // O(log(n))
    // m.erase(itt);   // O(1)              -- arg as an iterator
    if(itt==m.end()){
        cout<<"No such key-value pair exists"<<endl;
    }
    else{
        cout<<itt->first<<" "<<itt->second<<endl;
    }

    m.clear();
    for (auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }

    // -----------------------------------------------------------------------------------
    // unordered_map<int,string> m;

    // Implemented using Hash Tables internally
    // Same as map but all operations take O(1) "average" time complexity
    // While printing, the "key-value" pairs can be printed in any order (even different from insertion order)

    // It cannot handle "complex" data types because there hash functions do not exist -- so use it only for primitive data types
    // INVALID :-
    // unordered_map<pair<int,int>, string> m;
    // VALID :-
    // map<pair<int,int>, string> m;

    // -----------------------------------------------------------------------------------
    // multimap<int,string> m;

    // Implemented using Red Black Tree internally
    // Same as map but duplicate key-value pair (more specifically keys) are allowed
    // Sorted like map

}

void mySet(){
    // Implemented using Red Black Tree internally
    // Sorted always

    // To get last element from set or any other container use cout << *s.rbegin() OR cout << *(--s.end()); 

    set<string> s;
    s.insert("abc");   // O(log(n))
    s.insert("def");
    s.insert("ghi");
    s.insert("def");

    // n*log(n) -- as n elems with access time of each as log(n)
    for (auto &it : s){
        cout<<it<<endl;
    }

    // s.erase("def");   // O(log(n))       -- arg as an value
    auto itt = s.find("def");   // O(log(n))
    // s.erase(itt);   // O(1)              -- arg as an iterator
    if(itt==s.end()){
        cout<<"No such value exists"<<endl;
    }
    else{
        cout<<*itt<<endl;
    }

    s.clear();
    for (auto &ittt : s){
        cout<<ittt<<endl;
    }

    // -----------------------------------------------------------------------------------
    // unordered_set<string> s;

    // Implemented using Hash Tables internally
    // Same as set but all operations take O(1) "average" time complexity
    // While printing, the values can be printed in any order (even different from insertion order)

    // It cannot handle "complex" data types because there hash functions do not exist -- so use it only for primitive data types
    // INVALID :-
    // unordered_set<pair<int,int>> s;
    // VALID :-
    // set<pair<int,int>> s;

    // -----------------------------------------------------------------------------------
    // multiset<string> s;

    // Implemented using Red Black Tree internally
    // Same as set but duplicate values are allowed
    // Sorted like set

    // s.find() -- returns the iterator to first occurrence of value 
    // s.erase(s.find()) -- deletes the first occurrence of value
    // s.erase(value) -- deletes all the occurrences of value -- can be considered as while(s.find()!=s.end()){s.erase(s.find())}

}

void myStackNQueue(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(1);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;

    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(1);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}

void myStr(){
    string s = "jnJNoiLOInofo";

    // ------------------- Ascending -------------------
    sort(s.begin(), s.end());
    cout<<s<<endl;

    // ------------------- Descending -------------------
    sort(s.begin(), s.end(), greater<char>());
    cout<<s<<endl;

    // ------------------- Upper -------------------
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
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
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;

    // ------------------- IMP FUNCS -------------------
    cout<<s.substr(0, 4)<<endl;
    cout<<s.append("koi")<<endl;
    s += "koi";
    cout<<s<<endl;
    cout<<s.insert(4, "HI")<<endl;
    cout<<s.find("HI")<<endl;
    cout<<s.erase(4, 2)<<endl;   // del HI
    s.clear();
    cout<<s<<endl;
    cout<<s.empty()<<endl;
}

void myHeap(){
    priority_queue<int, vector<int>> maxHeap;
    maxHeap.push(5);
    maxHeap.push(6);
    maxHeap.push(4);
    maxHeap.push(2);
    while(!maxHeap.empty())    
    {
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }
    cout<<endl;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(6);
    minHeap.push(4);
    minHeap.push(2);
    while(!minHeap.empty())    
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    cout<<endl;
}

// %% PBDS %%
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using muset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void myPBDS(){
    // Policy Based Data Structure OR Ordered Set 
    // RB Tree implementation
    // duplicates not allowed; ordered; Multi-Ordered Set-> Duplicates Allowed
    // find, insert, erase, lower_bound, upper_bound, find_by_order, order_of_key
    oset<int> s;
    // muset<int> s;
    s.insert(2);    
    s.insert(3);    
    s.insert(1);     
    s.insert(3);    
    s.insert(4);    
    s.insert(2);
    for (auto &i : s){
        cout<<i<<" ";
    }cout<<endl;
    
    s.erase(3);
    // s.erase(s.find(3));
    for (auto &i : s){
        cout<<i<<" ";
    }cout<<endl;

    cout<<*s.find_by_order(2)<<endl;    // kth element in a set (starting from 0)
    cout<<*s.find_by_order(1)<<endl;    // kth element in a set (starting from 0)
    cout<<s.order_of_key(2)<<endl;      // no of elements strictly smaller than k (starting from 0)
    cout<<s.order_of_key(3)<<endl;      // no of elements strictly smaller than k (starting from 0)
}

bool comparator(pair<int,int> &a, pair<int,int> &b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
}

void mySort(){
    // Implemented using INTROSORT -- mixture of quick sort(start with this), heap sort(if high recursion calls in quick sort) and insertion sort(for smaller size arrays)

    int arr[] = {4,5,3,2,1};
    // sort(arr, arr+3);
    sort(arr, arr+5);
    for (int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    // Custom comparator in sort()
    // 6
    // 4 3
    // 5 5
    // 5 3
    // 25 6
    // 7 9
    // 8 5
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end(), comparator);
    for (int i = 0; i < n; i++){
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
    
}

void myAlgos(){
    // All operations O(n) in case of array or vector but O(log(n)) in case of map and set

    int n=6;
    int arr[] = {4,5,5,25,7,8};
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    cout<<*min_element(arr, arr+n)<<endl;
    cout<<*max_element(arr, arr+n)<<endl;
    cout<<accumulate(arr, arr+n, 0)<<endl;      // 3rd arg = initial value of sum
    cout<<count(arr, arr+n, 24)<<endl;
    int* i = find(arr, arr+n, 5);
    cout<<(i == (arr+n) ? -1: *i)<<endl;

    reverse(arr, arr+n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    sort(arr, arr+n);   // sort first otherwise lower_bound and upper_bound will work on original array assuming it to be sorted
    cout<<*lower_bound(arr, arr+n, 5)<<endl;   // if exists, then return itr to it
    cout<<*lower_bound(arr, arr+n, 6)<<endl;   // if do not exists, then return itr to next greater
    cout<<*upper_bound(arr, arr+n, 5)<<endl;   // always return itr to next greater
    cout<<*upper_bound(arr, arr+n, 6)<<endl;   // always return itr to next greater

    int* ii = lower_bound(arr, arr+n, 26);
    int* iii = upper_bound(arr, arr+n, 26);
    cout<<(ii == (arr+n) ? -1: *ii)<<endl;   // always return itr to next greater
    cout<<(iii == (arr+n) ? -1: *iii)<<endl;   // always return itr to next greater

    // Same goes for vector but with v.begin() and v.end()
    
    // In case of "set" and "map" do not use above
    // use this *(s.lower_bound(value)) instead of *lower_bound(s.begin(), s.end(), value)
    // because set and map are not sequential which results in high access time in case of latter
}

bool isPos(int n){
    return n>0;
}

void myAlgos2(){
    // Lambda functions in cpp:
    cout<<[](int n){return n+2;}(3)<<endl;
    // OR
    auto incr = [](int n){return n+2;};
    cout<<incr(3)<<endl;

    // all_of, any_of, none_of:
    // vector<int> v = {2,3,5};
    vector<int> v = {2,-3,5};
    // vector<int> v = {-2,-3,-5};
    cout<<all_of(v.begin(), v.end(), isPos)<<endl;
    cout<<all_of(v.begin(), v.end(), [](int n){return n>0;})<<endl;
    cout<<any_of(v.begin(), v.end(), [](int n){return n>0;})<<endl;
    cout<<none_of(v.begin(), v.end(), [](int n){return n>0;})<<endl;
}

int main(){

    // CONTAINERS ------------------------------------------------
    // myPair();
    // myVector();
    // myMap();  // along with unordered map and multimap
    // mySet();  // along with unordered set and multiset
    // myStackNQueue();
    // myStr();
    // myHeap();
    // myPBDS();

    // ALGORITHMS ------------------------------------------------
    // mySort();
    // myAlgos();
    // myAlgos2();


    return 0;
}