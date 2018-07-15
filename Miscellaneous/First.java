import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.TreeSet;

public class simple {

	public static BigInteger cube(BigInteger b){
		return b.pow(3);
	}
	
	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	
	//public BigInteger
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		long[] vals=new long[1000003];
		TreeSet<Long> ts= new TreeSet<>();
		for(int i=2;i<1000001;i++){
			long j = i;
			//vals[i] = j*j*j;
			ts.add(j*j*j);
		}
		//Arrays.sort(vals);
		
		while(t-->0){
			args= br.readLine().split( " ");
			long l1 = Integer.parseInt(args[0]);
			long l2 = Integer.parseInt(args[1]);
			long bb= l1*l2;
			//System.out.println(bb);
			long k = gcd(l1,l2);
			if(ts.contains(bb)){
				int[] fc1 = new int[100000];
				fc1[0]=0;
				fc1[1]=1;
				long ll1 =l1/k;
				//ArrayList<Integer> lst
				//System.out.println("q");
				for(int i=2;ll1>1;i++){
				//	
				//	System.out.println(ll1);
					if(ll1%i==0){
						fc1[i]++;
						
						ll1/=i;
						i--;
					}
					
				}
				//System.out.println("fas");
				
				
				int[] fc2 = new int[100000];
				fc2[0]=0;
				fc2[1]=1;
				long ll2 =l2/k;
				for(int i=2;ll2>1;i++){
					if(ll2%i==0){
						fc2[i]++;
						//i--;
						ll2/=i;
						i--;
					}
				}
				//System.out.println("Here");
				boolean bbb=true;;
				for(int i=2;i<fc1.length;i++){
					int m1= fc1[i];
					int m2 = fc2[i];
					if(m1>m2){
						int tt=m1;
						m1=m2;
						m2=tt;
					}
					//therefore m1<m2
					if(m1*2<m2){
						bbb=false;
						break;
					}
				}
				if(bbb){
					System.out.println("Yes");
				}else{
					System.out.println("No");
				}
				
				//System.out.println("Yes");
			}else{
				System.out.println("No");
			}
			
		}
		
		

	}

}