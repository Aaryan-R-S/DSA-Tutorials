#include<iostream>
using namespace std;

int getBit(int n, int i){
    return ((n&(1<<i)) != 0);
}

int setBit(int n, int i){
    return (n|(1<<i));
}

int clearBit(int n, int i){
    return (n&(~(1<<i)));
}

int updateBit(int n, int i, int b){
    n = n&(~(1<<i));  // clear bit
    n = n|(b<<i);  // set bit
    return n;
}

bool isPowTwo(int n){
    return (n&(n-1) == 0);
}

// n&(n-1) has same bits as n except the bits after rightmost set bit
// e.g. n = 19 = 01011         n = 18 = 01010          n = 16 = 01000 
//      n = 18 = 01010    ->   n = 17 = 01001     ->   n = 15 = 00111
//      n&(n-1)= 01010         n&(n-1)= 01000         n&(n-1)= 00000
// since it took 3 steps no. of '1' bits = 3;
int noOfOnes(int n){
    int count = 0;
    while (n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

// Bitmasking Technique -- given n element subset, generate all the subsets (precisely 2^n) using bits of numbers from i = 0 to 2^n (or 1<<n)
void subsets(char arr[], int n){
    for (int i = 0; i < (1<<n); i++)
    {
        cout<<"-> ";
        for (int j = 0; j < n; j++)
        {
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    // cout<<getBit(5, 2)<<endl;
    // cout<<setBit(5, 1)<<endl;
    // cout<<clearBit(5, 2)<<endl;
    // cout<<updateBit(5, 1, 1)<<endl;

    // cout<<isPowTwo(1)<<endl;
    // cout<<isPowTwo(12)<<endl;

    // cout<<noOfOnes(19)<<endl;

    char arr[] = {'p','q','r','s'};
    subsets(arr, 4);

    return 0;
}