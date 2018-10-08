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
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int a[50007];
struct RangeSTreeLazy
{
	int val;
	RangeSTreeLazy *l, *r;

	int merge(int a, int b) 
		{ return max(a, b); }

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end) { val = a[start]; }
			else
				{
					l = new RangeSTreeLazy, r = new RangeSTreeLazy;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	int query(int start, int end, int a, int b, int level = 1)
		{
            if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(start, mid, a, b, 2 * level), r -> query(mid + 1, end, a, b, 2 * level + 1));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, u, v, i, j, x, y, ans = 0;
		int nx, ny, nz;

		cin >> n >> m;

        for(int i = 0; i < n; i++) cin >> a[i];

		RangeSTreeLazy *root = new RangeSTreeLazy;
		root = root -> build(0, n - 1);

		while(m--)
			{
				cin >> u >> v;
                u--, v--;
                x = root -> query(0, n - 1, u, v - 1);
                if(x <= a[u]) ans++;
			}
        
        cout << ans << endl;

		return 0;
	}