#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

const int N = 107;

long double dp[N][N][N];

void recur(int r, int s, int p) {
	if((s == 0 && r == 0) || (s == 0 && p == 0) || (p == 0 && r == 0))
		return;
	
	long double num, denom, pr;

	denom = r * p + r * s + p * s;

	if(r) {
		num = r * p;
		pr = (long double) num / denom;
		// cout << num << " " << denom << " " << pr << endl;
		dp[r - 1][s][p] = (long double) dp[r][s][p] * pr;
		recur(r - 1, s, p);
	}

	if(s) {
		num = r * s;
		pr = (long double) num / denom;
		// cout << num << " " << denom << " " << pr << endl;
		dp[r][s - 1][p] = (long double) dp[r][s][p] * pr;
		recur(r, s - 1, p);
	}

	if(p) {
		num = p * s;
		pr = (long double) num / denom;
		// cout << num << " " << denom << " " << pr << endl;
		dp[r][s][p - 1] = (long double) dp[r][s][p] * pr;
		recur(r, s, p - 1);
	}
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
		
		int p, q, r, s, n, m, i, j, k, u, v;
		long double a = 0, b = 0, c = 0;

		cin >> r >> s >> p;

		dp[r][s][p] = 1.00;
		recur(r, s, p);

		for(i = 1; i <= r; i++) a += dp[i][0][0];
		for(i = 1; i <= s; i++) b += dp[0][i][0];
		for(i = 1; i <= p; i++) c += dp[i][0][i];

		for(i = 0; i <= r; i++)
			for(j = 0; j <= s; j++)
				for(k = 0; k <= p; k++)
					printf("%d %d %d %.9Lf\n", i, j, k, dp[i][j][k]);

		printf("%.9Lf %.9Lf %.9Lf\n", a, b, c);

		return 0;
	}