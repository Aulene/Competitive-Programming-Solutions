#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
// #define int long long int
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
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

#define ld long double

const int N = 10007;
const int M = 27;

int a[N], b[N], played[N][N];
ld dp[N][M];

pi range(int idx, int rd_no) { 
	int low = 1, high = 1 << (rd_no);
	for(int i = 0; ; i++) 
		if((low + (1 << rd_no) * i) <= idx && idx <= (high + (1 << rd_no)  * i)) 
			return mp(low + (1 << rd_no) * i, high + (1 << rd_no) * i);
}

int find_pow(int n) {
	int val = 1;
	while(val <= n) {
		val <<= 1;
	}
	// val >>= 1;
	return val;
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
		
		int n, m, i, j, k, u, v, dale;
		ld prob_win, prob_sum, prob_beat;

		// pi rng;
		// rng = range(5, 2);
		// cout << rng.f << " " << rng.s << endl;

		cin >> n >> dale;

		for(i = 0; i < n - 1; i++) cin >> a[i];

		int new_n = find_pow(n);
		int byes = new_n - n;
		int matches = log2(new_n);

		sort(a, a + (n - 1));

		j = 0;

		for(i = 1; i <= new_n; i++) {
			if(byes && i > 1 && b[i - 1] != 0) 
				{ byes--; continue; }
			else {
				if(i == 1) b[i] = dale;
				else b[i] = a[j], j++;
			}
		}

		// for(i = 1; i <= new_n; i++) cout << b[i] << " "; cout << endl;
		for(i = 1; i <= new_n; i++) dp[i][0] = 1.0;

		for(i = 1; i <= matches; i++) {
			
			for(j = 1; j <= new_n; j++) {

				pi rng = range(j, i);
				prob_win = dp[j][i - 1];
				prob_sum = 0.0;

				// printf("idx: %lld match: %lld low: %lld high: %lld\n", j, i, rng.f, rng.s);

				for(k = rng.f; k <= rng.s; k++) {
					if(k != j && !played[j][k] && !(b[j] == 0 && b[k] == 0) ) {
						prob_beat = ((ld) b[j] / (b[j] + b[k]));
						// printf("opp: %lld prob_beat: %.4Lf\n", k, prob_beat); 
						// printf("prob_prev: %.4Lf\n", dp[k][i - 1]);
						prob_sum += (ld) dp[k][i - 1] * prob_beat;
						played[j][k] = 1;
					}
				}
				
				prob_win *= prob_sum;
				dp[j][i] = prob_win;
				
				// printf("prob_win: %.4Lf prob_sum: %.4Lf\n", prob_win, prob_sum);
			}
		}

		// for(i = 0; i <= matches; i++) {
		// 	for(j = 1; j <= new_n; j++) printf("%.4Lf ", dp[j][i]); cout << endl;
		// }
		
		cout << fixed << setprecision(9) << dp[1][matches] << endl;
		// printf("%0.16Lf\n", dp[1][matches]);
		return 0;
	}