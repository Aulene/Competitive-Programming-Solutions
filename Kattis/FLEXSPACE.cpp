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

int a[107], vis[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j;

		cin >> n >> k;

		a[0] = 0;
		for(i = 1; i <= k; i++) cin >> a[i];
		a[k + 1] = n;

		for(i = 0; i <= k + 1; i++)
			for(j = i + 1; j <= k + 1; j++)
				{
					vis[a[j] - a[i]] = 1;
				}

		for(i = 0; i < 107; i++)
			if(vis[i]) cout << i << " ";
		return 0;
	}