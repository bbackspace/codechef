import java.io.*;
import java.math.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		while(T-- > 0)
		{
			int x = Integer.parseInt(in.readLine());
			BigInteger f = BigInteger.valueOf(1);
			for(int i = 2; i <= x; ++i)
			{
				f = f.multiply(BigInteger.valueOf(i));
			}
			System.out.println(f);
		}
		in.close();
	}
} 