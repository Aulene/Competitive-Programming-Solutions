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
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

#define ld long double

const int N = 200007;
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
		
		int pre = 0, suf = 0, i, j, u, v, n;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		for(i = 1; i <= n && a[i] == 1; i++) pre++;
		for(i = n; i >= 1 && a[i] == 1; i--) suf++;

		int cur = 0, ans = pre + suf;

		for(i = 1; i <= n; i++) {
			if(a[i] == 0) cur = 0;
			else {
				cur++;
				ans = max(ans, cur);
			}
		}

		cout << ans << endl;

		return 0;
	}