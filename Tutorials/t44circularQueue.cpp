#include<iostream>
using namespace std;


class Queue{
    public:
        int size = 5;
        int start = 0;
        int end = 0;
        int* arr = new int[size];

    void display(bool reverse = false){
        if(reverse==true){
            int i = this->end-1;
            while (i >= this->start)
            {
                printf("%d ", this->arr[i%this->size]);
                i--;
            }
        }
        else{
            int i = this->start;
            while (i < this->end)
            {
                printf("%d ", this->arr[i%this->size]);
                i++;
            }
        }
        printf("\n");
    };

    void peek(int n, bool reverse = false){
        if (reverse)
        {
            printf("%d", this->arr[(this->end-n)%this->size]);
        }
        else
        {
            printf("%d", this->arr[n-1+(this->start)%this->size]);
        }
        printf("\n");
    };

    bool checkEmpty(){
        if(this->end == this->start){
            return 1;
        }
        return 0;
    };
    
    bool checkFull(){
        if(this->end == this->start+5){
            return 1;
        }
        return 0;
    };

    Queue* queue(int n){
        if(this->checkFull()){
            cout<<"It's Full!"<<endl;
            return this;
        }
        else{
            this->arr[this->end%this->size] = n;
            this->end++;
            return this;
        };
    };

    Queue* dequeue(){
        if(this->checkEmpty()){
            cout<<"It's Empty!"<<endl;
            return this;
        }
        else{
            this->start++;
            return this;
        };
    };

    int queueStart(){
        if(this->checkEmpty()){
            printf("Queue is empty...\n");
        }
        else{
            return this->arr[this->start%this->size];
        }
        return -1;
    };

    int queueEnd(){
        if(this->checkEmpty()){
            printf("Queue is empty...\n");
        }
        else{
            return this->arr[(this->end-1)%this->size];
        }
        return -1;
    };
};

int main()
{
    Queue* myQueue = new Queue();
    myQueue->dequeue();
    myQueue->queue(-3);
    myQueue->queue(3);
    myQueue->queue(6);
    myQueue->queue(9);
    myQueue->queue(12);
    myQueue->queue(15);
    myQueue->display();
    myQueue->dequeue();
    myQueue->dequeue();
    myQueue->dequeue();
    myQueue->dequeue();
    myQueue->dequeue();
    myQueue->dequeue();
    myQueue->queue(15);
    myQueue->queue(18);
    myQueue->queue(21);
    myQueue->queue(24);
    myQueue->queue(27);
    myQueue->queue(0);
    myQueue->display();
    myQueue->display(true);
    myQueue->peek(2);
    myQueue->peek(1, true);  //132
    myQueue->display();
    cout<<myQueue->queueStart()<<endl;
    cout<<myQueue->queueEnd()<<endl;  //1r23
    return 0;
}