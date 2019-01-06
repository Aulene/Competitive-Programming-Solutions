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

		int n, m, i, j, u, v, dif, ans;

		cin >> n;

		m = sqrt(n);
		u = pow(m, 2);
		v = pow(m + 1, 2);
		dif = (v - u) / 2;

		if(n > u && n <= u + dif) ans = 2 * m + 1;
		else if(n > (u + dif) && n <= v) ans = 2 * m + 2;
		else ans = 2 * m;
		cout << ans << endl;

		return 0;
	}