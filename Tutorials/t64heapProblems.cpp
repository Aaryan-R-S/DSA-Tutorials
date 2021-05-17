#include<bits/stdc++.h>
using namespace std;

// Use STL for constructing maxHeap and minHeap
void STLHeap(){
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

int main()
{
    // STLHeap();

    return 0;
}