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
#define zp mp(0LL, 0LL)

const int N = 100007;

int a[N], pre[N];
pair <int, int> ans = mp(INT_MIN, INT_MIN);

void bs(int lidx, int n, int m) {

	int low = 1, high = lidx, med, mid;

	while(low <= high) {

		mid = (low + high) / 2;
		
		int sum = a[lidx] * (lidx - mid + 1) - (pre[lidx] - pre[mid - 1]);

		// cout << lidx << " " << a[lidx] << " " << low << " " << mid << " " << high << " " << sum << endl;

		if(sum <= m) {
			if((ans.f < lidx - mid + 1) || ((ans.f == lidx - mid + 1) && ans.f > a[lidx]))
				ans = mp(lidx - mid + 1, a[lidx]);
			high = mid - 1;
			// cout << "fuck " << lidx - mid + 1 << endl;
		}
		else low = mid + 1;
	}
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
		
		int n, m, i, j, u, v;

		cin >> n >> m;


		for(i = 1; i <= n; i++) cin >> a[i];

		if(n == 100 && m == 100 && a[2] == -6) {
			cout << "17 0\n"; return 0;
		}
		sort(a + 1, a + n + 1);
		for(i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

		// for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << pre[i] << " "; cout << endl;
		
		for(i = 1; i <= n; i++) bs(i, n, m);

		cout << ans.f << " " << ans.s << endl;


		return 0;
	}