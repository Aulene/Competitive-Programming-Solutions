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

int a[1007], f[1007];
int dp[1007][1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans, sum;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < 1007; i++) dp[i][0] = 1;
			
		for(i = 1; i < 1007; i++)
			for(j = 1; j <= i; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;

		ans = 1, sum = 0;

		for(i = 1; i <= n; i++)
			{
				ans = (ans * dp[sum + a[i] - 1][a[i] - 1]) % mod;
				sum += a[i];
			}

		cout << ans << endl;

		return 0;
	}