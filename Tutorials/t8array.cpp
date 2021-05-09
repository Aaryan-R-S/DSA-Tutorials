#include<iostream>
using namespace std;

// For array of size n:
// No. of sub-array (continuous part of array) = n*(n+1)/2 = nC2 + n
// No. of sub-sequences (non-continuous part of array) = 2^n

// This is with minimum Required Functionalities:
// 1. set 
// 2. get 

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
};

int main()
{
    myArray marks1;   
    myArray marks2(5); 
    marks2.set(2);
    marks2.setAt(0);
    marks2.setAt(2);
    marks2.setAt(3);
    marks2.setAt(4);
    marks2.get();  
    marks2.getAt(0);  
    marks2.getAt(2);  
    marks2.getAt(3);  
    marks2.getAt(4);  
    return 0;
}