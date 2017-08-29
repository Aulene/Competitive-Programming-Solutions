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

char s1[5007], s2[5007];
int dp[5007][5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> s1[i], s2[n - i - 1] = s1[i];

		for(i = 0; i <= n; i++)
			{
				for(j = 0; j <= n; j++)
					{
						if(i == 0 || j == 0)
							dp[i][j] = 0;
						else if(s1[i - 1] == s2[j - 1])
							{
								dp[i][j] = dp[i - 1][j - 1] + 1;
								ans = max(ans, dp[i][j]);
							}
						else
							dp[i][j] = 0;
					}
			}

		cout << s2 << endl;
		for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
					cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " ";
				cout << endl;
			}
		cout << ans << endl;
		return 0;
	}