	#include <iostream>
	#include <algorithm>
	using namespace std;
	const int N = 1e5+5;
	typedef long long ll;
	const ll inf=1e15;
	int arr[N];
	ll dp[2][N];


	void get(int f, int start, int end, int a,int b)	{
		if(end<start)	return;
		int m= (start+end)/2;
		int index=a;dp[f][m]=dp[!f][index-1]+arr[m]-arr[index];
		int index2=index;
		ll hh;
		for(int i=a;i<=b && i<=m-1;i++)	{
			index=i;
			hh=dp[!f][index-1]+arr[m]-arr[index];
			if(hh<dp[f][m])	{
				dp[f][m]=hh;
				index2=index;
			}
		}
		get(f,start,m-1,a,index2);
		get(f,m+1,end,index2,b);
	}

	int main()	{

		int t;scanf("%d",&t);
		while(t--)	{
			int n,k,a,b;scanf("%d %d",&n,&k);
			for (int i = 1; i <=n; ++i)	{
				scanf("%d",arr+i);
			}
			sort(arr+1,arr+1+n);
				for(int i=0;i<=k;i++)	{
					a=i&1;b=a^1;
					if(i==0)	{
						dp[a][0]=0;
						for(int j=1;j<=n;j++)	dp[a][j]=inf;
					}
					else	{
						get(a,1,n,1,n);
						for(int j=1;j<=n;j++)	cout<<i<<" "<<j<<" "<<dp[a][j]<<endl;
					}
				}
				cout<<dp[k&1][n]<<endl;
			}
		


	}