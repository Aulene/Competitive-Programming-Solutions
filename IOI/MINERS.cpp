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

int a[100007];
int dp[2][4][4][4][4];
bool vis[2][4][4][4][4];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, i, j, k, l, m, u, v, x, ans = 0;
		string s;

		vis[0][0][0][0][0] = 1;

		cin >> n >> s;

		for(i = 1; i <= n; i++) {
			if(s[i - 1] == 'M') a[i] = 1;
			else if(s[i - 1] == 'F') a[i] = 2;
			else a[i] = 3;
		}	

		for(i = 1; i <= n; i++) {

			x = a[i];

			for(j = 0; j < 4; j++) {
				for(k = 0; k < 4; k++) {
					for(u = 0; u < 4; u++) {
						for(v = 0; v < 4; v++) 
							if(vis[0][j][k][u][v]) {

							set <int> sx;
							if(x != 0) sx.insert(x);
							if(j != 0) sx.insert(j);
							if(k != 0) sx.insert(k);
							
							int sz = sx.size();
							dp[1][k][x][u][v] = max(dp[1][k][x][u][v], sz + dp[0][j][k][u][v]);
							ans = max(ans, dp[1][k][x][u][v]);
							vis[1][k][x][u][v] = 1;

							sx.clear();
							if(x != 0) sx.insert(x);
							if(u != 0) sx.insert(u);
							if(v != 0) sx.insert(v);
							
							sz = sx.size();
							dp[1][j][k][v][x] = max(dp[1][j][k][v][x], sz + dp[0][j][k][u][v]);
							ans = max(ans, dp[1][j][k][v][x]);
							vis[1][j][k][v][x] = 1;
						}
					}
				}
			}

			for(j = 0; j < 4; j++) {
				for(k = 0; k < 4; k++) {
					for(u = 0; u < 4; u++) {
						for(v = 0; v < 4; v++) {
							dp[0][j][k][u][v] = dp[1][j][k][u][v]; 
							vis[0][j][k][u][v] = vis[1][j][k][u][v]; 
							dp[1][j][k][u][v] = 0;
							vis[1][j][k][u][v] = 0;
						}
					}
				}
			}
		}

		// for(i = 0; i <= n; i++) {

		// 	x = a[i];

		// 	for(j = 0; j < 4; j++) {
		// 		for(k = 0; k < 4; k++) {
		// 			for(u = 0; u < 4; u++) {
		// 				for(v = 0; v < 4; v++) 
		// 					if(vis[i][j][k][u][v])
		// 					printf("DP[%d][%d][%d][%d][%d] = %d\n", i, j, k, u, v, dp[i][j][k][u][v]);
		// 			}
		// 		}
		// 	}
		// }

		cout << ans << endl;

		return 0;
	}