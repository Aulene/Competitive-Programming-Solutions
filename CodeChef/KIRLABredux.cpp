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
 
#define lli long long int
#define mod 1000000007
#define pb push_back
 
int n;
lli overall;
lli a[100007];
lli dp[1007][1007];
 
lli recur(lli index, lli prevIndex)
{
	if(prevIndex>=n)
		return 0;
 
	if(dp[index][prevIndex]!=-1)
		return dp[index][prevIndex];
 
	lli i, ans1, ans=0;
	lli cur, k;
 
	for(i=index; i<n; i++)
		{
			k=__gcd(a[i], a[prevIndex]);
 			if(k>1)
 				{
 					cout << i << " " << prevIndex << endl;
 					cout << k << endl;
 				}
			if(k>1)
				ans=max(ans, 1+recur(i+1, i));
		}
 
	return dp[index][prevIndex]=ans;
}
 
int main()
	{
		int t;
		lli prev, i, ans, k, j, cur;
 		
		cin >> t;
 
		while(t--)
			{
				cin >> n;
 
				ans=0;
 
				for(i=0; i<n; i++)
					cin >> a[i];
 
				for(i=0; i<1007; i++)
					for(j=0; j<1007; j++)
						dp[i][j]=-1;
				/*
				for(i=0; i<n; i++)
					{
						cur=1;
						prev=a[i];
 
						for(j=i+1; j<n; j++)
							{
								k=__gcd(prev, a[j]);
								if(k>1)
									{
										cur++;
										prev=a[j];
									}
							}
 
						ans=max(cur, ans);
					}
				*/
 	
				for(i=0; i<n; i++)
					ans=max(ans, 1+recur(i+1, i));

				for(i=0; i<n; i++)
					{
						for(j=0; j<n; j++)
							cout << dp[i][j] << " ";
						cout << endl;
					}
				cout << ans << endl;
			}
		return 0;
	} 