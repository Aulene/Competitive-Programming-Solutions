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

		int t, n, i, p, cw, h;

		cin >> t;

		while(t--)
			{
				cw = 0, h = 0;

				cin >> n >> p;

				for(i = 0; i < n; i++)
					{
						int u;

						cin >> u;

						if(u >= p / 2) cw++;
						if(u <= p / 10) h++;
					}

				if(cw == 1 && h == 2) cout << "yes\n";
				else cout << "no\n";
			}
		return 0;
	}