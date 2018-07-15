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

int a[100007], pref[200007];
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, s, f, ans = 0;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i], pref[i] = pref[i - 1] + a[i];
		cin >> s >> f;

		for(i = 1; i <= n; i++)
			{
				ans = max(ans, pref[f + i - 1] - pref[s + i]);
			}

		cout << ans << endl;
		return 0;
	}