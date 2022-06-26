package helpers;
import java.util.*;
    
class heap {
    int arr[] = new int[100000];
    int len = 0;

    void maxHeapify(int len, int index){
        int largest = index;
        int left = (2*index)+1;
        int right = (2*index)+2;
        if (left<len && this.arr[left]>this.arr[largest])
        {
            largest = left;
        }
        if (right<len && this.arr[right]>this.arr[largest])
        {
            largest = right;
        }
        if(largest != index){
            int temp = this.arr[largest];
            this.arr[largest] = this.arr[index];
            this.arr[index] = temp;
            maxHeapify(len, largest);
        }
    };

    void buildHeap(){
        // BUILD MAX HEAP starting from last non-leaf index
        for (int i = (this.len/2)-1; i >=0; i--)
        {
            maxHeapify(this.len, i);
        }
    };

    void heapSort(){
        // BUILD MAX HEAP starting from last non-leaf index
        for (int i = (this.len/2)-1; i >=0; i--)
        {
            maxHeapify(this.len, i);
        }
    
        // Delete MAX HEAP head and push it to the end of array being maxHeapified
        int temp;
        for (int i = this.len-1; i>=1; i--)
        {
            temp = this.arr[0];
            this.arr[0] = this.arr[i];
            this.arr[i] = temp;
            maxHeapify(i, 0);
        }
    };
    
    void insert(int elem){
        this.arr[this.len] = elem;
        this.len++;
        int idx = this.len-1;
        int parent = (idx-1)/2;
        while(parent>=0){
            if(this.arr[idx]>this.arr[parent]){
                int temp = this.arr[idx];
                this.arr[idx] = this.arr[parent];
                this.arr[parent] = temp;
                idx = parent;
                parent = (idx-1)/2;
            }
            else{
                break;
            }
        }
    }
    
    int extractMax(){
        if(this.len==0){
            return -1;
        }
        this.len--;
        int maxElem = arr[0];
        arr[0] = arr[this.len];
        arr[this.len] = 0;
        maxHeapify(this.len, 0);
        return maxElem;
    }
    
    void decreaseKey(int idx, int k){
        if(k>this.arr[idx]){
            return; 
        }
        this.arr[idx] -= k;
        maxHeapify(this.len, idx);
    }
    
}
