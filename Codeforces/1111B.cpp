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

const int N = 100007;
int a[N], pre[N];

int numOps(int m, int rem_supers) {
	return m - rem_supers;
}

int numUps(int supers_left, int k, int ops) {
	return min(supers_left * k, ops); 
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, k, m, i, j, u, v;
		ld ans = 0, sum, avg;

		cin >> n >> k >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		sort(a + 1, a + n + 1);

		// for(i = 1; i <= n; i++) cout << a[i];
			
		for(i = 1; i <= n; i++) pre[i] = a[i] + pre[i - 1];

		for(i = 0; i < n; i++) {

			int power = pre[n] - pre[i];
			int operations = numOps(m, i);
			int upgrades = numUps(n - i, k, operations);

			// printf("%lld %lld %lld %lld\n", i, power, operations, upgrades);
			// 
			sum = power + upgrades;
			avg = ((ld) sum / (n - i));
			if(ans < avg) ans = avg; 
		}

		printf("%0.16Lf\n", ans);
		// cout << ans << endl;
		return 0;
	}