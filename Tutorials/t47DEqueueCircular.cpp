#include<iostream>
using namespace std;


class Queue{
    public:
        int size = 5;
        int start = -1;
        int end = -1;
        int* arr = new int[size];

    void display(bool reverse = false){
        if(!this->checkEmpty()){
            if(reverse==true){
                int i = this->end;
                while (i != this->start)
                {
                    printf("%d ", this->arr[i]);
                    i = (i-1)%this->size;
                }
                printf("%d ", this->arr[i]);
            }
            else{
                int i = this->start;
                while (i != this->end)
                {
                    printf("%d ", this->arr[i]);
                    i = (i+1)%this->size;
                }
                printf("%d ", this->arr[i]);
            }
            printf("\n");
        }
    };

    void peek(int n, bool reverse = false){
        if (reverse)
        {
            printf("%d", this->arr[(this->end-n+1)%this->size]);
        }
        else
        {
            printf("%d", this->arr[(n+this->start-1)%this->size]);
        }
        printf("\n");
    };

    bool checkEmpty(){
        if(this->end == -1 && this->start==-1){
            return 1;
        }
        return 0;
    };
    bool checkFull(){
        if(this->end == this->start-1 || (this->start==0 && this->end==this->size-1)){
            return 1;
        }
        return 0;
    };

    Queue* queue(int n, bool reverse = false){
        if(this->checkFull()){
            cout<<"It's Full!"<<endl;
            return this;
        }
        else if (this->start==-1 && this->end==-1){
            this->start = 0;
            this->end = 0;
            this->arr[this->start]=n;
            return this;
        }
        else if(reverse==false){
            this->end = this->end==this->size-1?0:this->end+1;
            this->arr[this->end] = n;
            return this;
        }
        else{
            this->start = this->start==0?this->size-1:this->start-1;
            this->arr[this->start] = n;
            return this;
        };
    };

    Queue* dequeue(bool reverse = false){
        if(this->checkEmpty()){
            cout<<"It's Empty!"<<endl;
            return this;
        }
        else if (this->start==this->end){
            this->start = -1;
            this->end = -1;
            return this;
        }
        else if(reverse==false){
            this->start = this->start==this->size-1?0:this->start+1;
            return this;
        }
        else{
            this->end = this->end==0?this->size-1:this->end-1;
            return this;
        }
    };

    int queueStart(){
        if(this->start==-1){
            printf("Queue is empty...\n");
        }
        else{
            return this->arr[this->start];
        }
        return -1;
    };

    int queueEnd(){
        if(this->end==-1){
            printf("Queue is empty...\n");
        }
        else{
            return this->arr[this->end];
        }
        return -1;
    };
};

int main()
{
    Queue* myQueue = new Queue();
    myQueue->dequeue();
    myQueue->queue(6);
    myQueue->queue(9);
    myQueue->queue(12, true);
    myQueue->queue(15);
    myQueue->queue(18);
    // myQueue->queue(21);
    myQueue->dequeue();
    myQueue->dequeue(true);
    // myQueue->queue(0);
    myQueue->display();
    myQueue->display(true);
    myQueue->peek(2);
    myQueue->peek(1, true);
    myQueue->queue(4, true);
    myQueue->dequeue(true);
    myQueue->display();
    return 0;
}