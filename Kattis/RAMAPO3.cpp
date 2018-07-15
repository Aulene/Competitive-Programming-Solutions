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

		int w, l, q, n, x, y, rx, ry, ax, ay;
		char s;

		while(cin >> w >> l)
			{
				if(!w && !l) break;

				rx = ry = ax = ay = 0;

				cin >> q;

				while(q--)
					{
						cin >> s >> n;

						if(s == 'u')
							{
								ry += n;
								ay = min(l - 1, ay + n);
							}
						else if(s == 'd')
							{
								ry -= n;
								ay = max(0, ay - n);
							}
						else if(s == 'r')
							{
								rx += n;
								ax = min(w - 1, ax + n);
							}
						else
							{
								rx -= n;
								ax = max(0, ax - n);
							}
					}

				printf("Robot thinks %d %d\n", rx, ry);
				printf("Actually at %d %d\n", ax, ay);
			}
		return 0;
	}