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

int binsearch(int low, int high, int b) {
	int mid, ans = 0;
	int f = low;

	int u = f * (f + 1) / 2;

	while(low <= high) {

		mid = (low + high) / 2;
		
		int v = mid * (mid + 1) / 2;
		int val = v - u;

		if(val <= b) {
			// cout << mid << " " << u << " " << v << " " << val << endl;
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	// cout << ans << endl;

	return ans;
}

vi a1, a2;

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

		// u = binsearch(0, 1000000, n);
		// v = binsearch(u + 1, 1000000, m);

		// cout << u << endl;
		// for(i = 1; i <= u; i++) cout << i << " "; cout << endl;
		// cout << v - u << endl;
		// for(i = u + 1; i <= v; i++) cout << i << " "; cout << endl;

		for(i = 1; i <= 1000000; i++) {

			if(n - i >= 0) {
				n -= i;
				a1.pb(i);
				continue;
			}
			else if(m - i >= 0) {
				m -= i;
				a2.pb(i);
				continue;
			}
			else if(m - i < 0) {
				if(n + a1[a1.size() - 1] - i >= 0 && ((m - a1[a1.size() - 1])) >= 0) {
					n = n + a1[a1.size() - 1] - i;
					m -= a1[a1.size() - 1];
					a2.pb(a1[a1.size() - 1]);
					a1[a1.size() - 1] = i;
				}
			}
 		}

 		cout << a1.size() << endl;
 		for(i = 0; i < a1.size(); i++) cout << a1[i] << " "; cout << endl;
 		cout << a2.size() << endl;
 		for(i = 0; i < a2.size(); i++) cout << a2[i] << " "; cout << endl;

		return 0;
	}