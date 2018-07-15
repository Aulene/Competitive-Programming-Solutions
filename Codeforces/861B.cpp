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

int flats[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, k, f, i, j, u, v, ansn;
		int ans = -1, ansfound = 0;

		cin >> n >> m;

		for(i = 0; i < 107; i++) flats[i] = -1;

		for(i = 1; i <= m; i++)
			{
				cin >> u >> v;
				flats[u] = v;
			}

		for(i = 1; i <= 100; i++)
			{
				u = 1;
				bool ansx = 1;

				for(j = 1; j <= 100; j++)
					{
						if(j == n) ansn = u;

						if(flats[j] != -1)
							{
								if(flats[j] != u)
									{
										ansx = 0;
										break;
									}
							}

						if(j % i == 0) 
							u++;
					}

				if(ansx)
					{
						ansfound++;
						cout << i << " " << ansn << endl;
						ans = ansn;
					}
			}

		if(ansfound != 1) ans = -1;
		cout << ans << endl;

		return 0;
	}