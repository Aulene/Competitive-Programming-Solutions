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

const int N = 1000007;

int cntl[N], cntr[N], a[N];
map <int, int> comp;
multiset <int> mx;

#define mid (start + end) / 2

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
		
		int n, m, i, j, u, v, x = 1, ans = 0;

		cin >> n;

		RSTree *root = new RSTree;
		root = root -> build(1, N - 1);

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			
			if(comp[a[i]] == 0) comp[a[i]] = x++;
			
			a[i] = comp[a[i]];
			cntr[a[i]]++;
			
			root = root -> update(1, N - 1, cntr[a[i]], cntr[a[i]], 1);
		}

		for(i = 1; i <= n; i++) {
			cntl[a[i]]++;
			root = root -> update(1, N - 1, cntr[a[i]], cntr[a[i]], -1);
			cntr[a[i]]--;
			
			// cout << i << " " << a[i] << " " << root -> query(1, N - 1, 1, cntl[a[i]] - 1) << endl;
			
			ans += root -> query(1, N - 1, 1, cntl[a[i]] - 1);
		}

		cout << ans << endl;

		return 0;
	}