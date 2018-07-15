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

		int d, r, t, i, j;
		int rita, theo;

		cin >> d >> r >> t;

		for(i = d + 1; i <= 10000; i++)
			{
				rita = i * (i + 1) / 2 - 6;
				theo = (i - d) * (i - d + 1) / 2 - 3;
				// cout << rita << " " << theo << endl;

				if(rita + theo == t + r)
					{
						cout << abs(rita - r) << endl;
						break;

					}
			}
		return 0;
	}