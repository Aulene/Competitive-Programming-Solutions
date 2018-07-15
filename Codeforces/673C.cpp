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

int cnt[5007], ans[5007], a[5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= 5007; j++) cnt[j] = 0;

				int best = -1, bestcnt = -1;

				for(j = i; j <= n; j++)
					{
						cnt[a[j]]++;

						if((bestcnt < cnt[a[j]]) || (bestcnt == cnt[a[j]] && best > a[j]))
							{
								best = a[j];
								bestcnt = cnt[a[j]];
							}

						ans[best]++;
					}
			}

		for(i = 1; i <= n; i++) cout << ans[i] << " ";

		return 0;
	}