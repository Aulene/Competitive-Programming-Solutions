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

bool vis[17][17];
bool found[17][17];

int canMake(int n)
{
	int i, j;
	for(i = 0; i < 17; i++)
		for(j = 0; j < 17; j++)
			vis[i][j] = 0;

	while(n)
		{
			int u = n % 10;
			bool m = 0;

			for(i = 0; i < 3; i++)
				{
					if(found[i][u] && !vis[i][u])
						{
							vis[i][u] = 1;
							m = 1;
							break;
						}
				}

			if(!m) return 0;

			n /= 10;
		}

	return 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, u, v, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++)
			for(j = 0; j < 6; j++) cin >> u, found[i][u] = 1;

		for(i = 1; i <= 999; i++)
			{
				if(canMake(i))
					ans = i;
				else break;
			}

		cout << ans << endl;
		return 0;
	}	