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

const int N = 300007;

int a[N];
int gcdt[N][27], mint[N][27];
int ans = 0;
vector <int> ansv;

void preprocessGcd(int n) {

	for(int i = 1; i <= n; i++)
		gcdt[i][0] = a[i];

	for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            int k = i + (1 << (j - 1));
            gcdt[i][j] = gcd(gcdt[i][j - 1], gcdt[k][j - 1]);
    }
}

int gcdQuery(int x, int y) {
	int len = y - x + 1;
	int k = log2(len);
	return gcd(gcdt[x][k], gcdt[y - (1 << k) + 1][k]);
}

void preprocessMin(int n) {

	for(int i = 1; i <= n; i++)
		mint[i][0] = a[i];

	for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            int k = i + (1 << (j - 1));
            mint[i][j] = min(mint[i][j - 1], mint[k][j - 1]);
    }
}

int minQuery(int x, int y) {
	int len = y - x + 1;
	int k = log2(len);
	return min(mint[x][k], mint[y - (1 << k) + 1][k]);
}

int check(int sz, int n) {
	
	vector <int> vs;
	bool afound = 0;

	for(int i = 1; i <= n; i++) {

		int r = i + sz - 1;

		if(r > n) break;

		int gcdx = gcdQuery(i, r);
		int minx = minQuery(i, r);

		// cout << sz << " " << i << " " << r << " " << gcdx << " " << minx << endl;

		if(gcdx == minx) {
			afound = 1;
			vs.pb(i);
		}
	}

	if(afound) ansv = vs;
	return afound;
}

int bsearch(int low, int high, int n) {

	int ans = 0, mx;

	while(low <= high) {
		mx = (low + high) / 2;
		
		if(check(mx, n)) {
			ans = mx;
			low = mx + 1;
		}
		else {
			high = mx - 1;
		}
	}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i], ansv.pb(i);

		preprocessGcd(n);
		preprocessMin(n);

		ans = bsearch(1, n, n);

		cout << ansv.size() << " " << ans - 1 << endl;
		for(auto it : ansv) cout << it << " "; cout << endl;

		return 0;
	}