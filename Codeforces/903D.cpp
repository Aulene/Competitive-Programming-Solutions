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

int a[N];

vpi vs;

bool cmp(pi a, pi b) { return a.s < b.s; }

struct RSTree
{
	pi gval;
	pi sval;

	RSTree *l, *r;

	pi merge(pi a, pi b) { return mp(a.f + b.f, a.s + b.s); }

	RSTree *build(int start, int end)
		{
			if(start == end) {
				gval = mp(a[start], 1);
				sval = zp;
			}
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					gval = merge(l -> gval, r -> gval);
					sval = merge(l -> sval, r -> sval);
				}
			return this;
		}

	RSTree *gupdate(int start, int end, int a, int b)	
		{
			if(start > b || end < a)
				return this;

			if(start >= a && end <= b) {
				gval = zp;
				return this;
			}
			
			l = l -> gupdate(start, mid, a, b);
			r = r -> gupdate(mid + 1, end, a, b);
			gval = merge(l -> gval, r -> gval);
			return this;
		}

	RSTree *supdate(int start, int end, int a, int b, int v)	
		{
			if(start > b || end < a)
				return this;

			if(start >= a && end <= b) {
				sval = mp(v, 1);
				return this;
			}
			
			l = l -> supdate(start, mid, a, b, v);
			r = r -> supdate(mid + 1, end, a, b, v);
			sval = merge(l -> sval, r -> sval);
			return this;
		}

	pi gquery(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				return mp(0, 0);
			else if(start >= a && end <= b)
				return gval;
			else
				return merge(l -> gquery(start, mid, a, b), r -> gquery(mid + 1, end, a, b));
		}

	pi squery(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				return mp(0, 0);
			else if(start >= a && end <= b)
				return sval;
			else
				return merge(l -> gquery(start, mid, a, b), r -> gquery(mid + 1, end, a, b));
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
		
		int n, m, i, j, k, u, v, ans = 0;
		pi gp, sp;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			vs.pb({i, a[i]});
		}

		sort(vs.begin(), vs.end());

		RSTree *root = new RSTree;
		root = root -> build(1, n);

		j = k = 0;

		for(i = 0; i < n; i++) {
			u = vs[i].f, v = vs[i].s;

			sp = root -> squery(1, n, u + 1, n);

			while(j < n && vs[j].s == v) {
				root = root -> gupdate(1, n, vs[j].f, vs[j].f);
				j++;
			}

			gp = root -> gquery(1, n, u + 1, n);

		}


		return 0;
	}