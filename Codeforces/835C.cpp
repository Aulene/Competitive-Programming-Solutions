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

int M[107][107], dp[107][107], stardp[107][107];
int starExists[107][107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, q, c, i, j, u, v, lol, ans;
		int t, x1, y1, x2, y2;
		int lrx, lry, ulx, uly;
		int maxx = 0, maxy = 0;

		cin >> n >> q >> c;

		for(i = 1; i <= 107; i++)
			for(j = 1; j <= 107; j++)
				dp[i][j] = 0, starExists[i][j] = 0;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v >> lol;
				M[u][v] += lol;
				starExists[u][v]++;
			}

		for(i = 1; i < 105; i++)
			for(j = 1; j < 105; j++)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + M[i][j];
					stardp[i][j] = stardp[i - 1][j] + stardp[i][j - 1] - stardp[i - 1][j - 1] + starExists[i][j];
				}

		while(q--)
			{
				ans = 0;

				cin >> t >> x1 >> y1 >> x2 >> y2;

				lol = stardp[x2][y2] + stardp[x1 - 1][y1 - 1] - stardp[x1 - 1][y2] - stardp[x2][y1 - 1];
				ans += lol * t;
				ans %= c + 1;

				u = dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];
				ans += u;
				ans %= c + 1;

				cout << ans << endl;
			}

		return 0;
	}