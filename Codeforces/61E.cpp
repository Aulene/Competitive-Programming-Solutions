#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

const int N = 1000007;

int a[N];

struct MSTree
{
	vector <int> vs;
	MSTree *l, *r;

	int sum(int a, int b) { return a + b; }

	MSTree *build(int start, int end)
		{
			if(start == end)
				vs = vi(1, a[start]);
			else
				{
					l = new MSTree, r = new MSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					merge(l->vs.begin(), l->vs.end(), r->vs.begin(),r->vs.end(), back_inserter(vs));
				}
			return this;
		}

	int lquery(int start, int end, int a, int b, int x)
		{
			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return lower_bound(vs.begin(), vs.end(), x) - vs.begin();
			else
				return sum(l -> lquery(start, mid, a, b, x), r -> lquery(mid + 1, end, a, b, x));
		}

	int gquery(int start, int end, int a, int b, int x)
		{
			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return vs.end() - upper_bound(vs.begin(), vs.end(), x);
			else
				return sum(l -> gquery(start, mid, a, b, x), r -> gquery(mid + 1, end, a, b, x));
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
		
		int n, m, i, j, u, v, x = 1;
		long long int ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		MSTree *root = new MSTree;
		root = root -> build(1, n);

		for(i = 2; i <= n - 1; i++) {
			u = root -> gquery(1, n, 1, i - 1, a[i]);
			v = root -> lquery(1, n, i + 1, n, a[i]);
			ans += (long long int) u * v;
		}

		cout << ans << endl;
		return 0;
	}