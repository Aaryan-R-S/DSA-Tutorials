import java.math.BigInteger;
import java.util.*;

public class sol_3 {
    private static int gcdThing(int a, int b) {
        BigInteger b1 = BigInteger.valueOf(a);
        BigInteger b2 = BigInteger.valueOf(b);
        BigInteger gcd = b1.gcd(b2);
        return gcd.intValue();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0){
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(
                gcdThing(Math.abs(a), Math.abs(b))
            );
            t--;
        }
        sc.close();
    }
}