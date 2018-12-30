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

const int N = 100007;
int a[N], t[N];
int lazy[4 * N];

struct RSTree
{
	int val, mx;
	RSTree *l, *r;

	int merge(int a, int b) { return a + b; }

	RSTree *build(int start, int end)
		{
			if(start == end) val = mx = a[start];
			else {
				l = new RSTree, r = new RSTree;
				l = l -> build(start, mid), r = r -> build(mid + 1, end);
				val = merge(l -> val, r -> val);
				mx = max(l -> mx, r -> mx);
			}
			return this;
		}

	RSTree *update(int lazy[], int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != 0) {
				cout << "updbef start, end, val = " << start << " " << end << " " << val << endl;
				val = max(0LL, val - ((end - start + 1) * lazy[level]));

				if(start != end) {
					lazy[2 * level] += lazy[level];
					lazy[2 * level + 1] += lazy[level];
				}

				lazy[level] = 0;
				cout << "upd start, end, val = " << start << " " << end << " " << val << endl;
			}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b) {
				cout << "updbef start, end, val = " << start << " " << end << " " << val << endl;
				val = max(0LL, val - ((end - start + 1) * v));

				if(start != end) {
					lazy[2 * level] += v;
					lazy[2 * level + 1] += v;
				}			

				cout << "upd start, end, val = " << start << " " << end << " " << val << endl;
				return this;
			}

			l = l -> update(lazy, start, mid, a, b, v, 2 * level);
			r = r -> update(lazy, mid + 1, end, a, b, v, 2 * level + 1);
			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int lazy[], int start, int end, int a, int b, int level = 1)
		{
			if(lazy[level] != 0) {

				// cout << "qupd " << val << " " << val - lazy[level] << endl;;

				val = max(0LL, val - ((end - start + 1) * lazy[level]));

				if(start != end) {
					lazy[2 * level] += lazy[level];
					lazy[2 * level + 1] += lazy[level];
				}

				lazy[level] = 0;
			}

			// cout << "start, end, val = " << start << " " << end << " " << val << endl;

			if(start >= a && end <= b) 
				return val;
			else if(end < a || start > b) 
				return 0;
			else
				return merge(l -> query(lazy, start, mid, a, b, 2 * level), r -> query(lazy, mid + 1, end, a, b, 2 * level + 1));
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
		
		int n, m, i, j, u, v, melt = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) cin >> t[i];

		RSTree *root = new RSTree;
		root = root -> build(1, n);

		for(i = 1; i <= n; i++) {

			int prev = root -> query(lazy, 1, n, 1, i);
			root = root -> update(lazy, 1, n, 1, i, t[i]);
			int cur = root -> query(lazy, 1, n, 1, i);

			cout << "prev, cur = " << prev << " " << cur << " " << prev - cur << endl;
		}
		return 0;
	}