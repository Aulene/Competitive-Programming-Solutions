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

int x[7], a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, p, q, r, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 0; i < 3; i++) cin >> x[i];
		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < 3; i++)
			{
				u = - 1000000000000000007;

				for(j = 0; j < n; j++)
					{
						u = max(u, x[i] * a[j]);
					}

				ans += u;
			}

		cout << ans << endl;
		
		return 0;
	}