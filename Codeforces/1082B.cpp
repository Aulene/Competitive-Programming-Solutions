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

const int N = 100007;

int a[N];

#define mid (start + end) / 2

int lazy[400007];

struct RangeSTreeLazy
{
	int val;
	RangeSTreeLazy *l, *r;

	int merge(int a, int b) { return max(a, b); }

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end)
				val = a[start];
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
		
		int n, m, i, j, u, v, ans = 0;
		int o;
		string s;

		cin >> n >> s;

		for(i = 0; i < n; i++)
			if(s[i] == 'G') a[i] = 1;
			else a[i] = 0;

		RangeSTreeLazy *root = new RangeSTreeLazy;
		root = root -> build(0, n - 1);

		int l = 0, r = 0, enc = 0;

		while(l < n && r < n) {

			while(a[r] == 0 && enc) {
				if(a[l] == 0) {
					l++;
					enc = 0;
					break;
				}
				l++;
			}

			if(a[r] == 0) enc = 1;
			r++;

			if(enc) {
				o = max(root -> query(0, n - 1, 0, l - 1), root -> query(0, n - 1, r + 1, n - 1));
				if(o) ans = max(ans, r - l);
				else ans = max(ans, r - l - 1);
			}
			else ans = max(ans, r - l);

			// cout << l << " " << r << " " << ans << endl;
		}

		cout << ans << endl;
		return 0;
	}