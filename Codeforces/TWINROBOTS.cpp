#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[2507][2507], b[2507][2507], c[2507][2507], dp[2507][2507];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, n;

		cin >> n;

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++) 
				{
					cin >> a[i][j]; 
					c[i][j] = a[i][j];
					dp[i][j] = -10000007;
				}


		for (int x = 0; x < n / 2; x++)
		    {
		        for (int y = x; y < n - x - 1; y++)
		        {
		            int temp = a[x][y];
		            a[x][y] = a[y][n - 1 - x];
		            a[y][n - 1 - x] = a[n - 1 - x][n - 1 - y];
		            a[n - 1 - x][n - 1 - y] = a[n - 1 - y][x];
		            a[n - 1 - y][x] = temp;
		        }
		    }

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				c[i][j] += a[i][j];

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				{
					if(i == 0 && j == 0) { dp[i][j] = c[i][j]; continue; }

					if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
					if(i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
					dp[i][j] += c[i][j];
				}

		cout << dp[n - 1][n - 1] << endl;

		return 0;
	}