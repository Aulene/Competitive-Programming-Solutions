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

int a[5];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i;
		int x = 20000000007, ans = 0;

		for(i = 0; i < 3; i++)
			cin >> a[i], x = min(x, a[i]);

		for(i = 0; i < 3; i++)
			a[i] -= x;

		sort(a, a + 3);

		if(a[1] + a[2] >= 3)
			ans = max(min(ceil(a[2] / 2), a[1]), min(ceil(a[1] / 2), a[2]));

		ans += x;
		cout << ans << endl;
		return 0;
	}