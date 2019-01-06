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

int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m,  b >>= 1;
	return res;
}

int inv(int a, int m) { return a < 2 ? a : ((1 - m * 1ll * inv(m % a, a)) / a % m + m) % m; }

map <int, int> mx;

const int N = 10007;
const int M = 107;
int dp[M][N];
int powers[M], inverses[M];

int solve(int num, int step) {

	if(num == 0) return 1;
	if(step == 0) return powers[num];
	if(dp[num][step] != -1) return dp[num][step];

	int ans = 0;

	for(int i = 0; i <= num; i++) {
		int val = solve(i, step - 1) % mod;
		val = (val * inverses[num + 1]) % mod;
		ans = (ans + val) % mod;
	}

	return dp[num][step] = ans;
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
		
		int n, m, i, j, u, v, ans = 1;

		cin >> n >> m;

		for(i = 2; i < sqrt(n) + 10; i++) {
			while(n % i == 0) {
				n /= i;
				mx[i]++;
			}
		}

		if(n != 1) mx[n]++;

		for(i = 0; i < M; i++) inverses[i] = powmod(i, mod - 2, mod);

		for(auto it : mx) {

			int p = it.f, pw = it.s;

			for(i = 0; i < M; i++)
				for(j = 0; j < N; j++) dp[i][j] = -1;
		
			powers[0] = 1;
			for(i = 1; i <= pw; i++) powers[i] = (powers[i - 1] * p) % mod;

			ans = (ans * solve(pw, m)) % mod;
		}

		cout << ans << endl;

		return 0;
	}