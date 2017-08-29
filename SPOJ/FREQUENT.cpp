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

#define pff pair < pair < pair <int, int>, pair <int, int> >, pair <int, int> >
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];

struct node
{
	pff val; //left, right, max, f = num, 
	node *l, *r;

	pff merge(pff a, pff b)
		{
			pff ans;
			
		}


	node *build(int start, int end)
		{
			if(start == end)
				val = mp(mp(mp(a[start], 1), mp(a[start], 1)), mp(a[start], 1));
			else
				{
					l = new node, r = new node;
					l = l -> build(1, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, u, v, i, j, ans;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		node *root = new node;
		root = root -> build(1, n);

		while(m--)
			{
				cin >> q;

				if(!q) break;
				
				cin >> u >> v;

				ans = root -> query(u, v);
				cout << ans << endl;
			}
		return 0;
	}