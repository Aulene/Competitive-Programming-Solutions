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

int a[200007];
bool vis[200007], dp[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 1;;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];

		vis[1] = 0;
		dp[0] = 1;

		for(i = 1; i <= n; i++)
			{
				j = a[i];

				if(dp[j])
					{
						int u = 
					}

			}

		cout << ans << endl;
		return 0;
	}