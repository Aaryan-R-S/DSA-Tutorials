#include<iostream>
using namespace std;

void desiredSum(){
    // find sub-array of desired sum   
    // int n;
    // cin>>n;

    // int ans;
    // cin>>ans;

    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }

    
    // int start = 0;
    // int end = 0;
    // int sum = arr[start];
    // bool flag = 0;

    // while (start!=n-1 || end!=n-1)
    // {
    //     if (start!=end)
    //     {
    //         if (sum == ans)
    //         {
    //             cout<<start<<" "<<end<<endl;
    //             flag = 1;
    //             break;
    //         }
    //         else if(sum < ans){
    //             end++;
    //             sum += arr[end];
    //         }
    //         else{
    //             sum -= arr[start];
    //             start++;
    //         }
    //     }
    //     else{
    //         end++;
    //         sum += arr[end];
    //     }    
    // }

    // if (!flag)
    // {
    //     if (sum == ans)
    //     {
    //         cout<<start<<" "<<end<<endl;
    //     }
    //     else{
    //         cout<<"-1"<<endl;
    //     }
    // }
    
}

void repeatingElem(){
    // find min index of first repeating element   
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }    


    int N = 1e5;
    int indxArr[N];
    for (int i = 0; i < N; i++)
    {
        indxArr[i] = -1;
    }
    int minIndex = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if (indxArr[arr[i]] != -1)
        {
            minIndex = min(minIndex, indxArr[arr[i]]);
        }
        else{
            indxArr[arr[i]] = i;
        }
    }
    if (minIndex == INT16_MAX)
    {
        cout<<"-1"<<endl;
    }
    else{
        cout<<minIndex<<endl;
    }
}

int main()
{
  
    return 0;
}