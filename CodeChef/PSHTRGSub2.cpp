#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2

int n, q;
int a[100007];
int wtf[7];

bool checktri(int x, int y, int z)
{
	if(x + y <= z || x + z <= y || y + z <= x) return 0;
	return 1;
}

// struct node
// {
// 	pair < pair <int, int>, pair <int, int> > val;
// 	node *l, *r;

// 	pair < pair <int, int>, pair <int, int> > merge(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b)
// 		{
// 			pair < pair <int, int>, pair <int, int> > x;

// 			wtf[0] = a.f.f, wtf[1] = a.f.s, wtf[2] = a.s;
// 			wtf[3] = b.f.f, wtf[4] = b.f.s, wtf[5] = b.s;
// 			sort(wtf, wtf + 6);

// 			for(i = 1; i <= 4; i++)
// 			x.f.f = wtf[5];
// 			x.f.s = wtf[4];
// 			x.s = wtf[3];

// 			return x;
// 		}

// 	node* build(int start, int end)
// 		{
// 			if(start == end)
// 				{
// 					val = mp(mp(a[start], 0), mp(0, a[start]));
// 					// cout << start << " " << val.f << " " << val.s << endl;
// 				}
// 			else
// 				{
// 					l = new node, r = new node;
// 					l = l -> build(start, mid), r = r -> build(mid + 1, end);
// 					val = merge(l -> val, r -> val);
// 					// cout << start << " " << end << " " << val.f << " " << val.s << endl;
// 				}
// 			return this;
// 		}

// 	node* update(int start, int end, int x, int v)
// 		{
// 			if(start == end)
// 				{
// 					val = mp(mp(v, 0), mp(0, v));
// 					return this;
// 				}
// 			else if(x <= mid)
// 				l = l -> update(start, mid, x, v);
// 			else
// 				r = r -> update(mid + 1, end, x, v);

// 			val = merge(l -> val, r -> val);
// 			return this;
// 		}

// 	pair < pair <int, int>, pair <int, int>  > query(int start, int end, int a, int b)
// 		{
// 			if(start >= a && end <= b)
// 				{
// 					// cout << start << " " << end << endl;
// 					return val;
// 				}
// 			else if(end < a || start > b) return mp(mp(0, 0), mp(0, 0));
// 			else return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
// 		}
// };

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v, pos, val, l, r;
		pair < pair <int, int>, pair <int, int> > ans;

		cin >> n >> q;

		for(i = 1; i <= n; i++) cin >> a[i];

		// node *root = new node;
		// root = root -> build(1, n);

		// while(q--)
		// 	{
		// 		cin >> v;

		// 		if(v == 1)
		// 			{
		// 				cin >> pos >> val;
		// 				root = root -> update(1, n, pos, val);
		// 			}
		// 		else
		// 			{
		// 				cin >> l >> r;
		// 				ans = root -> query(1, n, l, r);

		// 				cout << ans.f.f << " " << ans.f.s << " " << ans.s << endl;

		// 				if(ans.f.f && ans.f.s && ans.s) cout << ans.f.f + ans.f.s + ans.s << endl;
		// 				else cout << 0 << endl;
		// 			}
		// 	}
		
		while(q--)
			{
				cin >> v;
				
				if(v == 1)
					{
						cin >> pos >> val;
						a[pos] = val;
					}
				else
					{
						vector <int> vs(100007);

						cin >> l >> r;
						for(i = l; i <= r; i++) vs.pb(a[i]);
						sort(vs.begin(), vs.end());

						int ansv = 0;

						for(i = 0; i < vs.size() - 2; i++)
							if(checktri(vs[i], vs[i + 1], vs[i + 2])) 
								ansv = vs[i] + vs[i + 1] + vs[i + 2];

						cout << ansv << endl;
					}
			}
		return 0;
	}