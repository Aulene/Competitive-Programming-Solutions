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

int ans[100007];

int perf(int n)
{
	int x = sqrt(n);
	if (x * x == n) return 1;
	return 0;
}

int lag(int n)
{
	if(perf(n)) return 1;

	while(n % 4 == 0) n >>= 2;
	if(n % 8 == 7) return 4;

	int x = sqrt(n);
	for(int i = 1; i <= x; i++)
		if(perf(n - i * i))
			return 2;

	return 3;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		ofstream cout ("EATCAKEred2.txt");
		int t, n, i, j, u, v, ans;

		cin >> t;

		for(i = 1; i <= t; i++)
			{
				cin >> n;
				ans = lag(n);
				cout << "Case #" << i << ": " << ans << endl;
				printf("Case #%lld: %lld\n", i, ans);
			}
		return 0;
	}