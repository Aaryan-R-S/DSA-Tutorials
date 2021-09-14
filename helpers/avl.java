package helpers;
import java.util.*;

class avl {
    class Node{
        int key;
        Node left;
        Node right;
        int height;
        int size;
        Node(int key){
            this.key = key;
            this.left = null;
            this.right = null;
            this.height = 1;
            this.size = 1;
        }
    };
    
    Node root = null;
    
    void preorder(Node n){
        if(n!=null){
            System.out.print(n.key+" ");
            preorder(n.left);
            preorder(n.right);
        }
    }
    
    void inorder(Node n){
        if(n!=null){
            inorder(n.left);
            System.out.print(n.key+" ");
            inorder(n.right);
        }
    }
    
    int getSize(Node n){
        if(n==null){
            return 0;
        }
        return n.size;
    }
    
    int getHeight(Node n){
        if(n==null){
            return 0;
        }
        return n.height;
    }
    
    int getBalance(Node n){
        if(n==null){
            return 0;
        }
        return getHeight(n.right) - getHeight(n.left);
    }
    
    Node RR(Node y){
        Node x = y.right;
        Node t = x.left;
    
        // main rotations
        x.left = y;
        y.right = t;
    
        // reset height of changed pointers
        y.height = 1 + Integer.max(getHeight(y.left), getHeight(y.right));
        x.height = 1 + Integer.max(getHeight(x.left), getHeight(x.right));
    
        // reset size of changed pointers
        y.size = 1 + getSize(y.left) + getSize(y.right);
        x.size = 1 + getSize(x.left) + getSize(x.right);
    
        // return new parent
        return x;
    }
    
    Node LL(Node y){
        Node x = y.left;
        Node t = x.right;
    
        // main rotations
        x.right = y;
        y.left = t;
    
        // reset height of changed pointers
        y.height = 1 + Integer.max(getHeight(y.left), getHeight(y.right));
        x.height = 1 + Integer.max(getHeight(x.left), getHeight(x.right));
    
        // reset size of the changed pointers
        y.size = 1 + getSize(y.left) + getSize(y.right);
        x.size = 1 + getSize(x.left) + getSize(x.right);
    
        // return new parent
        return x;
    }
    
    Node balance(Node n, int key){
        int balanceFactor = getBalance(n);
        // RR Case
        if(balanceFactor>1 && key > n.right.key){
            return RR(n);
        }
        // LL Case
        else if(balanceFactor<-1 && key < n.left.key){
            return LL(n);
        }
        // RL Case
        else if(balanceFactor>1 && key < n.right.key){
            n.right = LL(n.right);
            return RR(n);
        }
        // LR Case
        else if(balanceFactor<-1 && key > n.left.key){
            n.left = RR(n.left);
            return LL(n);
        }
        return n;
    }
    
    Node insert(Node n, int key){
        if(n==null){
            Node t = new Node(key);
            return t;
        }
        else if(n.key > key){
            n.left = insert(n.left, key);
        }
        else if(n.key < key){
            n.right = insert(n.right, key);
        }
        else{
            return n;
        }
        n.height = 1 + Integer.max(getHeight(n.left), getHeight(n.right));
        n.size = 1 + getSize(n.left) + getSize(n.right);
        return balance(n, key);
    }
    
    Node balanceDel(Node n){
        int balanceFactor = getBalance(n);
        int balanceLeft = getBalance(n.left);
        int balanceRight = getBalance(n.right);
        // RR Case
        if(balanceFactor>1 && balanceRight>=0){
            return RR(n);
        }
        // LL Case
        else if(balanceFactor<-1 && balanceLeft<=0){
            return LL(n);
        }
        // RL Case
        else if(balanceFactor>1 && balanceRight<0){
            n.right = LL(n.right);
            return RR(n);
        }
        // LR Case
        else if(balanceFactor<-1 && balanceLeft>0){
            n.left = RR(n.left);
            return LL(n);
        }
        return n;
    }
    
    Node deleteNode(Node n, int key){
        if(n==null){
            return n;
        }
        else if(key > n.key){
            n.right = deleteNode(n.right, key);
        }
        else if(key < n.key){
            n.left = deleteNode(n.left, key);
        }
        else{
            if(n.left==null || n.right==null){
                Node t = (n.right!=null) ? n.right : n.left;
                if(t==null){
                    t = n;
                    n = null;
                }
                else{
                    n = t;    // copy the values from t to n
                }
                // free(t);     // free n or t
            }
            else{
                Node t = n.right;
                while (t.left!=null)
                {
                    t = t.left;
                }
                n.key = t.key;
                n.right = deleteNode(n.right, t.key);
            }
        }
        if(n==null){
            return n;
        }
        n.height = 1 + Integer.max(getHeight(n.left), getHeight(n.right));
        n.size = 1 + getSize(n.left) + getSize(n.right);
    
        return balanceDel(n);
    }
    
    int alpha(Node n, boolean isMax){
        if(n==null){
            return -1;
        }
        Node p = n;
        if(isMax){
            while(p.right!=null){
                p = p.right;
            }
            int maxElem = p.key;
            root = deleteNode(n, maxElem);
            return maxElem;
        }
        else{
            while(p.left!=null){
                p = p.left;
            }
            int minElem = p.key;
            root = deleteNode(n, minElem);
            return minElem;
        }
    }
    
    int beta(Node n, int k){
        if(n==null){
            return -1;
        }
        int idx = k;
        Node p = n;
        while(p!=null){
            if(idx==(getSize(p.left)+1)){
                int kthSmallElem = p.key;
                root = deleteNode(n, kthSmallElem);
                return kthSmallElem;
            }
            else if(idx < (getSize(p.left)+1)){
                p = p.left;
            }
            else{
                idx = idx-(getSize(p.left)+1);
                p = p.right;
            }
        }
        return -1;
    }
    
    int gamma(Node n){
        if(n==null){
            return -1;
        }
        int idx = (getSize(n)+1)/2;
        Node p = n;
        while(p!=null){
            if(idx==getSize(p.left)+1){
                int median = p.key;
                root = deleteNode(n, median);
                return median;
            }
            else if(idx < getSize(p.left)+1){
                p = p.left;
            }
            else{
                idx = idx-(getSize(p.left)+1);
                p = p.right;
            }
        }
        return -1;
    }
        
}
