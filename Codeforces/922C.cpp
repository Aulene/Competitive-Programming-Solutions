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

unordered_map <int, bool> vis;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j;
		bool ans = 1;

		cin >> n >> k;

		for(i = 1; i <= min(k, 50000000*1LL); i++)
			{
				if(vis[n % i])
					{
						ans = 0;
						break;
					}
				else vis[n % i] = 1;
			}

		if(ans) cout << "yes\n";
		else cout << "no\n";
		return 0;
	}