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

		int T, b, s, x, t, y, i, j, u, v;
		int ans1, ans2, ans3;
		cin >> T;

		while(T--)
			{
				cin >> s >> x >> t >> y;

				for(b = 1; b <= 10000000; b++)
					{
						u = s * b;
						v = y * b;

						// cout << u << " " << v << endl;

						if(((u % x) == 0) && ((v % t == 0)))
							{
								ans1 = (s * b) / x;
								ans2 = b;
								ans3 = (y * b) / t;
								break;
							}
					}

				cout << ans1 << " " << ans2 << " " << ans3 << endl; 
			}
		return 0;
	}