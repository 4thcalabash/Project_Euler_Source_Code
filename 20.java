import java.math.BigInteger;

public class Main {
    public static int digit_sum(BigInteger num){
        int ans = 0;
        while (!num.equals(BigInteger.ZERO)){
            ans += num.mod(BigInteger.valueOf(10)).longValue();
            num = num.divide(BigInteger.valueOf(10));
        }
        return ans;
    }
    public static void main(String[] args) {
        BigInteger num = BigInteger.ONE;
        for (int i=2;i<=100;i++){
            num = num.multiply(BigInteger.valueOf(i));
        }
        int ans = digit_sum(num);
        System.out.println(ans);
    }
}
