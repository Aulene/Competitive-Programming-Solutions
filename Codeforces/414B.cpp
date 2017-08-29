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

int dp[2007][2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, K;

		cin >> n >> K;

		for(i = 1; i <= n; i++) dp[i][1] = 1;

		for(i = 2; i <= K; i++)
			for(j = 1; j <= n; j++)
				for(k = j; k <= n; k += j)
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;

		return 0;
	}