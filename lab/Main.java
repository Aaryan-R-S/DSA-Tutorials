import java.util.*;

public class Main {
    static void solve(){

    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int t = sc.nextInt();
        int t=1;
        while(t>0){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            solve();
            t--;
        }
        sc.close();
    }
}