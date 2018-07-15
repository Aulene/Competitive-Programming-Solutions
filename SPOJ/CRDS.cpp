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
#define mod 1000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[1000007][3];
int prefix[1000007][3];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;

		cin >> t;

		dp[1][1] = prefix[1][1] = 2;
		dp[1][2] = prefix [1][2] = 0;
		dp[2][1] = 4;
		dp[2][2] = 1;
		prefix[2][1] = 6;
		prefix[2][2] = 1;

		for(i = 3; i <= 1000000; i++)
			{
				dp[i][1] = (i * 2) % mod;
				dp[i][2] = (i - 1 + mod) % mod;
				prefix[i][1] = (prefix[i - 1][1] + dp[i][1]) % mod;
				prefix[i][2] = (prefix[i - 1][2] + dp[i][2]) % mod;				
			}

		// for(i = 1; i <= 10; i++)
		// 		cout << dp[i][1] << " " << dp[i][2] << endl;

		while(t--)
			{
				cin >> n;
				cout << (prefix[n][1] + prefix[n][2]) % mod << endl;
			}
		return 0;
	}