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
#define zp mp(0, 0)
#define mid (start + end) / 2

const int N = 200007;

int a[N];
int lazy[400007];

struct RangeSTreeLazy
{
	int val;
	RangeSTreeLazy *l, *r;

	int merge(int a, int b) { return a + b; }

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new RangeSTreeLazy, r = new RangeSTreeLazy;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RangeSTreeLazy *update(int lazy[], int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != 0) {
				val += (end - start + 1) * lazy[level];

				if(start != end) {
					lazy[2 * level] += lazy[level];
					lazy[2 * level + 1] += lazy[level];
				}

				lazy[level] = 0;
			}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b) {
				val += (end - start + 1) * v;

				if(start != end) {
					lazy[2 * level] += v;
					lazy[2 * level + 1] += v;
				}			

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
				val += (end - start + 1) * lazy[level];

				if(start != end) {
					lazy[2 * level] += lazy[level];
					lazy[2 * level + 1] += lazy[level];
				}

				lazy[level] = 0;
			}

			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return val;
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
		
		int n = 1, m, k, q, i, j, u, v;

		RangeSTreeLazy *root = new RangeSTreeLazy;
		root = root -> build(0, N - 1);

		cin >> m;

		while(m--) {

			// cout << n << endl;
			// for(i = 0; i < n; i++) 
			// 	cout << root -> query(lazy, 0, N - 1, i, i) << " "; cout << endl;

			cin >> q;

			if(q == 1) {
				cin >> u >> v;
				root = root -> update(lazy, 0, N - 1, 0, u - 1, v);
			}
			else if(q == 2) {
				cin >> v;
				root = root -> update(lazy, 0, N - 1, n, n, v);
				n++;
			}
			else {
				int rem = root -> query(lazy, 0, N - 1, n - 1, n - 1);

				// cout << rem << endl;

				root = root -> update(lazy, 0, N - 1, n - 1, n - 1, -rem); 
				n--;
			}
			
			int sum = root -> query(lazy, 0, N - 1, 0, n - 1);

			// cout << sum << " " << n << endl;

			long double ans = (long double) sum / n;

			printf("%.9Lf\n", ans);
		}	

		return 0;
	}