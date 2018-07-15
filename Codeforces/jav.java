 
import java.util.*;
import java.lang.*;
import java.io.*;
 
/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	static int sum(int[] a, int i, int s, int f){
		int addi=s;
		int sum = 0;
		for(int j=i;j>=i-(f-s);j--){
			sum+=a[j]-addi;
			addi+=1;
		}
		return sum;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner s1 = new Scanner(System.in);
		int n=s1.nextInt();
		//int k = s.nextInt();
		int[] a = new int[n];
		for(int i=0;i<n;i++){
			a[i]=s1.nextInt();
		}
		int s = s1.nextInt();
		int f = s1.nextInt();
		int max = Integer.MIN_VALUE;
		int argmax = n-1;
		for(int i=n-1;i>=f-s;i--){
			if(sum(a,i,s,f)>max){
				max = sum(a,i,s,f);
				argmax = i;
			}else if(sum(a,i,s,f)==max && i<argmax){
				argmax=i;
			}
		}
		System.out.println(argmax+1);
 
	}
}