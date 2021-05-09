#include<iostream>
using namespace std;

// This is with Operations:
// 1. traversal (done in t8.cpp using for loop) 
// 2. insert 
// 3. delete
// 4. serach
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
        void insert(int index, int num){
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
};

int main()
{
    myArray marks1;   
    myArray marks2(10); 
    // myArray marks2(5); 
    marks2.set(5);
    marks2.get();  
    // marks2.insert(0,-1);
    // marks2.insert(10,0);
    // marks2.insert(4,-3);
    marks2.insert(5,-4);
    // marks2.insert(7,4);
    marks2.get();  
 
    return 0;
}