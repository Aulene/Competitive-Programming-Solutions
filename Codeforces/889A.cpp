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

int a[7];
int req;

int recur(int idx, int sum)
{
	if(idx > 5)
		{
			if(sum == req) return 1;
			return 0;
		}
	else
		{
			return max(recur(idx + 1, sum + a[idx]), recur(idx + 1, sum));
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n = 6, i, j, sum = 0;

		for(i = 0; i < n; i++) cin >> a[i], sum += a[i];

		if(sum % 2) cout << "NO" << endl;
		else
			{
				req = sum / 2;
				int ans = recur(0, 0);
				if(ans) cout << "YES\n";
				else cout << "NO\n";
			}
		return 0;
	}