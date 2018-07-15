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
bool vis[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = 0, ansvis = 100000007;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> j;
				a[j] = i;
				vis[j] = 1;
			}

		for(i = 0; i <= 200000; i++)
			if(vis[i])
				{
					if(a[i] < ansvis)
						{
							ansvis = a[i];
							ans = i;
						}
				}

		cout << ans << endl;
		return 0;
	}