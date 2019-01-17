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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)
#define mid (start + end) / 2

const int N = 200007;

vi vx;
vppi vs;
map <int, int> mx;

int ans[N];

struct RSTree
{
	int val;
	RSTree *l, *r;

	int merge(int a, int b) { return a + b; }

	RSTree *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RSTree *update(int start, int end, int a, int b, int v)	
		{
			if(start > b || end < a)
				return this;

			if(start >= a && end <= b) {
				val += v;
				return this;
			}
			
			l = l -> update(start, mid, a, b, v);
			r = r -> update(mid + 1, end, a, b, v);
			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

bool cmp(ppi a, ppi b) { return a.f.f < b.f.f; }

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
		
		int n, m, i, j, u, v, q, num = 1;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> u >> v;
			vx.pb(u), vx.pb(v);
			vs.pb({{u, v}, i});
		}

		sort(vx.begin(), vx.end());

		for(i = 0; i < vx.size(); i++) mx[vx[i]] = num++;

		for(i = 0; i < n; i++) {
			vs[i].f.f = mx[vs[i].f.f];
			vs[i].f.s = mx[vs[i].f.s];
		}

		RSTree *root = new RSTree;
		root = root -> build(1, num);

		for(i = 0; i < n; i++) {
			u = vs[i].f.f, v = vs[i].f.s;
			root = root -> update(1, num, v, v, 1);
		}

		sort(vs.begin(), vs.end(), cmp);

		// cout << num << endl;
		// for(auto it : vs) cout << it.f.f << " " << it.f.s << endl;

		for(i = 0; i < n; i++) {

			u = vs[i].f.f, v = vs[i].f.s, q = vs[i].s;

			// cout << "q = " << u << " " << v << endl;

			// for(j = 1; j <= num; j++) 
			// 	cout << root -> query(1, num, j, j) << " "; cout << endl;
			
			ans[q] = root -> query(1, num, 1, v - 1);
			root = root -> update(1, num, v, v, -1);
		}

		for(i = 1; i <= n; i++) cout << ans[i] << endl;

		return 0;
	}