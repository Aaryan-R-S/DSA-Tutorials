import java.util.*;

public class sol_3 {    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];
        int arr_xor = 0;

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            arr_xor ^= arr[i];
        }
        
        int t = sc.nextInt();
        System.out.println(Integer.bitCount(t^arr_xor));
    
        sc.close();
    }
}