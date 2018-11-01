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

const int N = 4007;
int a[N], pre[N], ps[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans = 0;
		string s;

		cin >> m >> s;
		n = s.size();

		for(i = 1; i <= n; i++) a[i] = (int) s[i - 1] - '0';
		for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

		for(i = 1; i <= n; i++) {

			for(j = 1; j <= n; j++) ps[j] = a[i] * a[j];
			for(j = 1; j <= n; j++) pre[j] = pre[j - 1] + ps[j];

			for(j = 1; j <= n; j++) cout << ps[j] << " "; cout << endl;

			int l = 1, r = 1, sum = 0;

			while(r <= n || sum > m) {

				cout << l << " " << r << " " << sum << endl;

				while(sum > m) {
					sum -= ps[l];
					l++;
				}

				while(sum <= m && r <= n) {
					sum += ps[r];
					r++;

					if(sum == m) ans++;
				}

				// if(sum == m) {
				// 	cout << l << " " << r << endl;
				// 	ans++;
				// }
			}
		}

		ans = ans * 2;

		cout << ans << endl;

		return 0;
	}