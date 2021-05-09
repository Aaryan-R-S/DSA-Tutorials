#include<iostream>
using namespace std;

// This is with Operations:
// 1. traversal (done in t8.cpp using for loop) 
// 2. insert (done in t10.cpp)
// 3. delete (done in t11.cpp)
// 4. search
// 5. sort and many more...

class myArray {
    private:
        int total_size;
        int used_size;
        int *ptr ;
    public:
        myArray(){
            this->total_size = 10;
            this->used_size = 0;
            this->ptr = new int[this->total_size];
        };
        myArray(int total_size){
            this->total_size = total_size;
            this->used_size = 0;
            this->ptr = new int[this->total_size];
        };
        void set(int num){
            for (int i = 0; i < num; i++)
            {
                int n;
                printf("Enter the element at Index %d: ", i);
                scanf("%d", &n);
                this->ptr[i] = n;
            }
            this->used_size = num;
        };
        void setAt(int index){
            int n;
            if (index >= this->used_size){ 
                printf("Enter the element at Index %d: ", this->used_size);
                scanf("%d", &n);
                this->ptr[this->used_size] = n;
                this->used_size += 1;
            }
            else{
                printf("Enter the element at Index %d: ", index);
                scanf("%d", &n);
                this->ptr[index] = n;
            }
        };
        void get(){
            for (int i = 0; i < this->used_size; i++)
            {
                printf("%d ", this->ptr[i]);
            }
            printf("\n");
        };
        void getAt(int index){
            if (index>=this->used_size)
            {
                printf("No value at this index");
            }
            else{
                printf("%d ", this->ptr[index]);
            };
        };
        void insertAt(int index, int num){
            if (this->total_size == this->used_size)
            {
                printf("Array cannot hold any more entry..\n");
            }
            else{
                if (index<this->total_size){
                    for (int i = this->used_size; i > index; i--)
                    {
                        this->ptr[i] = this->ptr[i-1];
                    }
                    if(index<=this->used_size){
                        this->ptr[index] = num;
                    }
                    else{
                        this->ptr[this->used_size] = num;
                    }
                    this->used_size+=1;
                }
                else{
                    printf("Invalid Index...\n");
                }
            }
            
        };
        void deleteAt(int index){
            if (index>=this->used_size)
            {
                printf("No element at this Index...\n");
            }
            else{
                for (int i = index; i < this->used_size-1; i++)
                {
                    this->ptr[i] = this->ptr[i+1];
                }
                this->used_size-=1;
            }
            
        };
        int searchLinear(int num){
            for (int i = 0; i < this->used_size; i++)
            {
                if (num==this->ptr[i]){
                    return i;
                };
            };
            return -1;
        };
        int searchBinary(int num){
            int l=0, h=this->used_size-1, m; 
            while(l<=h){
                m = (l+h)/2;
                if (this->ptr[m]==num){
                    return m;
                }
                else if(this->ptr[m]<num){
                    l = m+1;
                }
                else{
                    h = m-1;
                }
            }
            return -1;
        };
        void reverseArr(){
            int temp;
            for (int i = 0; i < this->used_size/2; i++)
            {
                temp = this->ptr[i];
                this->ptr[i] = this->ptr[this->used_size-i-1];
                this->ptr[this->used_size-i-1] = temp;
            }
        };
};

int main()
{
    myArray marks1;   
    myArray marks2(10); 
    marks2.set(4);
    // marks2.set(5);

    int s;
    s = marks2.searchLinear(4);
    cout<<s<<endl;
    s = marks2.searchBinary(4);  // ARRAY MUST BE SORTED
    cout<<s<<endl;

    marks2.get(); 

    marks2.reverseArr();
    marks2.get(); 
    // Calculate len of array
    // int arr[] = {3,3,4,4,4};
    // int lenArr = sizeof(arr)/sizeof(int);
    // cout<<lenArr;

    return 0;
}