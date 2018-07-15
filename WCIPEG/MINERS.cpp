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

int vs[27];
int n;
int dp[27][3][3][3][3];

int cal(int a, int b, int c)
{
	int ans = 0;
	for(int i = 1; i <= 3; i++)
		if(a == i || b == i || c == i) ans++;
	return ans;
}

int recur(int index, int s11, int s12, int s21, int s22)
{
	if(dp[index][s11][s12][s21][s22] != -1) return dp[index][s11][s12][s21][s22];
	if(index >= n) return 0;

	int ans1, ans2, ans;

	ans1 = recur(index + 1, s12, vs[index], s21, s22) + cal(s11, s12, vs[index]);
	ans2 = recur(index + 1, s11, s12, s22, vs[index]) + cal(s21, s22, vs[index]);
	ans = max(ans1, ans2);

	// cout << "OPEN " << index << endl;
	// cout << s11 << " " << s12 << " " << vs[index] << " " << ans1 << endl;
	// cout << s21 << " " << s22 << " " << vs[index] << " " << ans1 << endl;
	// cout << index << " " << ans1 << " " << ans2 << endl;
	// cout << "CLOSE" << endl;

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, ans;
		string s;

		memset(dp, -1, sizeof dp);
		
		cin >> n >> s;

		for(i = 0; i < n; i++)
			if(s[i] == 'M') vs[i] = 1;
			else if(s[i] == 'B') vs[i] = 2;
			else vs[i] = 3;

		ans = recur(0, 0, 0, 0, 0);
		cout << ans << endl;

		return 0;
	}