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

double calc(int p, int q, int r, int s, int t)
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, s, m;
		double a;

		cin >> t;

		while(t--)
			{
				cin >> a;

				bool ansx = 0;

				for(i = 3; i <= 100; i++)
					{
						double x = (i - 2) * 180 / i;
						if(a == x) ansx = 1;
					}

				if(ansx) cout << "YES\n";
				else cout << "NO\n";
  			}
		return 0;
	}