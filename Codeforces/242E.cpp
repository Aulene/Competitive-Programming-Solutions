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
const int M = 67;

int a[N];
int lazy[4 * N];

struct RSTree
{
	vi val;
	RSTree *l, *r;

	vi merge(vi a, vi b) {
		vi res;
		for(int i = 0; i < M; i++) res.pb(a[i] + b[i]);
		return res;
	}

	RSTree *build(int start, int end)
		{
			if(start == end) {
				for(int i = 0; i < M; i++) 
					if(a[start] & (1 << i)) val.pb(1);
					else val.pb(0);
			}
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	// RSTree *update(int lazy[], int start, int end, int a, int b, int v, int level = 1)	
	// 	{
	// 		if(lazy[level] != 0)
	// 			{
	// 				for(int i = 0; i < M; i++) {

	// 					if(v & (1 << i)) {

	// 					}
	// 					else {

	// 					}

	// 				}

	// 				if(start != end) {
	// 					lazy[2 * level] += lazy[level];
	// 					lazy[2 * level + 1] += lazy[level];
	// 				}

	// 				lazy[level] = 0;
	// 			}

	// 		if(start > b || end < a)
	// 			return this;

	// 		if(start >= a && end <= b)
	// 			{
	// 				val = v;

	// 				if(start != end) {
	// 					lazy[2 * level] = v;
	// 					lazy[2 * level + 1] = v;
	// 				}			

	// 				return this;
	// 			}

	// 		l = l -> update(lazy, start, mid, a, b, v, 2 * level);
	// 		r = r -> update(lazy, mid + 1, end, a, b, v, 2 * level + 1);
	// 		val = merge(l -> val, r -> val);
	// 		return this;
	// 	}

	// int query(int lazy[], int start, int end, int a, int b, int level = 1)
	// 	{
	// 		if(lazy[level] != 0)
	// 			{
	// 				val += (end - start + 1) * lazy[level];

	// 				if(start != end)
	// 					{
	// 						lazy[2 * level] += lazy[level];
	// 						lazy[2 * level + 1] += lazy[level];
	// 					}

	// 				lazy[level] = 0;
	// 			}

	// 		if(start > b || end < a)
	// 			return 0;
	// 		else if(start >= a && end <= b)
	// 			return val;
	// 		else
	// 			return merge(l -> query(lazy, start, mid, a, b, 2 * level), r -> query(lazy, mid + 1, end, a, b, 2 * level + 1));
	// 	}
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
		
		int n, m, i, j, q, l, r, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		cin >> m;

		while(m--) {
			cin >> q;

			if(q == 1) {
				cin >> l >> r;

			}
			else {
				cin >> l >> r >> u;
			}
		}

		return 0;
	}