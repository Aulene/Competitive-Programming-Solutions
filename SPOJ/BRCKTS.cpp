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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2

string s;

struct node
{
	pair <int, int> val; // open, closed, complete
	node *l, *r;

	pair <int, int> merge(pair <int, int> a, pair <int, int> b)
		{
			int x = min(a.f, b.s);
			pair <int, int> ans = mp(0, 0);
			ans.f = a.f + b.f - x;
			ans.s = a.s + b.s - x;
			return ans;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					if(s[start] == '(') val = mp(1, 0);
					else val = mp(0, 1);
				}
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}

	node *update(int start, int end, int x)
		{
			if(start == end)
				{
					if(s[x] == '(')
						{
							s[x] = ')';
							val = mp(0, 1);
						}
					else
						{
							s[x] = '(';
							val = mp(1, 0);
						}

					return this;
				}
			else if(x <= mid) l = l -> update(start, mid, x);
			else r = r -> update(mid + 1, end, x);

			val = merge(l -> val, r -> val);
			return this;
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u;
		pair <int, int> ans;

		for(t = 1; t <= 10; t++)
			{
				cin >> n >> s >> j;

				node *root = new node;
				root = root -> build(0, n - 1);

				cout << "Test " << t << ":" << endl;

				while(j--)
					{
						cin >> u;

						if(!u)
							{
								ans = root -> val;
								if(ans.f || ans.s) cout << "NO\n";
								else cout << "YES\n";
							}

						else root = root -> update(0, n - 1, u - 1);
					}
			}
		return 0;
	}