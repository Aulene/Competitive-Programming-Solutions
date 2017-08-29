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

int pref[107][107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, sum, u, ans = -10000000007;

		cin >> n;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				cin >> u, pref[i][j] = pref[i][j - 1] + u;
		
		for(i = 1; i <= n; i++)
			for(j = i; j <= n; j++)
				{
					sum = pref[1][j] - pref[1][i - 1];
					ans = max(ans, sum);

					for(k = 2; k <= n; k++)
						{
							sum = pref[k][j] - pref[k][i - 1] + max(0LL, sum);
							// cout << i << " " << j << " " << k << " " <<  pref[k][j] - pref[k][i - 1] << endl;
							ans = max(ans, sum);
						}
				}

		cout << ans << endl;
		return 0;
	}