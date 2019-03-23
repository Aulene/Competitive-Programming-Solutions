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

int a[N], pre[N];
int sum;
int n;

int compute(int its, int h) {

	int fuck = its * sum;
	h = h + fuck;
	for(int i = 0; i <= n; i++) 
		if(h + pre[i] <= 0) return its * n + i; 

	return -1;
}

int bs(int h) {

	int max_its = h / abs(sum);

	int low = 1, high = max_its, mid, ans = 1e12;

	while(low <= high) {
		
		mid = (low + high) / 2;

		int num_its = compute(mid, h);

		// cout << mid << " " << num_its << endl;

		if(num_its != -1) {
			ans = num_its;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int m, h, i, j, u, v;
		
		cin >> h >> n;

		int cur = h;

		for(i = 1; i <= n; i++) {
			cin >> a[i], sum += a[i], pre[i] = sum;

			cur += a[i];
			if(cur <= 0) {
				cout << i << endl;
				return 0;
			}
		}

		if(sum >= 0) {
			cout << -1 << endl;
			return 0;
		}

		cout << bs(h) << endl;
		return 0;
	}