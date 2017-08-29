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

int a[300007], p[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = 0;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for(i = 1; i <= n; i++) ans += min(i + 1, n) * a[i];
		cout << ans << endl;
		return 0;	
	}