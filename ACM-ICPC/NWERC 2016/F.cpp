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

vi vs, vs2;

int check(int val) {
	vi v;

	for(int i = 0; i < vs.size(); i++) 
		if(vs[i] > val) v.pb(vs[i]);

	for(int i = 0; i < v.size(); i += 2) 
		if(v[i] != v[i + 1]) return 0;

	v.clear();

	for(int i = 0; i < vs2.size(); i++) 
		if(vs2[i] > val) v.pb(vs2[i]);

	for(int i = 0; i < v.size(); i += 2) 
		if(v[i] != v[i + 1]) return 0;

	return 1;
}

int bs() {

	if(check(0)) return 0;

	int low = 1, high = 1e9 + 1, mid, ans = high;

	while(low <= high) {
		mid = (low + high) / 2;
		// cout << mid << " " << check(mid) << endl;

		if(check(mid)) {
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n; i++) cin >> u, vs.pb(u);
		for(i = 0; i < n; i++) cin >> u, vs2.pb(u);

		cout << bs() << endl;

		return 0;
	}