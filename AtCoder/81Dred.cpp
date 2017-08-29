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
 
int n;
int dp[57];
 
string s1, s2;
 
int recur(int i)
{
	if(dp[i] != -1) return dp[i];
 
	if(i == n - 1)
		{
			if(s1[i] == s2[i]) return 3;
			else return 0;
		}
	else if(i == n) return 1;
 
	int ans = 0, ans1 = 0, ans2 = 0;
 
	if(s1[i] == s1[i + 1] && s2[i] == s2[i + 1])
		{
			// cout << i << " t1\n";
 
			if(s1[i + 2] == s2[i + 2])
				ans1 = (ans1 + 2 * recur(i + 2)) % mod;
 
			if(s1[i + 2] == s1[i + 3] && s2[i + 2] == s2[i + 3])
				ans1 = (ans1 + 3 * recur(i + 2)) % mod;
 
			ans = ans1 % mod;
		}
 
	if(s1[i] == s2[i])
		{
			// cout << i << " t2\n";
 
			if(s1[i + 1] == s2[i + 1])
				ans2 = (ans2 + 2 * recur(i + 1)) % mod;
 
			if(s1[i + 1] == s1[i + 2] && s2[i + 1] == s2[i + 2])
				ans2 = (ans2 + recur(i + 1)) % mod;
 
			ans2 %= mod;
			ans = (ans + ans2) % mod;
		}
 
	// cout << i << " " << ans1 << " " << ans2 << endl;
	return dp[i] = ans % mod;
}
 
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
 
		int i, ans;
 
		for(i = 0; i < 57; i++) dp[i] = -1;
 
		cin >> n >> s1 >> s2;
		ans = recur(0);
		cout << ans % mod << endl;
 
		return 0;
	}