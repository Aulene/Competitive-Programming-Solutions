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
#define ld long double 
const int N = 1e5 + 7;

int a[N];
ld dp[N];

#define mid (start + end) / 2

ld lazy[400007];

struct RSTree
{
	ld val;
	RSTree *l, *r;

	ld merge(ld a, ld b) { return ((ld) (max(a, b))); }

	RSTree *build(int start, int end)
		{
			if(start == end) val = dp[start];
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RSTree *update(ld lazy[], int start, int end, int a, int b, ld v, int level = 1)	
		{
			if(lazy[level] != 0) {
					val = val * lazy[level];

					if(start != end) {
						if(lazy[2 * level] == 0) {
							lazy[2 * level] += lazy[level];
							lazy[2 * level] += lazy[level];
						}
						else {
							lazy[2 * level] *= lazy[level];
							lazy[2 * level + 1] *= lazy[level];
						}
					}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					val *= v;

					if(start != end) {
						if(lazy[2 * level] == 0) {
							lazy[2 * level] += v;
							lazy[2 * level] += v;
						}
						else {
							lazy[2 * level] *= v;
							lazy[2 * level + 1] *= v;
						}
					}			

					return this;
				}

			l = l -> update(lazy, start, mid, a, b, v, 2 * level);
			r = r -> update(lazy, mid + 1, end, a, b, v, 2 * level + 1);
			val = merge(l -> val, r -> val);
			return this;
		}

	ld query(ld lazy[], int start, int end, int a, int b, int level = 1)
		{
			if(lazy[level] != 0)
				{
					val *= lazy[level];

					if(start != end) {
						if(lazy[2 * level] == 0) {
							lazy[2 * level] += lazy[level];
							lazy[2 * level] += lazy[level];
						}
						else {
							lazy[2 * level] *= lazy[level];
							lazy[2 * level + 1] *= lazy[level];
						}
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
		
		// ifstream cin ("balance.in");
		// ofstream cout ("balance.out");
		
		int n, m, i, j, u, v;
		ld coef = 1.0;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			dp[i] = ((ld) coef * a[i]);
			coef *= 0.5;
		}	

		RSTree *root = new RSTree;
		root = root -> build(1, n);

		for(i = 1; i <= n; i++) {
			ld val = root -> query(lazy, 1, n, 1, n);
			// cout << val << endl;
			int ans = (int) ((ld) 1e5 * val);

			cout << ans << endl;
			root = root -> update(lazy, 1, n, 1, i, (ld) 0.5);
			root = root -> update(lazy, 1, n, i + 1, n, (ld) 2.0);
		}
		return 0;
	}