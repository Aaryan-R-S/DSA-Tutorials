#include<bits/stdc++.h>
using namespace std;

// FIND THREE ELEM FROM AN ARRAY OF SIZE N WHOSE SUM IS T
// O(n^2) -> Reduce the problem to two sum problem [O(n)] by traversing the array once [O(n)] after sorting it [O(n*logn)]

int main()
{
    int n, t;
    cin>>n;
    cin>>t;

    vector<int> v(n);
    for (auto &i : v)
    {
        cin>>i;
    }

    sort(v.begin(), v.end());

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int low = i+1;
        int high = n-1;
        while(low<high){
            int sum = v[i] + v[low] + v[high];
            if(sum==t){
                found = true;
                break;
            }
            else if(sum<t){
                low++;
            }
            else{
                high--;
            }
        }
        if(found){
            break;
        }
    }
    cout<<(found==true?"True":"False")<<endl;
    

    return 0;
}