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

int a[507][507], dp[507][507]; 

int recur(int x, int y, int px, int py)
{
	if(!a[x][y]) return 100007;
	int ans = 100007;

	if(y - a[x][y] && (px != x && py != (y - a[x][y]))) ans = 1 + recur(x, y - a[x][y]);
	if(y + a[x][y] <= m) ans = min(ans, 1 + recur(x, y + a[x][y]));
	if(x - a[x][y]) ans = min(ans, 1 + recur(x - a[x][y], y));
	if(x + a[x][y] <= n) ans = min(ans, 1 + recur(x + a[x][y], y));
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j;
		string s;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			{
				cin >> s;

				for(j = 0; j < m; j++)
					a[i][j + 1] = s[j] - '0';
			}

		for(i = 0; i < 507; i++)
			for(j = 0; j < 507; j++) dp[i][j] = -1;



		return 0;
	}