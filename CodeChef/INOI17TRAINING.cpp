#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int e[5007], dp[5007][5007];
int tvals[5007];

// dp[i][j] = max XV for the first I gyms by training J times

int sumdig(int n)
{
	int ans = 0;
	while(n)
		{ ans += n % 10, n /= 10; }
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, sin, i, j;

		cin >> n >> sin;

		for(i = 1; i <= n; i++)
			cin >> e[i];

		tvals[0] = sin;
		for(i = 1; i <= n; i++)
			tvals[i] = pow(sumdig(tvals[i - 1]), 3) + tvals[i - 1];

		// for(i = 0; i <= n; i++)
		// 	cout << tvals[i] << " ";
		// cout << endl;


		for(i = 0; i <= n; i++)
			{
				for(j = 0; j <= n; j++)
					dp[i][j] = -1000000007;
			}

		dp[0][0] = 0;
		
 		for(i = 1; i <= n; i++)
			{
				for(j = 0; j <= i; j++) 
					dp[i][j] = dp[i - 1][j] + (tvals[j] * e[i]);
				
				if(j > 0) 
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			}

		int ans = 0;

		for(i = 0; i <= n; i++)
			ans = max(ans, dp[n][i]);

		for(i = 0; i <= n; i++)
			{
				for(j = 0; j <= n; j++)
					cout << dp[i][j] << " ";
				cout << endl;

			}
		cout << ans << endl;
		return 0;
	}