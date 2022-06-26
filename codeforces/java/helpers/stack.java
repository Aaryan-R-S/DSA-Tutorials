package helpers;

class stack{
    static class Stack{
        int size;
        long arr[];
        int idx;
        Stack(){
            this.size = 1000002;
            this.arr = new long[size];
            this.idx = 0;
        }
    }
    static Stack myStack = new Stack();
    static void push(long num){
        if(myStack.idx==myStack.size){
            return;
        }
        myStack.arr[myStack.idx] = num;
        myStack.idx++;
    }
    static void pop(){
        if(myStack.idx==0){
            return;
        }
        myStack.idx--;
    }
}