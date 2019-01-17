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

const int N = 107;
int a[N], b[N], ax[7], bx[7], cnt[7];

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
		
		int n, m, i, j, u, v, ansx = 1, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i], ax[a[i]]++;
		for(i = 1; i <= n; i++) cin >> b[i], bx[b[i]]++;
		
		// for(i = 1; i <= 5; i++)
		// 	cout << ax[i] + bx[i] << " "; cout << endl;

		for(i = 1; i <= 5; i++)
			if((ax[i] + bx[i]) % 2 == 1) ansx = 0;
			else cnt[i] = (ax[i] + bx[i]) / 2;

		if(!ansx) {
			cout << -1 << endl;
			return 0;
		}

		// for(i = 1; i <= 5; i++) cout << cnt[i] << " "; cout << endl;

		for(i = 1; i <= 5; i++)
			ans += abs(cnt[i] - ax[i]);

		cout << ans / 2 << endl;
		return 0;
	}