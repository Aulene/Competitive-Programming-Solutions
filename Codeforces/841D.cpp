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

int a[300007];
// vector < vector <int> > g(100007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = -1, ans2;

		cin >> n >> m;
		for(i = 1; i <= n; i++)
			{
				cin >> a[i];
				if(a[i] == -1 || a[i] == 0) ans = 0;
			}

		if(ans == -1)
			{
				for(i = 1; i <= m; i++)
					{
						cin >> u >> v;
						if(a[u] == 1 && a[v] == 1)
							{
								ans = 1; ans2 = i;
								break;
							}
					}

				if(ans == 1)
					cout << ans << endl << ans2 << endl;
				else cout << ans << endl;
			}
		else cout << ans << endl;


		return 0;
	}