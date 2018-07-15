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

int dp[32007][37];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, n, ans = 1;
		string s;

		for(i = 0; i < 32007; i++)
			for(j = 0; j < 37; j++)
				dp[i][j] = -1;

		while(cin >> s)
			{
				n = s.size();

				int node = 1;

				for(i = 0; i < n; i++)
					{
						if(dp[node][s[i] - 'A'] == -1)
							{
								ans++;
								dp[node][(int) s[i] - 'A'] = ans;
							}
						
						node = dp[node][s[i] - 'A'];
					}

				// cout << ans << endl;
			}

		cout << ans << endl;

		return 0;
	}