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
vector <int> temp, emptySet;
stack < pair <int, int> > vs;

bool checktri(int x, int y, int z)
{
	if(x + y <= z || x + z <= y || y + z <= x) return 0;
	return 1;
}

struct node
{
	pair <int, int> val;
	node *l, *r;

	pair <int, int> merge(pair <int, int> a, pair <int, int> b)
		{
			if(a.s > b.s) return a;
			return b;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					val.f = start;
					val.s = a[start];
				}
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}

	node* update(int start, int end, int x, int v)
		{
			if(start == end)
				{
					val.s = v;
					return this;
				}
			else if(x <= mid)
				l = l -> update(start, mid, x, v);
			else
				r = r -> update(mid + 1, end, x, v);

			val = merge(l -> val, r -> val);
			return this;
		}

	pair <int, int> query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				return val;
			else if(end < a || start > b)
				return mp(0, 0);
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v, pos, val, l, r, fuck;
		int ax, b, c;

		// ifstream cin ("fuck.txt");
		// ofstream cout ("ohmyfuck.txt");

		cin >> n >> q;

		for(i = 1; i <= n; i++) cin >> a[i];

		// cout << "inp" << endl;
		node *root = new node;
		root = root -> build(1, n);
		// cout << "letfuckbegin" << endl;

		while(q--)
			{
				cin >> v;

				if(v == 1)
					{
						cin >> pos >> val;
						root = root -> update(1, n, pos, val);
						a[pos] = val;
					}
				else
					{
						fuck = 0;

						cin >> l >> r;
						ax = b = c = 0;
						
						for(i = 0; i < 50; i++)
							{
								pair <int, int> fux = root -> query(1, n, l, r);

								// cout << fux.f << " " << fux.s << endl;

								c = b;
								b = ax;
								ax = fux.s;

								if(checktri(ax, b, c))
									{
										// cout << ax << " " << b << " " << c << endl;
										fuck = ax + b + c;
										break;
									}

								root = root -> update(1, n, fux.f, 0);
								vs.p(fux);
							}
						
						while(!vs.empty())
							{
								int x = vs.top().f, v = vs.top().s;
								root = root -> update(1, n, x, v);
								vs.pop();
							}

						cout << fuck << endl;
					}
			}
		return 0;
	} 