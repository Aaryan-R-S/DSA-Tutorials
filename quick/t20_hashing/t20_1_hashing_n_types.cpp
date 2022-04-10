#include<iostream>
using namespace std;

// Hashing using Division method:
// 1. Open Hashing (or closed addressing) - Chaining Method
// 2. Closed Hashing (or open addressing) - Linear Probing, Quadratic Probing and Double Hashing

// Open Hashing
void chaining(int arr[], int mod, char hash[], int len){
    int A[mod][mod];
    int probes[len];
    for (int i = 0; i < len; i++)
    {
        probes[i] = 0;        
    }
    for (int i = 0; i < mod; i++)
    {
        for (int j = 0; j < mod; j++)
        {
            A[i][j] = -1;        
        }
    }
    int a = hash[0]-'0';
    int b = hash[3]-'0';
    char o = hash[2];
    int u;
    for (int i = 0; i < len; i++)
    {
        u = o == '+' ? (a*arr[i]+b)%10 : (a*arr[i]-b)%10;
        if (A[u][0]!=-1)
        {
            int p = 0;
            while (A[u][p]!=-1)
            {
                p++;
            }
            A[u][p] = arr[i];
            probes[i] = p+1;
        }
        else{
            A[u][0] = arr[i];
            probes[i] = 1;
        }
    }
    for (int i = 0; i < mod; i++)
    {
        if (A[i][0]!=-1)
        {
            int p = 0;
            while (A[i][p]!=-1)
            {
                cout<<A[i][p]<<"->";
                p++;
            }
            cout<<", ";
        }
        else{
            cout<<"_, ";
        }
    }
    cout<<endl;
    cout<<"Probes: ";
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<":"<<probes[i]<<", ";
    }
    cout<<endl;
};

// Closed Hashing
void linearProbing(int arr[], int mod, char hash[], int len){
    int A[mod];
    int B[mod];
    int Bp = 0;
    int probes[len];
    for (int i = 0; i < len; i++)
    {
        probes[i] = 0;        
    }
    for (int i = 0; i < mod; i++)
    {
        A[i] = -1;        
    }
    int a = hash[0]-'0';
    int b = hash[3]-'0';
    char o = hash[2];
    int u;
    for (int i = 0; i < len; i++)
    {
        u = o == '+' ? (a*arr[i]+b)%10 : (a*arr[i]-b)%10;
        int t = 0;
        for (int p = 0; p < mod; p++)
        {
            if (A[(u+p)%mod]==-1)
            {
                A[(u+p)%mod] = arr[i];
                t=1;
                probes[i] = p+1;
                break;
            }
        }
        if (!t)
        {
            B[Bp] = arr[i];
            Bp++;
        }   
    }

    for (int i = 0; i < mod; i++)
    {
        if (A[i]!=-1)
        {
            cout<<A[i]<<", ";
        }
        else{
            cout<<"_, ";
        }
    }
    cout<<endl;
    cout<<"Probes: ";
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<":"<<probes[i]<<", ";
    }
    cout<<endl;
    cout<<"Remaining Elements: ";
    for (int i = 0; i < Bp; i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
};

void quadraticProbing(int arr[], int mod, char hash[], int len){
    int A[mod];
    int B[mod];
    int Bp = 0;
    int probes[len];
    for (int i = 0; i < mod; i++)
    {
        A[i] = -1;        
    }
    for (int i = 0; i < len; i++)
    {
        probes[i] = 0;        
    }
    int a = hash[0]-'0';
    int b = hash[3]-'0';
    char o = hash[2];
    int u;
    for (int i = 0; i < len; i++)
    {
        u = o == '+' ? (a*arr[i]+b)%10 : (a*arr[i]-b)%10;
        int t = 0;
        for (int p = 0; p < mod; p++)
        {
            if (A[(u+p*p)%mod]==-1)
            {
                A[(u+p*p)%mod] = arr[i];
                t=1;
                probes[i] = p+1;
                break;
            }
        }
        if (!t)
        {
            B[Bp] = arr[i];
            Bp++;
        }   
    }

    for (int i = 0; i < mod; i++)
    {
        if (A[i]!=-1)
        {
            cout<<A[i]<<", ";
        }
        else{
            cout<<"_, ";
        }
    }
    cout<<endl;
    cout<<"Probes: ";
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<":"<<probes[i]<<", ";
    }
    cout<<endl;
    cout<<"Remaining Elements: ";
    for (int i = 0; i < Bp; i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
};

void doubleHashing(int arr[], int mod, char hash[], char hash2[], int len){
    int A[mod];
    int B[mod];
    int Bp = 0;
    int probes[len];
    for (int i = 0; i < mod; i++)
    {
        A[i] = -1;        
    }
    for (int i = 0; i < len; i++)
    {
        probes[i] = 0;        
    }
    int a = hash[0]-'0';
    int b = hash[3]-'0';
    char o = hash[2];
    int a2 = hash2[0]-'0';
    int b2 = hash2[3]-'0';
    char o2 = hash2[2];
    int u;
    int v;
    for (int i = 0; i < len; i++)
    {
        u = o == '+' ? (a*arr[i]+b)%10 : (a*arr[i]-b)%10;
        v = o2 == '+' ? (a2*arr[i]+b2)%10 : (a2*arr[i]-b2)%10;
        int t = 0;
        for (int p = 0; p < mod; p++)
        {
            if (A[(u+p*v)%mod]==-1)
            {
                A[(u+p*v)%mod] = arr[i];
                t=1;
                probes[i] = p+1;
                break;
            }
        }
        if (!t)
        {
            B[Bp] = arr[i];
            Bp++;
        }   
    }

    for (int i = 0; i < mod; i++)
    {
        if (A[i]!=-1)
        {
            cout<<A[i]<<", ";
        }
        else{
            cout<<"_, ";
        }
    }
    cout<<endl;
    cout<<"Probes: ";
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<":"<<probes[i]<<", ";
    }
    cout<<endl;
    cout<<"Remaining Elements: ";
    for (int i = 0; i < Bp; i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
};

int main()
{
    int arr[] = {3,2,9,6,11,13,7,12};
    int mod = 10;
    // char hash[] = {'a','x','+/-','b'};  where a, b are constants and x is variable
    char hash[] = {'2','k','+','3'};
    char hash2[] = {'3','k','+','1'};
    int len = sizeof(arr)/sizeof(int);

    cout<<"Chaining:"<<endl;
    chaining(arr, mod, hash, len);
    cout<<"Done Chaining\n"<<endl;

    cout<<"Linear Probing:"<<endl;
    linearProbing(arr, mod, hash, len);
    cout<<"Done Linear Probing\n"<<endl;

    cout<<"Quadratic Probing:"<<endl;
    quadraticProbing(arr, mod, hash, len);
    cout<<"Done Quadratic Probing\n"<<endl;

    cout<<"Double Hashing:"<<endl;
    doubleHashing(arr, mod, hash, hash2, len);
    cout<<"Done Double Hashing\n"<<endl;

    return 0;
}