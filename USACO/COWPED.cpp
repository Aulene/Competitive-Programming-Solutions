/*
ID: aussyle1
PROG: nocows
LANG: C++11
*/

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
#define mod 9901
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[207][107]; // dp_i_j = number of structures of i nodes with j length

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		// ifstream cin ("nocows.in");
		// ofstream cout ("nocows.out");
		int N, K, i, j, l, ans = 0;

		cin >> N >> K;

		for(i = 1; i <= K; i++) dp[1][i] = 1;

		for(i = 3; i <= N; i+=2)
			{
				for(j = 1; j <= K; j++)
					{
						for(l = 1; l <= i - 2; l += 2)
							{
								dp[i][j] = (dp[i][j] + dp[l][j - 1] * dp[i - 1 - l][j - 1]) % mod;
							}
					}
			}

		// for(i = 1; i <= N; i++)
		// 	{
		// 		for(j = 1; j <= K; j++)
		// 			cout << dp[i][j] << " ";
		// 		cout << endl;
		// 	}

		cout << (dp[N][K] - dp[N][K - 1] + mod) % mod << endl;

		return 0;
	}