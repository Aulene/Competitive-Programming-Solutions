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

int a[N];

#define mid (start + end) / 2

struct RSTree
{
	int val;
	RSTree *l, *r;

	int merge(int a, int b) { return a + b; }

	RSTree *build(int start, int end)
		{
			if(start == end)
				val = a[start];
			else
				{
					l = new RSTree, r = new RSTree;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v;

		while(true) {

			cin >> n >> m;

			for(i = 1; i <= n; i++) cin >> a[i];

			for(i = 1; i <= n; i++) {

			}
			RSTree *root = new RSTree;
			root = root -> build(1, n);

			while(m--) {
				cin >> u >> v;
				vpi av = root -> query(1, n, u, v);
				pi ansp = fmax(av);
				// for(auto it : av) cout << it.f << " " << it.s << endl; cout << endl;
				
			}

		}	
		return 0;
	}