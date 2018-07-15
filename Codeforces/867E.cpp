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

int a[300007];

pair < pair <int, int>, int > findmaxcrossing(int low, int mid, int high)
{
	int i;
	int leftsum = -mod, rightsum = -mod;
	int maxleft, maxright;
	int sum = 0;

	for(i = mid; i >= low; i--)
		{
			sum = sum + a[i];
			if(sum > leftsum)
				{
					leftsum = sum;
					maxleft = i;
				}
		}

	sum = 0;

	for(i = mid + 1; i <= high; i++)
		{
			sum += a[i];

			if(sum > rightsum)
				{
					rightsum = sum;
					maxright = i;
				}
		}

	return mp(mp(maxleft, maxright), leftsum + rightsum);
}

pair < pair <int, int>, int > findmaxsub(int low, int high)
{
	int i;

	if(high == low) return mp(mp(low, high), a[low]);
	else
		{
			int mid = (low + high) / 2;

			pair < pair <int, int>, int > a, b, c, ans;

			a = findmaxsub(low, mid);
			b = findmaxsub(mid + 1, high);
			c = findmaxcrossing(low, mid, high);

			int lsum = a.s, rsum = b.s, csum = c.s;

			if(lsum >= rsum && lsum >= csum) return a;
			else if(rsum >= lsum && rsum >= csum) return b;
			else return c;

		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];

		pair < pair <int, int>, int > ans;
		ans = findmaxsub(0, n - 1);
		cout << ans.s << endl;
		return 0;
	}