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
		cout.tie(NULL);}
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
			
		int t, n, i, j, u, v, s, a, b, c;

		cin >> t;

		while(t--)
			{
				int ans = 0;

				cin >> s >> a >> b >> c;
				u = floor(s / c);
				v = floor(u / a) * b;
				ans = u + v;
				cout << ans << endl;
			}	
		return 0;
	}