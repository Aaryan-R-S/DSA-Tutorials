#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using muset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


void a(){
    // ---------------------------- Set ----------------------------------
    // find, insert, erase, lower_bound, upper_bound
    // duplicates not allowed; ordered; 
    set<int> s;
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

    cout<<*s.lower_bound(2)<<endl;      // find the element just greater than or equal to k
    cout<<*s.upper_bound(2)<<endl;      // find the element just greater than k
    cout<<*s.upper_bound(3)<<endl;      // find the element just greater than k
}

void b(){
    // ---------------------------- Multiset ----------------------------------
    // duplicates allowed; ordered; 
    // find, insert, erase, lower_bound, upper_bound
    multiset<int> ms;
    ms.insert(2);    
    ms.insert(3);    
    ms.insert(1);     
    ms.insert(3);    
    ms.insert(4);    
    ms.insert(2);
    for (auto &i : ms){
        cout<<i<<" ";
    }cout<<endl;
    
    // ms.erase(3);
    ms.erase(ms.find(3));
    for (auto &i : ms){
        cout<<i<<" ";
    }cout<<endl;
}

void c(){
    // ---------------------------- Unordered set ----------------------------------
    // duplicates not allowed; unordered; 
    // find, insert, erase, lower_bound, upper_bound
    unordered_set<int> us;
    us.insert(2);    
    us.insert(3);    
    us.insert(1);     
    us.insert(3);    
    us.insert(4);    
    us.insert(2);
    for (auto &i : us){
        cout<<i<<" ";
    }cout<<endl;
    
    us.erase(3);
    // us.erase(s.find(3));
    for (auto &i : us){
        cout<<i<<" ";
    }cout<<endl;
}

void d(){
    // ---------------------------- PBDS ----------------------------------
    // duplicates not allowed; ordered; 
    // find, insert, erase, lower_bound, upper_bound, find_by_order, order_of_key
    oset<int> s;
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
    cout<<s.order_of_key(2)<<endl;      // no of elements strictly smaller than k
    cout<<s.order_of_key(3)<<endl;      // no of elements strictly smaller than k
}

int main()
{
    cout<<"Set"<<endl;
    a();
    cout<<endl;
    cout<<"Multi Set"<<endl;
    b();
    cout<<endl;
    cout<<"Unordered Set"<<endl;
    c();
    cout<<endl;
    cout<<"PBDS"<<endl;
    d();
    cout<<endl;

    return 0;
}