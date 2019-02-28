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
    public static final int maxn = 45;
    public static BigInteger [][] C = new BigInteger[maxn][maxn];
    public static void main(String[] args) {
        C[0][0] = BigInteger.ONE;
        for (int i=1;i<maxn;i++){
            C[i][0] = BigInteger.ONE;
            C[i][i] = BigInteger.ONE;
            for (int j=1;j<i;j++){
                C[i][j] = C[i-1][j].add(C[i-1][j-1]);
            }
        }
        System.out.println(C[40][20].toString(10));
    }
}
