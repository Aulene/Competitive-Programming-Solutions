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

const int N = 1000007;
const int M = 300007;
int divs[N], a[M];

struct RSTree
{
	int mx, sum;
	RSTree *l, *r;

	RSTree *build(int start, int end)
		{
			if(start == end)
				sum = mx = a[start]; 
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					sum = l -> sum + r -> sum;
					mx = max(l -> mx, r -> mx);
				}
			return this;
		}

	RSTree *update(int start, int end, int a, int b)	
		{
			if(start > b || end < a)
				return this;

			if(start >= a && end <= b && start == end) {
				sum = mx = divs[sum];
				return this;
			}
			
			if(l -> mxquery(start, mid, a, b) > 2)
				l = l -> update(start, mid, a, b);
			if(r -> mxquery(mid + 1, end, a, b) > 2)
				r = r -> update(mid + 1, end, a, b);

			sum = l -> sum + r -> sum;
			mx = max(l -> mx, r -> mx); 
			return this;
		}

	int mxquery(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return mx;
			else
				return max(l -> mxquery(start, mid, a, b), r -> mxquery(mid + 1, end, a, b));
		}

	int squery(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return sum;
			else
				return l -> squery(start, mid, a, b) + r -> squery(mid + 1, end, a, b);
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
		
		for(int i = 1; i < N; i++)
			for(int j = i; j < N; j += i) divs[j]++;

		int n, m, q, i, j, u, v, w;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		RSTree *root = new RSTree;
		root = root -> build(1, n);

		while(m--) {
			cin >> q >> u >> v;

			if(q == 1) {
				if(root -> mxquery(1, n, u, v) > 2)
					root = root -> update(1, n, u, v);
			}
			else {
				cout << root -> squery(1, n, u, v) << endl;
			}
		}
		return 0;
	}