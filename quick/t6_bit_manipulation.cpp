#include<bits/stdc++.h>
using namespace std;

// Basics --------------------
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

// Q0 -----------------------
void swap(){
    int a=3, b=5;
    cout<<a<<" "<<b<<endl; 
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<a<<" "<<b<<endl; 
}

// Q1 -----------------------
bool isPowTwo(int n){
    return (n&(n-1) == 0);
}

// Q2 -----------------------
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

// Q3 -----------------------
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

// Q4 -----------------------
int uniqueOne(int arr[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    return xorsum;
}

// Q5 -----------------------
void uniqueTwo(int arr[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }

    int setbit = 0;
    int pos = 0;
    while(!setbit){
        setbit = xorsum&(1<<pos);
        pos++;
    }
    pos--;

    int newXorSum = 0;
    for (int i = 0; i < n; i++)
    {
        if( (arr[i]&(1<<pos)) != 0 ){
            newXorSum ^= arr[i];
        }
    }

    cout<<newXorSum<<endl;
    cout<<(xorsum^newXorSum)<<endl;   
}

// Q6 -----------------------
int uniqueThree(int arr[], int n){
    int result = 0;
    for (int i = 0; i <= 31; i++)    // signifies there is 32 bit representation
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if( arr[j]&(1<<i) ){   // getBit()
                sum++;
            }
        }
        if(sum%3!=0){
            result = result | (1<<i) ;  // setBit()
        }
    }
    return result;
}

// `Problems`
// - https://www.interviewbit.com/problems/different-bits-sum-pairwise/
// - https://www.interviewbit.com/problems/min-xor-value/
// - https://www.interviewbit.com/problems/xor-ing-the-subarrays/
// - https://www.interviewbit.com/problems/count-total-set-bits/ 
// - Help for above problem - [https://youtu.be/g6OxU-hRGtY]
// - https://www.interviewbit.com/problems/palindromic-binary-representation/
// - Help for above problem - [https://youtu.be/QYoWR8hDCyQ]

int main()
{
    // cout<<getBit(5, 2)<<endl;
    // cout<<setBit(5, 1)<<endl;
    // cout<<clearBit(5, 2)<<endl;
    // cout<<updateBit(5, 1, 1)<<endl;

    // swap();

    // cout<<isPowTwo(1)<<endl;
    // cout<<isPowTwo(12)<<endl;

    // cout<<noOfOnes(19)<<endl;

    // char arr[] = {'p','q','r','s'};
    // subsets(arr, 4);

    // All nums are present twice except ONE, find that one num
    // int arr[] = {2,4,6,3,4,6,2};
    // cout<<uniqueOne(arr, 7)<<endl;

    // All nums are present twice except TWO, find that two nums
    // int arr[] = {2,4,6,7,4,5,6,2};
    // uniqueTwo(arr, 8);

    // All nums are present thrice except ONE, find that one num
    int arr[] = {1,3,2,3,4,2,1,1,3,2};
    cout<<uniqueThree(arr, 10)<<endl;

    return 0;
}