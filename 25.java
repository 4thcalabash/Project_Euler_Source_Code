import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger f1 = BigInteger.ONE;
        BigInteger f2 = BigInteger.ONE;
        BigInteger limit = BigInteger.ONE;
        for (int i=1;i<1000;i++){
            limit = limit.multiply(BigInteger.valueOf(10));
        }
        int idx = 2;
        while (f2.compareTo(limit) <0){
            BigInteger f3 = f2.add(f1);
            f1 = f2;
            f2 = f3;
            idx ++;
        }
        System.out.println(idx);
    }
}
