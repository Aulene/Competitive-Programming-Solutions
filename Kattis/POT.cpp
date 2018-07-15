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

int p[17];

int compute(int n)
{
	int px = n % 10;
	n /= 10;
	return pow(n, px);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> m, ans += compute(m);
		cout << ans << endl;


		return 0;
	}