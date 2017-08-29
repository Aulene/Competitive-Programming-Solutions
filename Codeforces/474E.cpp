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
#define mid (start + end) / 2

int h[100007], k;

struct node
{
	pair < pair <int, int>, int> val; // left, right, ans
	node *l, *r;

	pair < pair <int, int>, int> merge(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b)
		{
			int x = abs(h[b.f.f] - h[a.f.s]);
			pair < pair <int, int>, int> ans;
			if(x >= k)
				{
					ans.s = a.s + b.s;
					ans.f.f = a.f.f;
					ans.f.s = b.f.s;
				}
			else
				{
					if(a.s >= b.s) ans = a;
					else ans = b;
				}

			return ans;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					val.f.f = val.f.s = start;
					val.s = 1;
				}
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n >> k;

		for(i = 1; i <= n; i++) cin >> h[i];

		node *root = new node;
		root = root -> build(1, n);

		pair < pair <int, int>, int> ans;
		ans = root -> val;
		
		cout << ans.s << endl;
		return 0;
	}