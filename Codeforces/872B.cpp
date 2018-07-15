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

vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, ans = 1e16, i;

		cin >> n >> m;

		vs.resize(n);

		for(i = 0; i < n; i++) cin >> vs[i];

		if(m == 1)
			{
				for(i = 0; i < n; i++) ans = min(ans, vs[i]);
			}
		else if(m == 2) ans = max(vs[0], vs[n - 1]);
		else
			{
				ans = - ans;
				for(i = 0; i < n; i++) ans = max(ans, vs[i]);
			}

		cout << ans << endl;
		return 0;
	}