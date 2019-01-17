#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1e18
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 407;
const int M = 250007;

int a[N];

vector < vector <int> > vs;
vi ord;

int check_truck(int start, int finish, int consume, int refuel, int tank) {

	int cur = tank, num_refuel = 0;

	for(int i = start; i < finish; i++) {

		int cost = a[i + 1] - a[i];
		cost *= consume;

		if(cost > cur) {
			if(cur < tank) {
				cur = tank;
				num_refuel++;
			} 
			else return 0;
		}

		if(cost > cur) return 0;
		cur -= cost;
	}

	if(num_refuel > refuel) return 0;
	return 1;
}

int check(int idx, int tank) {
	int s = vs[idx][0], f = vs[idx][1], r = vs[idx][2], c = vs[idx][3];
	return check_truck(s, f, r, c, tank);
}

void check_debug(int i, int tank) {
	int s = vs[i][0], f = vs[i][1], r = vs[i][2], c = vs[i][3];
	printf("check = %lld\n", check_truck(s, f, r, c, tank));
}

int solve(int idx, int cur) {

	int low = cur + 1, high = 1e18, mid, ans = high;

	while(low <= high) {

		mid = (low + high) / 2;

		if(check(idx, mid)) {
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
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= m; i++) {
			vector <int> vx(4);
			for(j = 0; j < 4; j++) cin >> vx[j];
			vs.pb(vx);
			ord.pb(i - 1);
		}
    
        shuffle(ord.begin(), ord.end(), rng);

        for(i = 0; i < m; i++) {
        	if(check(ord[i], ans)) continue;
        	ans = max(ans, solve(ord[i], ans));
        }

		cout << ans << endl;

		return 0;
	}