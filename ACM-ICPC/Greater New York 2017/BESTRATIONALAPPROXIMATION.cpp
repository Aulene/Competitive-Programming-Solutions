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
#define ld double
#define ldx (ld)

// p = q * approx

int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("BESTRATIONALEXP.txt");
		// ofstream cout ("output.txt");
		
		int t, n, m, i, j, k, u, v;
		double approx, x, y, mdiff, diff;

		cin >> t;

		while(t--)
			{
				int ansx, ansy;
				mdiff = 10;

				scanf("%d %d", &k, &n);
				cin >> approx;

				// cin >> k >> n >> approx;

				if(approx == 0) {
					// printf("%d 0/1\n", k);	
					continue;
				}	

				for(int i = 1; i <= n; i++) {
					x = ldx i * approx;
					u = ceil(x);
					v = floor(x);

					// cout << i << " " << u << " " << v << endl;

					y = ldx (ldx u / i);
					diff = ldx abs(ldx approx - y);

					// cout << y << " " << diff << endl;

					if(diff < mdiff) {
						mdiff = diff;
						ansx = u;
						ansy = i;
					}

					y = ldx (ldx v / i);
					diff = ldx abs(ldx approx - y);

					// cout << y << " " << diff << endl;

					if(diff < mdiff) {
						mdiff = diff;
						ansx = v;
						ansy = i;
					}
				}

				// cout << k << " " << ansx << "/" << ansy << endl;
				printf("%d %d/%d\n", k, ansx, ansy);
			}

		return 0;
	}

