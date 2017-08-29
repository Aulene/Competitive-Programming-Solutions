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

#define int long long
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2

int a[100007];

struct node 
{
	int val;
	bool pendingUpdate;

	node *l, *r;

	int merge(int a, int b)	{ return a + b; }

	node* build(int start, int end)
		{
			if(start == end)
				{
					val = a[start];
					return this;
				}

			l = new node, r = new node;
			l = l -> build(start, mid), r = r -> build(mid + 1, end);
			val = merge(l -> val, r -> val);	
			return this;
		}

	node* update(int start, int end, int a, int b)
		{
			if(val == 1)
				return this;

			if(start > b || end < a)
				return this;

			if(start == end)
				{
					val = floor(sqrt(val));	
					return this;
				}

			if(mid >= end) l = l -> update(start, mid, a, b);
			else if(mid < start) r = r -> update(mid + 1, end, a, b);
			else l = l -> update(start, mid, a, b), r -> update(mid + 1, end, a, b);

			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				return val;
			else if(start > b || end < a)
				return 0;
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}	
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, n, m, u, v, q, ans, x = 1;
		
		while(scanf("%lld", &n) != EOF)
			{
				for(i = 1; i <= n; i++)
					scanf("%lld", &a[i]);

				scanf("%lld", &m);

				node *root = new node;
				root = root -> build(1, n);

				printf("Case #%lld:\n", x);
				x++;

				while(m--)
					{
						scanf("%lld %lld %lld", &q, &u, &v);

						if(u > v) swap(u, v);
						if(!q) root = root -> update(1, n, u, v);
						else ans = root -> query(1, n, u, v), printf("%lld\n", ans);
					}
				
				printf("\n");
			}
		return 0;
	}