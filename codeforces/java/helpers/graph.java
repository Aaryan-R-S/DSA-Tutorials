package helpers;
import java.util.*;

class Graph{
    private int V;
    private ArrayList<ArrayList<Integer>> adj;

    Graph(int v){
        this.V = v;
        this.adj = new ArrayList<ArrayList<Integer>>(this.V);
        for (int i = 0; i < this.V; i++) {
            this.adj.add(new ArrayList<Integer>());
        }
    }

    void addEdgeD(int x, int y){
        // this.adj.get(x).add(y);
        // OR
        if(!this.adj.get(x).contains(y)){
            this.adj.get(x).add(y);
        }
    }

    void addEdgeU(int x, int y){
        // this.adj.get(x).add(y);
        // OR
        if(!this.adj.get(x).contains(y)){
            this.adj.get(x).add(y);
        }
        if(!this.adj.get(y).contains(x)){
            this.adj.get(y).add(x);
        }
    }

    void removeEdge(int x, int y){
        Iterator<Integer> it = this.adj.get(x).iterator();
        while(it.hasNext()){
            Integer n = it.next();
            if(n==y){
                it.remove();
            }
        }
    }

    void bfs(int src){
        boolean vis[] = new boolean[this.V];
        for (int i = 0; i < vis.length; i++) {
            vis[i] = false;
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        vis[src] = true;
        while(!q.isEmpty()){
            int top = q.poll();
            System.out.print(top+" ");
            for (Integer i : this.adj.get(top)) {
                if(!vis[i]){
                    q.add(i);
                    vis[i] = true;
                }
            }
        }
        System.out.println();
    }

    void dfsHelper(int x, boolean vis[]){
        if(!vis[x]){
            vis[x] = true;
            System.out.print(x+" ");
            for (Integer i : this.adj.get(x)) {
                if(!vis[i]){
                    dfsHelper(i, vis);
                }
            }
        }
    }

    void dfs(int src){
        boolean vis[] = new boolean[this.V];
        for (int i = 0; i < vis.length; i++) {
            vis[i] = false;
        }
        dfsHelper(src, vis);
        System.out.println();
    }

    void getComponents(){
        boolean vis[] = new boolean[this.V];
        for (int i = 0; i < vis.length; i++) {
            vis[i] = false;
        }
        Queue<Integer> q = new LinkedList<>();
        int comp = 0;
        for (int k = 0; k < vis.length; k++) {
            if(!vis[k]){
                comp++;
                System.out.print((comp)+" -> ");
                q.add(k);
                vis[k] = true;
                while(!q.isEmpty()){
                    int top = q.poll();
                    System.out.print(top+" ");
                    for (Integer i : this.adj.get(top)) {
                        if(!vis[i]){
                            q.add(i);
                            vis[i] = true;
                        }
                    }
                }
                System.out.println();
            }
        }
    }

    void distancebfs(int src, int dist[]){
        boolean vis[] = new boolean[this.V];
        for (int i = 0; i < vis.length; i++) {
            vis[i] = false;
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        vis[src] = true;
        int curr = 0;
        while(!q.isEmpty()){
            int l = q.size();
            for (int j = 0; j < l; j++) {
                int top = q.poll();
                dist[top] = curr;
                for (Integer i : this.adj.get(top)) {
                    if(!vis[i]){
                        q.add(i);
                        vis[i] = true;
                    }
                }
            }
            curr++;
        }
    }

    void tpshelper(int x, boolean vis[], Stack<Integer> s){
        vis[x] = true;
        for (Integer i : this.adj.get(x)) {
            if(!vis[i]){
                tpshelper(i, vis, s);
            }
        }
        s.push(x);
    }

    void tps(){
        Stack<Integer> s = new Stack<>();
        boolean vis[] = new boolean[this.V];
        for (int i = 0; i < vis.length; i++) {
            vis[i] = false;
        }
        for (int i = 0; i < this.V; i++) {
            if(!vis[i]){
                tpshelper(i, vis, s);
            } 
        }
        while(!s.empty()){
            System.out.print(s.pop()+" ");
        }
        System.out.println();
    }

    boolean isBipartite(){
        int col[] = new int[this.V];
        for (int i = 0; i < this.V; i++) {
            col[i] = -1;
        }
        int curr = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int j = 0; j < this.V; j++) {
            curr = 0;
            if(col[j]==-1){
                q.add(j);
                col[j] = curr;
                while(!q.isEmpty()){
                    int top = q.poll();
                    curr = col[top];
                    for (Integer i : this.adj.get(top)) {
                        if(col[i]==curr){
                            return false;
                        }
                        if(col[i]==-1){
                            q.add(i);
                            col[i] = 1-curr;
                        }
                    }
                }
            }
        }
        return true;
    }

}
