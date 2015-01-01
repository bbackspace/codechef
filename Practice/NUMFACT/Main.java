import java.io.*;
import java.util.*;

public class Main
{
	static ArrayList factors;
	public static void main(String[] args) throws IOException
	{
		factors = new ArrayList();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		while(T-- > 0)
		{
			int N = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			int x;
			for(int i = 0; i < N; ++i)
				x = Integer.parseInt(st.nextToken());
			
			System.out.println(x);
		}
		in.close();
	}
} 