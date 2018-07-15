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

int a[1007], dp[1007][1007];



signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, k;

		cin >> t;

		while(t--)
			{
				int ans = 0;

				cin >> n >> k;

				for(i = 0; i < k; i++)
					{
						cin >> u >> v;
						a[u] = v;
					}

				for(i = 0; i < n; i++)
					for(j = i; j < n; j += 2)
						{
							ans += checkPal(i, j);
						}

				cout << ans << endl;
			}
		return 0;
	}