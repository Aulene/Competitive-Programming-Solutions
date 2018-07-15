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
#define mid (low + high) / 2

vector < pair <int, pair <int, int> > > vs;
int ans[100007];

struct node
{
	int val;
	node *l, *r;

	node *updt(int low, int high)
		{
			if(low == high) return this;

			l -> val = (l -> val + val) % mod;
			r -> val = (r -> val + val) % mod;
			val = 0;

			return this; 
		}

	node* build(int low, int high)
		{
			if(low == high)
				val = 0;
			else
				{
					l = new node, r = new node;
					l = l -> build(low, mid), r = r -> build(mid + 1, high);
					val = 0;
				}
			return this;
		}

	node* update(int low, int high, int a, int b, int x)
		{
			updt(low, high);

			if(high < a || low > b) return this;

			if(a <= low && b >= high)
				{
					val = (val + x) % mod; 
					return this;
				}

			l = l -> update(low, mid, a, b, x);
			r = r -> update(mid + 1, high, a, b, x);
			
			return this;
		}

	int query(int low, int high, int x)
		{
			if(low == high) return val;

			updt(low, high);

			if(x <= mid) return l -> query(low, mid, x);
			else return r -> query(mid + 1, high, x); 
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, u, v, type;
		pair <int, pair <int, int> > temp;

		cin >> t;

		while(t--)
			{
				cin >> n >> m;

				vs.clear();
				for(i = 0; i <= n; i++) ans[i] = 0;

				node *root = new node;
				root = root -> build(0, n + 100007);

				for(i = 0; i < m; i++)
					{
						cin >> type >> u >> v;
						u--, v--;
						vs.pb(mp(type, mp(u, v)));
					}

				for(i = m - 1; i >= 0; i--)
					{
						temp = vs[i];

						u = (root -> query(0, m - 1, i) + 1) % mod; 
						
						if(temp.f == 1)
							{
								ans[temp.s.f] = (ans[temp.s.f] + u) % mod;
								ans[temp.s.s + 1] = (ans[temp.s.s + 1] - u + mod) % mod;
							}
						else
							root = root -> update(0, m - 1, temp.s.f, temp.s.s, u);
					}

				for(i = 1; i < n; i++) ans[i] = (ans[i] + ans[i - 1]) % mod;
				for(i = 0; i < n; i++) cout << ans[i] % mod << " ";
				cout << endl;
			}
		return 0;
	}