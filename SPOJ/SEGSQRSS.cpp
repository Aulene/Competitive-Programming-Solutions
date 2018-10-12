#include <bits/stdc++.h>
#include <unordered_map>

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

pair <int, int> lazy[400007];

struct RangeSTreeSquare
{
	int val;
	RangeSTreeSquare *l, *r;

	int merge(int a, int b) { 
		return a + b; 
	}

	RangeSTreeSquare *build(int start, int end)
		{
			if(start == end)
				val = a[start] * a[start];
			else
				{
					l = new RangeSTreeSquare, r = new RangeSTreeSquare;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RangeSTreeSquare *update(int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != 0)
				{
					val += (end - start + 1) * lazy[level];

					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					val += (end - start + 1) * v;

					if(start != end)
						{
							lazy[2 * level] += v;
							lazy[2 * level + 1] += v;
						}			

					return this;
				}

			l = l -> update(lazy, start, mid, a, b, v, 2 * level);
			r = r -> update(lazy, mid + 1, end, a, b, v, 2 * level + 1);
			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b, int level = 1)
		{
			if(lazy[level] != 0)
				{
					val += (end - start + 1) * lazy[level];

					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(lazy, start, mid, a, b, 2 * level), r -> query(lazy, mid + 1, end, a, b, 2 * level + 1));
		}
};


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, u, q, v, i, j, x, y, ans;

        cin >> n;
		for(i = 0; i < n; i++) cin >> a[i];

		return 0;   
	}