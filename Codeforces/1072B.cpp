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

int a[100007], b[100007];
int ax[7][N];
int bx[7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, k, u, v;

		cin >> n;

		for(i = 1; i < n; i++) cin >> a[i];
		for(i = 1; i < n; i++) cin >> b[i];

		for(i = 0; i < 4; i++) bx[i] = 1, ax[i][n] = i;

		for(i = 0; i < 4; i++) {

			for(j = n - 1; j >= 1; j--) {

				int ass = 0;

				for(k = 0; k < 4; k++) {
					if(((k | ax[i][j + 1]) == a[j]) && ((k & ax[i][j + 1]) == b[j])) {
						ax[i][j] = k;
						ass = 1;
						break;
					}
				}

				if(!ass) {

					// cout << i << " " << j << endl;

					bx[i] = 0;
					break;
				}
				
			}
		}

		// for(i = 1; i <= n; i++) cout << ax[0][i] << " "; cout << endl;

		for(i = 0; i < 4; i++) {
			if(bx[i]) {
				cout << "YES" << endl;
				for(j = 1; j <= n; j++) cout << ax[i][j] << " "; cout << endl;
				return 0;
			}
		}

		cout << "NO" << endl;
		return 0;
	}