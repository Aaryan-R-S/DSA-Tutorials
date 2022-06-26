package helpers;
import java.util.*;

class queue {
    int limit = 10;
    int arr[] = new int[this.limit];
    int size = 0, front = -1, rear = -1;

    void display(){
        if(isEmpty()){
            System.out.println();
            return;
        }
        for (int i = 0; i < this.size; i++) {
            System.out.print(this.arr[(this.front+i)%this.limit]+" ");
        }System.out.println();
    }
    boolean isEmpty(){
        return this.size==0;
    }

    boolean isFull(){
        return this.size == this.limit;
    }

    int getF(){
        if(this.isEmpty()){
            return -1;
        }
        return this.arr[this.front];
    }
    
    int getR(){
        if(this.isEmpty()){
            return -1;
        }
        return this.arr[this.rear];
    }

    void insertF(int key){
        if(this.isFull()){
            return;
        }
        if(this.isEmpty()){
            this.front = 0;
            this.rear = 0;
            this.arr[0] = key;
            this.size = 1;
            return;
        }
        this.front = (this.front == 0 ? this.limit-1 : this.front-1);
        this.arr[this.front] = key;
        this.size += 1;
        return;
    }
    
    void insertR(int key){
        if(this.isFull()){
            return;
        }
        if(this.isEmpty()){
            this.front = 0;
            this.rear = 0;
            this.arr[0] = key;
            this.size = 1;
            return;
        }
        this.rear = (this.rear == this.limit-1 ? 0 : this.rear+1);
        this.arr[this.rear] = key;
        this.size += 1;
        return;
    }

    void deleteF(){
        if(this.isEmpty()){
            return;
        }
        if(this.size==1){
            this.front = -1;
            this.rear = -1;
            this.size = 0;
            return;
        }
        this.front = (this.front == this.limit-1 ? 0 : this.front+1);
        this.size -= 1;
        return;
    }
    
    void deleteR(){
        if(this.isEmpty()){
            return;
        }
        if(this.size==1){
            this.front = -1;
            this.rear = -1;
            this.size = 0;
            return;
        }
        this.rear = (this.rear == 0 ? this.limit-1 : this.rear-1);
        this.size -= 1;
        return;
    }
}