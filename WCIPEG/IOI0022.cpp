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
#define p push
#define pb push_back
#define mp make_pair

int a[307];
int dist[307][307];
int cost[307][307];
int dp[307][307]; //minimum cost of assigning j post offices such that there is a post office at village i

int main()
	{
		int n, i, j, k, K;

		cin >> n >> K;

		for(i=0; i<307; i++)
			for(j=0; j<307; j++)
				dp[i][j]=INT_MAX;

		for(i=0; i<307; i++)
			dp[i][1]=0;

		for(i=0; i<n; i++)
			cin >> a[i];

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				dist[i][j]=abs(a[i]-a[j]);

		//int dp[i][j] - minimum cost of assigning j post offices such that there is a post office at village i

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				for(k=i; k<j; k++)
					cost[i][j]+=min(dist[i][k], dist[k][j]);
  
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				dp[i][1]+=abs(a[i]-a[j]);
			
		for(i=2; i<=K; i++)
			{
				for(j=0; j<n; j++)
					{
						for(k=0; k<=j; k++)
							dp[j][i]=min(dp[j][i], dp[k][i-1]+cost[k][j]);
						dp[j][i]+=cost[j][n-1];
					}
			}

		for(i=1; i<=K; i++)
			{
				for(j=0; j<n; j++)
					cout << dp[j][i] << " ";
				cout << endl;
			}
		return 0;
	}