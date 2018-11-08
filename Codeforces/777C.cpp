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

const int N = 100007;
int is[N], px[N];

struct RangeSTreeLazy
{
	int val;
	RangeSTreeLazy *l, *r;

	int merge(int a, int b) { return a + b; }

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end)
				val = is[start];
			else
				{
					l = new RangeSTreeLazy, r = new RangeSTreeLazy;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, q, i, j, u, v;

		for(i = 0; i < N; i++) is[i] = 1;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) {
				cin >> u;
				if(u >= px[j]) px[j] = u;
				else is[j] = 0;
			}
		
		RangeSTreeLazy *root = new RangeSTreeLazy;
		root = root -> build(1, n);

		cin >> q;

		while(q--) {
			cin >> u >> v;

			cout << root -> query(1, n, u, v) << endl;

			if(root -> query(1, n, u, v)) cout << "Yes\n";
			else cout << "No\n";
		}

		return 0;
	}