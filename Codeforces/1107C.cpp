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

const int N = 200007;

// vvi vs(N);
int a[N];

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
		
		int n, m, i, j, u, v, ans = 0;
		string s;

		cin >> n >> m;

		for(i = 0; i < n; i++) cin >> a[i];

		cin >> s;

		// for(i = 0; i < n; i++) {
		// 	cout << s[i] << " " << a[i] << endl;
		// 	vs[((int) s[i] - 'a')].pb(a[i]);
		// }
			

		// for(i = 0; i < 26; i++) 
		// 	sort(vs[i].begin(), vs[i].end(), greater <int>());

		// for(i = 0; i < 26; i++) {
		// 	cout << i << " f ";
		// 	for(j = 0; j < min(m, (int) vs[i].size()); j++) {
		// 		cout << vs[i][j] << " ";
		// 		ans += vs[i][j];
		// 	}
		// 	cout << endl;
		// }
		
		for(i = 0; i < n; i++) {
			vi vs;

			for(j = i; s[j] == s[i] && j < n; j++)
				vs.pb(a[j]);

			sort(vs.begin(), vs.end(), greater <int>());

			i = j - 1;

			for(j = 0; j < min(m, (int) vs.size()); j++) ans += vs[j];

		}

		cout << ans << endl;

		return 0;
	}