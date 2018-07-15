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
#define ld long double
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

ld dp[1007][1007];

ld recur(int w, int b)
{
	if(w <= 0) return 0;
	if(b <= 0) return 1;
	if(dp[w][b] != -1) return dp[w][b];

	ld ans = (ld) w / (w + b), ans2, ans3, ans4;

	ans2 = (ld) b / (w + b); b--;
	ans2 *= (ld) b / (w + b); b--;

	ans3 = (ld) recur(w, b - 1) * b / (w + b);
	ans4 = (ld) recur(w - 1, b) * w / (w + b);

	ans += ans2 * (ans3 + ans4);
	return dp[w][b] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int w, b;
		ld ans;

		for(int i = 0; i < 1007; i++)
			for(int j = 0; j < 1007; j++) dp[i][j] = -1;

		cin >> w >> b;
		ans = recur(w, b);

		printf("%.11Lf\n", ans);
		return 0;
	}