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

#define int unsigned long long int
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

		int a, b, ans, i;

		cin >> a >> b;

		if(b - a >= 10) ans = 0;
		else
			{
				ans = 1;
				for(i = a + 1; i <= b; i++)
					{
						int u = i % 10;
						ans *= u;
					}
				ans = ans % 10;
			}

		cout << ans << endl;
		return 0;
	}