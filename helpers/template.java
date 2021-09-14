package helpers;
import java.util.*;

class template {

    static void solve(){
        
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int t = sc.nextInt();
        int t=1;
        while(t>0){
            int n = sc.nextInt();   
            int arr[] = new int[n];
            int nn=0;
            while(nn!=n){
                arr[nn] = sc.nextInt();    // price of ith taxi
                nn++;
            }
            solve();
            t--;
        }
        sc.close();
    }
}