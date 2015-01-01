import java.io.*;
 
public class Main
{
	static int[] holes= 
	{
		1,2,0,1,0,0,0,0,0,0,
		0,0,0,0,1,1,1,1,0,0,
		0,0,0,0,0,0
	};
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		while(T-- > 0)
		{
			String line = in.readLine();
			int h = 0;
			for(int i = 0; i < line.length(); ++i)
			{
				h += holes[line.charAt(i) - 'A'];
			}
			System.out.println(h);
		}
		in.close();
	}
}  