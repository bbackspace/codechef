import java.io.*;
import java.util.*;

public class Main
{
	static int DP[][];
	public static void main(String[] args) throws IOException
	{
		DP = new int[100][];
		for(int i = 0; i < 100; ++i)
			DP[i] = new int[i + 1];
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		while(T-- > 0)
		{
			int N = Integer.parseInt(in.readLine());
			for(int i = 0; i < N; ++i)
			{
				StringTokenizer st = new StringTokenizer(in.readLine());
				for(int j = 0; j <= i; ++j)
					DP[i][j] = Integer.parseInt(st.nextToken());
			}
			for(int i = 0; i < N; ++i)
			{
				for(int j = 0; j <= i; ++j)
				{
					int max = 0;
					if(j - 1 >= 0)
						max = DP[i - 1][j - 1];
					if(j <= i - 1)
						if(max < DP[i - 1][j])
							max = DP[i - 1][j];
					DP[i][j] += max;
					//System.out.print(DP[i][j] + " ");
				}
				//System.out.println();
			}
			int max = DP[N - 1][0];
			for(int i = 1; i < N; ++i)
				if (max < DP[N - 1][i])
					max = DP[N - 1][i];
			System.out.println(max);
		}
		in.close();
	}
} 