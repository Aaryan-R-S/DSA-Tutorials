#include<iostream>
using namespace std;

int main()
{
    // FIND LEN OF LONGEST WORD IN A SENTENCE AND PRINT IT
    // like string : char-array also ends in a null character \0
    int n;
    cin>>n;
    cin.ignore();

    char arr[n+1]; // nth place for null char
    cin.getline(arr, n);
    cin.ignore();  // imp if using getline func

    int i = 0;
    int currlen = 0, maxlen = 0;
    int st = 0, maxst = 0;

    while (true)
    {
        if(arr[i]==' ' || arr[i] == '\0'){
            if (currlen > maxlen)
            {
                maxlen = currlen;
                maxst = st;
            }
            currlen = 0;
            st = i+1;
        }
        else{
            currlen++;
        }

        if(arr[i]=='\0'){
            break;
        }

        i++;
    }

    cout<<maxlen<<endl;
    for (int i = 0; i < maxlen; i++)
    {
        cout<<arr[i+maxst];
    }
    cout<<endl;

    return 0;
}