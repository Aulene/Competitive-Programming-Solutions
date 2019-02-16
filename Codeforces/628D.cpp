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

const int N = 2007;
const int M = 3;

vi v1, v2;

int m, d; // given digit
int dp[N][N][M]; // dp[modval][pos][is_eq]

void init() {
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) 
			for(int k = 0; k < M; k++) dp[i][j][k] = -1;
}

int solve(vi &v, int mval, int pos, bool is_eq) {

	if(pos == v.size()) {
		if(mval == 0) {
			printf("Returning 1\n");
			return 1;
		}
		printf("Returning 0\n");
		return 0;
	}

	if(dp[mval][pos][is_eq] != -1) return dp[mval][pos][is_eq];

	int ret = 0;

	if(!is_eq) {
		
		printf("Check [%lld][%lld][%d]\n", mval, pos, is_eq);

		if(pos % 2 == 0) {
			ret = (ret + solve(v, (mval * 10 + d) % m, pos + 1, 0)) % mod;
		}
		else {
			for(int i = 0; i < 10; i++)
				if(i != d) {
					printf("Open %lld from [%lld][%lld][%d]\n", i, mval, pos, is_eq);
					ret = (ret + solve(v, (mval * 10 + i) % m, pos + 1, 0)) % mod;
					printf("Close %lld from [%lld][%lld][%d]\n", i, mval, pos, is_eq);
				}
		}	
	}
	else {
		if(pos % 2 == 0) {
			if(v[pos] > d) ret = (ret + solve(v, (mval * 10 + d) % m, pos + 1, 0)) % mod;
			else if(v[pos] == d) ret = (ret + solve(v, (mval * 10 + d) % m, pos + 1, 1)) % mod;
			else ret = 0;
		}
		else {
			for(int i = 0; i < v[pos]; i++)
				if(i != d) {
					printf("Open %lld from [%lld][%lld][%d]\n", i, mval, pos, is_eq);
					ret = (ret + solve(v, (mval * 10 + i) % m, pos + 1, 0)) % mod;
					printf("Close %lld from [%lld][%lld][%d]\n", i, mval, pos, is_eq);
				}
			if(v[pos] != d) ret = (ret + solve(v, (mval * 10 + v[pos]) % m, pos + 1, 1)) % mod;
		}
	}

	return dp[mval][pos][is_eq] = ret;
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
		

		int i, j, k, u, v, ans1 = 0, ans2 = 0, ans;
		string a, b;

		cin >> m >> d >> a >> b;

		for(i = a.size() - 1; i >= 0; i--) v1.pb((int) (a[i] - '0')); v1.pb(-1);
		for(i = b.size() - 1; i >= 0; i--) v2.pb((int) (b[i] - '0')); v2.pb(-1);

		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());

		for(auto it : v1) cout << it << " "; cout << endl;
		for(auto it : v2) cout << it << " "; cout << endl;

		init();
		ans1 = solve(v1, 0, 1, 1);
		for(i = 0; i < m; i++)
			for(j = 1; j < v2.size(); j++)
				for(k = 0; k < 2; k++) printf("DP[%lld][%lld][%lld] = %lld\n", i, j, k, dp[i][j][k]);

		cout << endl;

		// init();
		// ans2 = solve(v2, 0, 1, 1);

		// for(i = 0; i < m; i++)
		// 	for(j = 1; j < v2.size(); j++)
		// 		for(k = 0; k < 2; k++) printf("DP[%lld][%lld][%lld] = %lld\n", i, j, k, dp[i][j][k]);

		cout << ans1 << " " << ans2 << endl;

		// ans = (ans2 - ans1 + mod) % mod;
		// cout << ans << endl;

		return 0;
	}