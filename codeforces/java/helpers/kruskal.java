package helpers;

import java.util.Arrays;

class kruskal {
    static class Graph{
        private int V, E, top;

        class DSU{
            int parent, size;
        }

        class Edge implements Comparable<Edge>{
            int src, dest, wt;
            public int compareTo(Edge e2){
                return this.wt-e2.wt;
            }
        }

        Edge edges[];

        Graph(int v, int e){
            this.V = v;
            this.E = e;
            this.top = 0;
            edges = new Edge[this.E];
            for (int i = 0; i < edges.length; i++) {
                edges[i] = new Edge();
            }
        }

        void make_set(int idx, DSU mySets[]){
            mySets[idx].parent = idx;
            mySets[idx].size = 1;
        }

        int find_set(int idx, DSU mySets[]){
            if(mySets[idx].parent==idx)
                return idx;
            return mySets[idx].parent = find_set(mySets[idx].parent, mySets);
        }

        void union_sets(DSU mySets[], int a, int b){
            a = find_set(a, mySets);
            b = find_set(b, mySets);
            if(a!=b){
                if(mySets[a].size<mySets[b].size){
                    int temp = a;
                    a = b;
                    b = temp;
                }
                mySets[b].parent = a;
                mySets[a].size += mySets[b].size;
            }
        }
        
        void kruskal(){
            Edge ans[] = new Edge[this.V];
            for (int i = 0; i < ans.length; i++) {
                ans[i] = new Edge();
            }
            Arrays.sort(this.edges);
            DSU mySets[] = new DSU[this.V];
            for (int idx = 0; idx < mySets.length; idx++) {
                mySets[idx] = new DSU();
                make_set(idx, mySets);
            }
            int count = 0;
            int curr = 0;
            while(curr<this.V-1){
                Edge myEdge = edges[count];
                count++;
                int a = find_set(myEdge.src, mySets);
                int b = find_set(myEdge.dest, mySets);
                if(a==b){
                    continue;
                }
                else{
                    ans[curr] = myEdge;
                    union_sets(mySets, a, b); 
                    curr++;
                }
            }
            System.out.println("MST");
            int minCost = 0;
            for (int i = 0; i < curr; i++) {
                System.out.println(ans[i].src+" "+ans[i].dest+" "+ans[i].wt);
                minCost += ans[i].wt;
            }
            System.out.println(minCost);
        }   

        // undirected graph
        void addEdge(int u, int v, int w){
            this.edges[this.top].src = u;
            this.edges[this.top].dest = v;
            this.edges[this.top].wt = w;
            this.top++;
        }

        void detectCycle(){
            DSU mySets[] = new DSU[this.V];
            for (int idx = 0; idx < mySets.length; idx++) {
                mySets[idx] = new DSU();
                make_set(idx, mySets);
            }
            int count = 0;
            int curr = 0;
            boolean found = false;
            while(curr<this.E){
                Edge myEdge = edges[count];
                count++;
                int a = find_set(myEdge.src, mySets);
                int b = find_set(myEdge.dest, mySets);
                if(a==b){
                    found = true;
                }
                else{
                    union_sets(mySets, a, b); 
                    curr++;
                }
                if(found){
                    break;
                }
            }
            if(found){
                System.out.println("Yes");
            }
            else{
                System.out.println("No");
            }
        }   
        
    }
}
