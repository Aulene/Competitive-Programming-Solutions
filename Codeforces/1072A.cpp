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


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, k, i, j, u, v, ans = 0;
		int w, h;

		cin >> w >> h >> k;

		while(k--) {

			if(w < 1 || h < 1) break;

			u = w * h;
			w -= 2, h -= 2;
			v = w * h; 

			// u = (w - 4 * (i - 1)) + (w - 4 * (i));
			// v = (h - 4 * (i - 1)) + (h - 4 * (i));

			// u = (w - 4 * (i - 1));
			// v = (h - 4 * (i - 1));

			// cout << u << " " << v << endl;

			if(u < 0) break;
			

			ans += u;
			if(v < 0) break;
			ans -= v;

			w -= 2, h -= 2;
		}

		cout << ans << endl;


		return 0;
	}