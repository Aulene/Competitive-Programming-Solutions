#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 200007;

int a[N];
vector < pi > vs;

#define mid (start + end) / 2

int lazy[400007];

struct RangeSTreeLazy
{
	int val;
	RangeSTreeLazy *l, *r;

	int merge(int a, int b) { return a + b; }

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new RangeSTreeLazy, r = new RangeSTreeLazy;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RangeSTreeLazy *update(int lazy[], int start, int end, int a, int b, int v, int level = 1)	
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

	int query(int lazy[], int start, int end, int a, int b, int level = 1)
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
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, k, i, j, u, v;

		cin >> n >> m >> k;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}



		return 0;
	}