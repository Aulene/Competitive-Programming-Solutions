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

int a[200007], prefix[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;


		for(i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1, greater <int> ());
		for(i = 1; i <= n; i++) cout << a[i] << " ", prefix[i] = prefix[i - 1] + a[i];
		

		while(m--)
			{
				cin >> u >> v;
				// j = max(j, v - u);
				ans += prefix[j]
			}

		cout << ans << endl;

		return 0;
	}