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

int dp[257][257];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		int i, j, k, n, m, t;

		for(i = 0; i < 257; i++) dp[i][0] = 1;
		for(i = 1; i < 257; i++)
			for(j = 0; j < 257; j++)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		cin >> t;
		while(t--)
			{
				cin >> m >> n;
				cout << dp[n + m - 1][n - 1] << endl;
			}
		return 0;
	}