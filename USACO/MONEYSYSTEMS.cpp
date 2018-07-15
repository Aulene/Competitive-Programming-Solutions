/*
 ID: aussyle1
 PROG: money
 LANG: C++11
 */

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

int dp[100007][27], a[27];
int n;

int recur(int m, int req)
{
	if(req >= n) return 0;
	if(m < 0) return 0;
	if(!m) return 1;

	int ans = 0;

	return dp[m][req] = recur(m - a[req], req) + recur(m - a[req], req + 1) + recur(m, req + 1);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int v, i, j;

		cin >> n >> v;
		for(i = 0; i < n; i++) cin >> a[i];

		recur(v, 0);
		int ans = 0;

		for(i = 0; i < 27; i++) ans += dp[v][i];
		cout << ans << endl;
		return 0;
	}