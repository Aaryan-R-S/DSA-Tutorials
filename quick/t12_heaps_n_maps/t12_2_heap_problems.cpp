#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

// --REFER ADITYA VERMA PLAYLIST ALSO--
// Identification: Find kth smallest/closest or largest/frequent
// Make heaap of size k (smallest=maxheap and largest=minheap) pop elems if size of heaps get larger than k then at the last you have desired k elems left in heap
// Time complexity = O(n*logk) not (O(n*logn)) as heap max size is k

// `Problems`:
// - https://www.interviewbit.com/problems/merge-k-sorted-lists/
// - https://www.interviewbit.com/problems/lru-cache/
// - https://www.interviewbit.com/problems/n-max-pair-combinations/ [https://youtu.be/btjG9eLNYcg]
// - https://www.interviewbit.com/problems/ways-to-form-max-heap/ [https://youtu.be/s9hCZxjjBoE]

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

// After every input tell the median of the sorted array inputed so far
double medianOfRunningStream(priority_queue<int, vector<int>> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int k){
    if(maxHeap.size()==minHeap.size()){
        if(maxHeap.size()==0){
            maxHeap.push(k);
            // since sizes are unequal
            return maxHeap.top();
        }
        if(k<maxHeap.top()){
            maxHeap.push(k);
            // since sizes are unequal
            return maxHeap.top();
        }
        else{
            minHeap.push(k);
            // since sizes are unequal
            return minHeap.top();
        }
    }
    else{
        if(maxHeap.size()>minHeap.size()){
            if(k>=maxHeap.top()){
                minHeap.push(k);
            }
            else{
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                maxHeap.push(k);
            }
        }
        else{
            if(k<=minHeap.top()){
                maxHeap.push(k);
            }
            else{
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(k);
            }
        }
        // since sizes are equal
        return ((minHeap.top()+maxHeap.top())/2.0);
    }
}

// merge k sorted arrays
void mergeArrays(){
    int n; cin>>n;
    vector<vector<int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        int size;cin>>size;
        // Take input of elems of n arrays each of size 'size
        vec[i] = vector<int> (size);

        for (int j = 0; j < size; j++)
        {
            cin>>vec[i][j];
        } 
    }

    // Declare minHeap which will store n elems at a time which are respectively minimum elems in their repective arrays
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push({vec[i][0], i});
    }

    vector<int> indices(n, 0);  // store indices of each array upto which elems are inserted
    vector<int> ans;    // store ans array

    //  main algo
    while(!minHeap.empty()){
        pii myTop = minHeap.top();
        minHeap.pop();
        ans.push_back(myTop.first);

        if(indices[myTop.second]+1<vec[myTop.second].size()){
            minHeap.push({
                vec[myTop.second][indices[myTop.second]+1], myTop.second
                });
        }
        indices[myTop.second]++;
    }

    // cout ans
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

// given an array of size n find smallest subsequence with sum at least k
void sumK(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    priority_queue<int, vector<int>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(v[i]);
    }

    int sum = 0;
    int count = 0;
    while(!maxHeap.empty()){
        sum += maxHeap.top();
        count++;
        maxHeap.pop();

        if(sum>=k){
            break;
        }
    }
    if(sum<k){
        cout<<"Not possible!"<<endl;
    }
    else{
        cout<<count<<endl;
    }
}

int main()
{
    // STLHeap();

    // priority_queue<int, vector<int>> maxHeap;
    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // int n; cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int num;
    //     cin>>num;
    //     cout<<"Median: "<<medianOfRunningStream(maxHeap, minHeap, num)<<endl;
    //     cout<<"Size: "<<maxHeap.size()<<" "<<minHeap.size()<<endl;
    // }
    
    // mergeArrays();

    sumK();

    return 0;
}