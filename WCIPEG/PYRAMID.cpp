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

int ax[1007][1007], dp[1007][1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int m, n, i, j, k, l, a, b, c, d;

		cin >> m >> n >> a >> b >> c >> d;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) cin >> ax[i][j];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + ax[i][j];
		
		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++) cout << dp[i][j] << " ";
				cout << endl;
			}

		return 0;
	}