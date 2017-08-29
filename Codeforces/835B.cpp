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

int sumdig(string n)
{
	int ans = 0, i;

	for(i = 0; i < n.size(); i++)
		ans += n[i] - '0';

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int k, ans = 0, v, i = 0;
		string n;

		cin >> k >> n;

		sort(n.begin(), n.end());

		int sum2 = sumdig(n);

		v = k - sum2;

		while(v > 0)
			{
				ans++;
				v -= ('9' - n[i]);
				i++;
			}

		cout << ans << endl;
		return 0;
	}