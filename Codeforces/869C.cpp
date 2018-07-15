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
#define mod 998244353
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[5007][5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int a, b, c, ans, x, y, z;

		cin >> a >> b >> c;

		for(int i = 0; i < 5007; i++) dp[i][0] = dp[0][i] = 1;

		for(int i = 1; i < 5007; i++)
			for(int j = 1; j < 5007; j++)
				dp[i][j] = (dp[i - 1][j] + (j * dp[i - 1][j - 1]) % mod) % mod;

		x = dp[a][b] % mod;
		y = dp[a][c] % mod;
		z = dp[b][c] % mod;

		ans = (((x * y) % mod) * z) % mod;  

		cout << ans << endl;

		return 0;
	}