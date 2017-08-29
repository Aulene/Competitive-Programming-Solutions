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

int a[30007], ans[200007];
vector < pair < pair <int, int>, pair <int, int> > > vs;

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b) { return a + b; }

	node *build(int start, int end, int x)
		{
			if(start == end)
				{
					if(a[start] > x)
						val = 1;
					else
						val = 0;
					return this;
				}

			l = new node, r = new node;
			l = l -> build(start, mid, x), r = r -> build(mid + 1, end, x);
			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(end < a || start > b) return 0;
			else if(start >= a && end <= b) return val;
			else return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}

};

// bool cmp(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b) { return a.s.f > b.s.f; }

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, m, u, v, x, y, q, prev = 0;
		vector < pair < pair <int, int>, pair <int, int> > > :: iterator it;
		node *root;

		scanf("%lld", &n);

		for(i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		
		scanf("%lld", &m);

		for(i = 1; i <= m; i++)
			{
				scanf("%lld %lld %lld", &u, &v, &q);;
				vs.pb(mp(mp(u, v), mp(q, i)));
			}

		// sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < m; i++)
		// 	cout << vs[i].f.f << " " << vs[i].f.s << " " << vs[i].s.f << " " << vs[i].s.s << endl;

		for(it = vs.begin(); it != vs.end(); it++)
			{
				u = it -> f.f, v = it -> f.s, x = it -> s.f, y = it -> s.s;

				if(prev != x)
					{
						root = new node;
						root = root -> build(1, n, x);
					}

				ans[y] = root -> query(1, n, u, v);
				prev = x;
			}

		for(i = 1; i <= m; i++)
			printf("%lld\n", ans[i]);

		return 0;
	}