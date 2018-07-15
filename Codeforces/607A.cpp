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

vector < pair <int, int> > vs;
int dp[1000007];
int obj[1000007];

int ret(int pos, int b)
{
	if(pos - b - 1 < 0) return 1;
	else return 1 + dp[pos - b - 1];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;

		cin >> n;

		memset(obj, -1, sizeof(obj));

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
				obj[u] = v;
			}

		for(i = 0; i <= 1000001; i++)
			{
				if(obj[i] != -1) dp[i] = ret(i, obj[i]);
				else
					{
						if(i == 0) dp[i] = 0;
						else dp[i] = dp[i - 1];
					}

				ans = max(ans, dp[i]);
			}

		cout << n - ans << endl;

		return 0;
	}