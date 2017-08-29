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

int n, k, ans, twos, fives;
int num;
int dp[207][6007];
map <int, int> :: iterator it;

int fact(int x, int y)
{
	int ans = 0;
	while(x % y == 0) { ans++; x /= y; }
	return ans;
}

signed main() 
{
	int i, j;

	cin >> n >> k;

	dp[0][0][0] = 0;

	for (i = 1; i <= n; i++) 
		{
			twos = fives = 0;
			
			cin >> num;

			twos = fact(num, 2);
			fives = fact(num, 5);
			
			for (j = 0; j < i; j++)
				for (it = dp[i - 1][j].begin(); it != dp[i - 1][j].end(); it++) 
					{
						dp[i][j][it->first] = max(dp[i][j][it->first], it->second);
						dp[i][j + 1][it->first + fives] = max(dp[i][j + 1][it->first + fives], it->second + twos);
					}
		}

	for (it = dp[n][k].begin(); it != dp[n][k].end(); it++)
		ans = max(ans, min(it->first, it->second));

	cout << ans << endl;
	return 0;
}