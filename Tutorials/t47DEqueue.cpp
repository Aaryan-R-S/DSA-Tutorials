#include<iostream>
using namespace std;


class Queue{
    public:
        int size = 20;
        int start = -1;
        int end = -1;
        int* arr = new int[size];

    void display(bool reverse = false){
        if(reverse==true){
            int i = this->end;
            while (i >= this->start+1)
            {
                printf("%d ", this->arr[i]);
                i--;
            }
        }
        else{
            int i = this->start+1;
            while (i <= this->end)
            {
                printf("%d ", this->arr[i]);
                i++;
            }
        }
        printf("\n");
    };

    void peek(int n, bool reverse = false){
        if (reverse)
        {
            printf("%d", this->arr[this->end-n+1]);
        }
        else
        {
            printf("%d", this->arr[n+this->start]);
        }
        printf("\n");
    };

    bool checkEmpty(){
        if(this->end == this->start){
            return 1;
        }
        return 0;
    };
    bool checkFull(bool reverse = false){
        if(this->end == this->size-1 || (this->start<=-1 && reverse)){
            return 1;
        }
        return 0;
    };

    Queue* queue(int n, bool reverse = false){
        if(this->checkFull(reverse)){
            cout<<"It's Full or Not posssible in this direction!"<<endl;
            return this;
        }
        if(reverse==true){
            this->arr[start] = n;
            this->start--;
            return this;
        }
        else{
            this->end++;
            this->arr[end] = n;
            return this;
        };
    };

    Queue* dequeue(bool reverse = false){
        if(this->checkEmpty()){
            cout<<"It's Empty!"<<endl;
            return this;
        }
        if(reverse==false){
            this->start++;
            return this;
        }
        else{
            this->end--;
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
    myQueue->queue(12);
    myQueue->queue(15);
    myQueue->dequeue();
    myQueue->queue(0);
    myQueue->display();
    myQueue->display(true);
    myQueue->peek(2);
    myQueue->peek(1, true);
    myQueue->dequeue();
    myQueue->dequeue();
    myQueue->queue(4, true);
    myQueue->dequeue(true);
    myQueue->display();
    return 0;
}