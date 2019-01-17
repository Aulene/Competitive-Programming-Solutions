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
#define pipi pair < pi, pi >
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 100007;

int a[N];

#define mid (start + end) / 2

struct node
{
	pair < pair <int, int>, pair <int, int> > val; // presum, sufsum, mainsum, anssum
	node *l, *r;
 
	pair < pair <int, int>, pair <int, int> > merge(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b)
		{
			pair < pair <int, int>, pair <int, int> > x;
 
			x.f.f = max(a.f.f, a.s.f + b.f.f);
			x.f.s = max(a.f.s + b.s.f, b.f.s);
			x.s.f = a.s.f + b.s.f;
 
			x.s.s = max(a.s.s, b.s.s);
			x.s.s = max(x.s.s, x.f.f);
			x.s.s = max(x.s.s, x.f.s);
			x.s.s = max(x.s.s, x.s.f);
			x.s.s = max(x.s.s, a.f.s + b.f.f);
			return x;
		}
 
	node *build(int start, int end)
		{
			if(start == end)
				val.f.f = val.f.s = val.s.f = val.s.s = -1e10;
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);				
				}
			return this;
		} 
 
	node *update(int start, int end, int u, int v)
		{
			if(start == end)
				{
					val.f.f = val.f.s = val.s.f = val.s.s = v;
					return this;
				}
			else if(u <= mid)
				l = l -> update(start, mid, u, v);
			else
				r = r -> update(mid + 1, end, u, v);
 
			val = merge(l -> val, r -> val);
			return this;
		}
 
	pair < pair <int, int>, pair <int, int> > query(int start, int end, int a, int b)
		{
			if(end < a || start > b)
				return mp(mp(-1e16, -1e16), mp(-1e16, -1e16));
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		vi qs, ansv;
		for(i = 1; i <= n; i++) cin >> u, qs.pb(u);
		reverse(qs.begin(), qs.end());

		node *root = new node;
		root = root -> build(1, n);

		for(auto it : qs) {
			pipi query = root -> query(1, n, 1, n);
			u = max(0LL, query.s.s);
			ansv.pb(u);
			root = root -> update(1, n, it, a[it]);
		}

		reverse(ansv.begin(), ansv.end());

		for(auto it : ansv) cout << it << endl;

		return 0;
	}