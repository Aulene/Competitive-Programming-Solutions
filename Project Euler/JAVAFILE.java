import java.math.*;

public class JAVAFILE
{
	public static void main(String[] args) {
		BigInteger m = new BigInteger("1");

		for(Integer i = 1; i <= 100; i++) {
			BigInteger x = new BigInteger("" + i);
			m = m.multiply(x);
		}


		String sx = m.toString();
		System.out.println(sx);
		
		int ans = 0;

		for(int i = 0; i < sx.length(); i++) {
			ans += (sx.charAt(i) - '0');
		}

		System.out.println(ans);
	}
}