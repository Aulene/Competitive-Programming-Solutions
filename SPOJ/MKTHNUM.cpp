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

const int N = 100007;

int a[N];

#define mid (start + end) / 2

struct MSTree
{
	vector <int> vs;
	MSTree *l, *r;

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

	vi query(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				return vi(0);
			else if(start >= a && end <= b) 
				return vs;
			else {
				vi lv, rv, v;
				lv = l -> query(start, mid, a, b);
				rv = r -> query(mid + 1, end, a, b);
				merge(lv.begin(), lv.end(), rv.begin(),rv.end(), back_inserter(v));
				return v;
			}
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
		vi ansv;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		MSTree *root = new MSTree;
		root = root -> build(1, n);

		while(m--) {
			cin >> u >> v >> j;
			ansv = root -> query(1, n, u, v);
			cout << ansv[j - 1] << endl;
		}
		return 0;
	}