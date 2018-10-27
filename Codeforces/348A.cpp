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

int a[100007];

int check(int x, int n) {
	int sum = (n - 1) * x;
	for(int i = 1; i <= n; i++) sum -= a[i];
	// cout << x << " " << sum << endl;
	if(sum >= 0) return 1;
	return 0;
}

int bsearch(int low, int high, int n) {
	int ans = 0;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(check(mid, n)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}

	return ans;
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
		
		int n, m, i, j, u, v, sum = 0, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		ans = bsearch(a[n], INT_MAX, n);
		cout << ans << endl;
		return 0;
	}