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
vector < vector <int> > divs(2007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, m, t, k, ans;

		cin >> t;

		for(i = 1; i <= 2000; i++)
			for(j = 1; j <= i; j++)
				if(i % j == 0)
					divs[i].pb(j);

		while(t--)
			{
				cin >> n >> m;

				for(i = 1; i <= n; i++) dp[1][i] = 1;

				for(i = 2; i <= m; i++)
					{
						for(j = 1; j <= n; j++)
							{
								ans = 0;

								for(k = 0; k < divs[j].size(); k++)
									ans = (ans + dp[i - 1][divs[j][k]]) % mod;

								dp[i][j] = ans;
							}
					}

				ans = 0;

				for(i = 1; i <= n; i++) ans = (ans + dp[m][i]) % mod;

				cout << ans << endl;
			}
		return 0;
	}