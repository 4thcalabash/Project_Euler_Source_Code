import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args){
        try {
            File tmp = new File("");
            System.out.println(tmp.getAbsolutePath());
            BufferedReader input = new BufferedReader(new FileReader("src/input"));
            BigInteger sum = BigInteger.ZERO;
            String line = null;
            while ((line  = input.readLine()) != null){
                BigInteger temp = new BigInteger(line);
                System.out.println(temp);
                sum = sum.add(temp);

            }
            System.out.println(sum);
            String s = sum.toString(10);
            System.out.println(s);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
