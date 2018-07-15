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

int a[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, ans = 0, l, r;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		l = r = m;

		while(l > 0 || r < n + 1)
			{
				if(l == r)
					{
						if(a[l]) ans++;
						l--, r++;
						continue;
					}

				if(l > 0 && r < n + 1)
					{
						if(a[l] && a[r]) ans += 2;
					}

				if(l > 0 && r > n)
					if(a[l]) ans++;

				if(l < 1 && r < n + 1)
					if(a[r]) ans++;

				l--, r++;
			}

		cout << ans << endl;
		return 0;
	}