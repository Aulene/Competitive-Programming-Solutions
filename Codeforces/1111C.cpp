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

vi avs;
int A, B;

int getAvengers(int low, int high) {
	auto it1 = lower_bound(avs.begin(), avs.end(), high + 1);
	auto it2 = lower_bound(avs.begin(), avs.end(), low);
	int ans = it1 - it2;
	return ans;
}

int getBurn(int low, int high) {
	int low_p2 = low;
	int high_p2 = high;
	int num_avengers = getAvengers(low_p2, high_p2);

	if(low == high) {
		if(num_avengers == 0) return A;
		return B * num_avengers;
	}

	int cur_burn;

	if(num_avengers == 0) cur_burn = A;
	else cur_burn = B * num_avengers * (high_p2 - low_p2 + 1);

	int ans = cur_burn;

	int mid = (low + high) / 2;
	int ans1 = getBurn(low, mid);
	int ans2 = getBurn(mid + 1, high);
	
	ans = min(ans, ans1 + ans2);
	return ans;
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		int n, m, a, b, i, j, u, v, l, r, q;

		cin >> n >> m >> A >> B;

		for(i = 1; i <= m; i++) {
			cin >> u; avs.pb(u);
		}

		avs.pb(-1); avs.pb(LLONG_MAX);
		sort(avs.begin(), avs.end());

		int high_p2 = (1LL << n);
		int ans = getBurn(1LL, high_p2);
		cout << ans << endl;
		return 0;
	}