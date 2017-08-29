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

int mover[107];
int dp[107];
bool visited[107];
bool ansExists;

int dfs(int index)
{
	if(index==100)
		{
			ansExists=1;
			return 0;
		}

	if(visited[index])
		return 1000001;

	visited[index]=1;

	if(mover[index])
		return dp[index]=1+dfs(mover[index]);

	int i, ans=1000001;

	for(i=1; i<=6; i++)
		if(index+i<=100)	
			ans=min(ans, dfs(index+i));

	return dp[index]=1+ans;
}

int main()
	{
		int t, n, i, m, u, v, ans;

		cin >> t;

		while(t--)
			{
				ansExists=0;
				
				for(i=0; i<107; i++)
					{
						visited[i]=0;
						mover[i]=0;
						dp[i]=-1;
					}

				cin >> n;

				while(n--)
					{
						cin >> u >> v;
						mover[u]=v;
					}

				cin >> m;

				while(m--)
					{
						cin >> u >> v;
						mover[u]=v;
					}

				ans=dfs(1);

				if(ansExists)
					cout << ans << endl;
				else
					cout << "-1" << endl;
			}

		return 0;
	}