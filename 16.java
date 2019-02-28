import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        BigInteger num = BigInteger.ONE;
        num = num.shiftLeft(1000);
        int ans = 0;
        while (!num.equals(BigInteger.ZERO)){
            ans += num.mod(BigInteger.valueOf(10)).longValue();
            num = num.divide(BigInteger.valueOf(10));
        }
        System.out.println(ans);
    }
}
