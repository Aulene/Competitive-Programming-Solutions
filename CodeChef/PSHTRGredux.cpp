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

bool checktri(int x, int y, int z)
{
	if(x + y <= z || x + z <= y || y + z <= x) return 0;
	return 1;
}

pair < vector <int>, pair <int, int> > merge(pair < vector <int>, pair <int, int> > a, pair < vector <int>, pair <int, int> > b)
{
	pair < vector <int>, pair <int, int> > ans;
	temp.clear();
 
	int p1 = 0, p2 = 0, minxx = 0, lol = max(a.s.s, b.s.s);
	p1 = upper_bound(a.f.begin(), a.f.end(), a.s.f) - a.f.begin();
	p2 = upper_bound(b.f.begin(), b.f.end(), b.s.f) - b.f.begin();
 	
 	cout << "MERGING" << endl;
 	for(auto it: a.f) cout << it << " "; cout << endl;
 	for(auto it: b.f) cout << it << " "; cout << endl;

	while(p1 < a.f.size() || p2 < b.f.size())
		{
			if(p1 == a.f.size() && p2 == b.f.size()) break;
 
			if(p1 == a.f.size()) 
				{ 
					temp.pb(b.f[p2]); 
					p2++;					
				}
			else if(p2 == b.f.size()) 
				{
					temp.pb(a.f[p1]); 
					p1++;
				}
			else
				{
				 	if(a.f[p1] > b.f[p2])
				 		{
				 			temp.pb(b.f[p2]); 
							p2++;
				 		}
				 	else
				 		{
							temp.pb(a.f[p1]); 
							p1++;
				 		}
				}
		}
 
	if(temp.size() >= 3)
		{
			for(int i = temp.size() - 3; i >= 0; i--)
				{
					if(checktri(temp[i], temp[i + 1], temp[i + 2])) 
						{
							lol = max(lol, temp[i] + temp[i + 1] + temp[i + 2]);
							minxx = temp[i];
							break;
						}
				}
		}
 
	ans = mp(temp, mp(minxx, lol));
	cout << minxx << " " << lol << endl;
	cout << temp.size() << endl;
	cout << "FUCKMEDADDY" << endl;
	return ans;
}

struct node
{
	multiset <int> val;
	node *l, *r;

	multiset <int> mergeMeDaddy(multiset <int> a, multiset <int> b)
		{
			multiset <int> x;
			x.insert(a.begin(), a.end());
			x.insert(b.begin(), b.end());
			return x;
		}

	node* build(int start, int end)
		{
			if(start == end)
				val.insert(a[start]);
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = mergeMeDaddy(l -> val, r -> val);
				}
			return this;
		}

	node* update(int start, int end, int x, int v)
		{
			val.erase(a[x]);
			val.insert(v);

			if(start == end) return this;
			else if(x <= mid) l = l -> update(start, mid, x, v);
			else r = r -> update(mid + 1, end, x, v);

			val = mergeMeDaddy(l -> val, r -> val);

			return this;
		}

	pair < vector <int>, pair <int, int> > query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				{
					vector <int> temp;

					for(multiset <int> :: iterator it = val.begin(); it != val.end(); it++) 
						temp.pb(*it);

					return mp(temp, mp(0, 0));
				}
			else if(end < a || start > b)
				return mp(emptySet, mp(0, 0));
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v, pos, val, l, r, fuck;
		vector <int> ans;

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
						// cout << l << " " << r << endl;

						ans = root -> query(1, n, l, r).f;
						cout << root -> query(1, n, l, r).s.f << " " << root -> query(1, n, l, r).s.s << endl;

						for(i = ans.size() - 3; i >= 0; i--)
							if(checktri(ans[i], ans[i + 1], ans[i + 2]))
								{
									fuck = ans[i] + ans[i + 1] + ans[i + 2];
									break;
								}
						
						cout << fuck << endl;
					}
			}
		return 0;
	} 