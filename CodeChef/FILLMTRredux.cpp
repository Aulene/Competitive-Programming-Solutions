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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, q, i, j, u, v, ans;

		cin >> t;

		while(t--)
			{
				ans = 1;

				cin >> n >> q;

				for(i = 0; i < q; i++)
					{
						cin >> u >> v >> j;
						if((u + v) % 2 == 0 && j == 0) ans++;
					}

				if(ans == q) cout << "yes" << endl;
				else cout << "no" << endl;
			}

		return 0;
	}