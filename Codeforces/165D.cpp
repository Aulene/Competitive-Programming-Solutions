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

map < pair <int, int>, int> mx;

vvi g(N);

struct node {
	int val;
	node *l, *r;

	int merge(int a, int b) { return a + b; }

	node *build(int start, int end) {
		if(start == end) { val = 1; }
		else {
			l = new node, r = new node;
			l = l -> build(start, mid); r = r -> build(mid + 1, end);
			val = merge(l -> val, r -> val);
		} return this;
	}

	node *update(int start, int end, int x, int v) {

		if(start == end) {
			val = v;
			return this;
		}
		else if(x <= mid) l = l -> update(start, mid, x, v);
		else r = r -> update(mid + 1, end, x, v); 

		val = merge(l -> val, r -> val);
		return this;
	}

	int query(int start, int end, int a, int b) {
		if(end < a || start > b) return 0;
		else if(start >= a && end <= b) return val;
		else return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
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
		
		int n, m, i, j, q, u, v;

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
			mx[{u, v}] = i;
		}	

		node *root = new node;
		root = root -> build(0, n - 1);
		
		cin >> m;

		while(m--) {
			cin >> q;

			if(q == 1) {
				cin >> u;
				
			}
		}
		return 0;
	}