package helpers;
import java.util.*;

class DLL{
    class Node{
        int num;
        Node pre;
        Node nxt;
        Node(int num){
            this.num = num;
            this.pre = null;
            this.nxt = null;
        }
    }
    
    Node head = null;
    Node tail= null;

    boolean checkEmpty(){
        if(this.head==null || this.tail==null){
            return true;
        }
        return false;
    }

    void printList() 
    { 
        if(this.checkEmpty()){
            return;
        }
        Node e = this.head;
        while(e != null){
            System.out.print(e.num+" ");
            e = e.nxt;
        }
        System.out.println();
    };
    
    void printListRev() 
    { 
        if(this.checkEmpty()){
            return;
        }
        Node e = this.tail;
        while(e != null){
            System.out.print(e.num+" ");
            e = e.pre;
        }
        System.out.println();
    };

    void insertAtFirst(int num) 
    { 
        Node e = new Node(num);
        e.nxt = this.head;
        e.pre = null;
        
        if(this.head!=null){
            this.head.pre = e;
            this.head = e;  
        }
        else{
            this.head = e;
            this.tail = e;
        }
        
    };
    
    void insertAtLast(int num) 
    { 
        Node e = new Node(num);
        e.nxt = null;
        e.pre = this.tail;
        
        if(this.tail!=null){
            this.tail.nxt = e;
            this.tail = e;  
        }
        else{
            this.head = e;
            this.tail = e;
        }
        
    };

    void insertAfter(Node n, int num) 
    { 
        if(this.checkEmpty()){
            return;
        }
        Node e = new Node(num);
        Node f = n.nxt;

        e.nxt = f;
        e.pre = n;

        if(f!=null){
            f.pre = e;
        }
        n.nxt = e;
    };

    void deleteFirst() 
    { 
        if(this.checkEmpty()){
            return;
        }
        Node e = this.head;
        Node p = head.nxt;
        this.head = p;
        if(this.head==null){
            this.tail = null;
        }
        else{
            p.pre = null;
        }
    };
    
    void deleteLast() 
    { 
        if(this.checkEmpty()){
            return;
        }
        Node e = this.tail;
        Node f = this.tail.pre;
        this.tail = f;
        if(this.tail==null){
            this.head = null;
        }
        else{
            f.nxt = null;
        }
    };
    
    void deleteVal(int val) 
    { 
        if(this.checkEmpty()){
            return;
        }
        if(this.head.num==val){
            this.deleteFirst();
            return;
        }
        if(this.tail.num==val){
            this.deleteLast();
            return;
        }
        Node e = this.head;
        Node f = e.nxt;
        while (f != null && f.num != val)
        {
            e = e.nxt;
            f = f.nxt;
        }
        if(f==null){
            return;
        }
        Node k = f.nxt;
        e.nxt = k;
        k.pre = e; 
    };

    void reverseLinkedList(){
        if(this.checkEmpty()){
            return;
        }
        this.tail = this.head;
        Node prevNode = null;
        Node currentNode = this.head;
        Node nextNode = null;
        while (currentNode != null)
        {
            nextNode = currentNode.nxt;
            currentNode.nxt = currentNode.pre;
            currentNode.pre = nextNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        this.head = prevNode; 
    };

}