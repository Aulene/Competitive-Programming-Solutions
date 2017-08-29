#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;
struct job{
	int start,finish,price;
};
bool func(job s1,job s2){
return (s1.start<s2.start);
}
int bin_search(job a[],int low,int high,int val)
{
	while(low<high)
	{
		int mid = low+(high-low)/2;
		if(a[mid].start>=val)
		{
			high=mid;
		}
		else
		{
			low=mid+1;
		}
	}
	if(a[low].start>=val)
	{
		return low;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int s,d,p,t,n,pos;
		scanf("%d",&n);
		job a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&s,&d,&p);
			a[i].start=s;
			a[i].finish=s+d;
			a[i].price=p;
		}
		sort(a,a+n,func);
		int dp[n+1];
		memset(dp,0,sizeof(dp));
		dp[n]=a[n-1].price;
		for(int i=n-1;i>=0;i--)
		{
			dp[i]=dp[i+1];
			for(int j=i+1;j<n;j++)
			{
				if(a[j].start>=a[i].finish)
				{
					dp[i]=max(dp[i],a[i].price+dp[j]);
				}
			}
		}
		cout<<dp[0]<<endl;
	return 0;
}