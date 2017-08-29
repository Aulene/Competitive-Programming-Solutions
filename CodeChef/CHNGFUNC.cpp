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

		int n, m, i, j, eqn, ans = 0;
		int left, u, v;
		vector <int> :: iterator it1, it2;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
				{
					eqn = i * i;
					u = eqn + 1;
					v = eqn + m;
					
					if(u != v)
						ans += (int)sqrt(v) - (int)sqrt(u);
					else
						if((int)sqrt(u) * (int)sqrt(u) == u)
							ans++;
				}

		cout << ans << endl;

		return 0;
	}