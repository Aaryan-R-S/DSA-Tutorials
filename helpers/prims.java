package helpers;
import java.util.*;

class Prims{
    int V;
    int arr[][];

    Prims(int v){
        this.V = v;
        this.arr = new int[v][v];
        for (int i = 0; i < this.V; i++) {
            for (int j = 0; j < this.V; j++) {
                this.arr[i][j] = 0;
            }
        }
    }

    void addEdgeU(int x, int y, int wt){
        this.arr[x][y] = wt;
        this.arr[y][x] = wt;
    }
    
    void addEdgeD(int x, int y, int wt){
        this.arr[x][y] = wt;
    }

    int minElem(int key[], boolean vis[]){
        int minIdx = -1;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < this.V; i++) {
            if(!vis[i] && key[i]<ans){
                ans = key[i];
                minIdx = i;
            }
        }
        return minIdx;
    }

    void prims(int src){
        int key[] = new int[this.V]; 
        int parent[] = new int[this.V]; 
        boolean vis[] = new boolean[this.V];
        for (int i = 0; i < vis.length; i++) {
            vis[i] = false;
            key[i] = Integer.MAX_VALUE;
            parent[i] = -1;
        }
        parent[src] = -1;
        key[src] = 0;
        for (int j = 0; j < this.V-1; j++) {
            int minV = minElem(key, vis);
            vis[minV] = true;
            for (int i = 0; i < this.V; i++) {
                if(this.arr[minV][i]!=0 && !vis[i] && this.arr[minV][i]<key[i]){
                       parent[i] = minV;
                       key[i] = this.arr[minV][i];
                }
            }
        }
        for (int i = 1; i < vis.length; i++) {
            System.out.println(parent[i]+"->"+i+" "+this.arr[parent[i]][i]);
        }
    }

    void dijkstra(int src){
        int dist[] = new int[this.V]; 
        boolean vis[] = new boolean[this.V];
        for (int i = 0; i < vis.length; i++) {
            vis[i] = false;
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        for (int j = 0; j < this.V-1; j++) {
            int minV = minElem(dist, vis);
            vis[minV] = true;
            for (int i = 0; i < this.V; i++) {
                if(this.arr[minV][i]!=0 && !vis[i] && dist[minV] != Integer.MAX_VALUE && dist[minV]+this.arr[minV][i] < dist[i]){
                    dist[i] = dist[minV]+this.arr[minV][i]; 
                }
            }
        }
        for (int i = 0; i < vis.length; i++) {
            System.out.println(i+" "+dist[i]);
        }
    }

}
