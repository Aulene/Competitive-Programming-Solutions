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

const int N = 100007;
int x_change[N], y_change[N];
int x_tot_change, y_tot_change;
int req_x, req_y;
int n;

// int req_x_bec_sea(int days) {

// 	int tot_cycles = floor((long double) days / n);
// 	int left_days = days - tot_cycles * n;
// 	int ans = req_x + tot_cycles * x_tot_change + x_change[left_days];
// 	return ans;
// }

// int req_y_bec_sea(int days) {
// 	int tot_cycles = floor((long double) days / n);
// 	int left_days = days - tot_cycles * n;
// 	int ans = req_y + tot_cycles * y_tot_change + y_change[left_days];
// 	return ans;
// }

// int check(int days) {
// 	int new_req_x = req_x_bec_sea(days);
// 	int new_req_y = req_y_bec_sea(days);

// 	// cout << new_req_x << " " << new_req_y << endl;
	
// 	int pos_req = new_req_x + new_req_y;
// 	if(pos_req <= days) return 1;
// 	return 0;
// }

int req_x_after_cycles(int given_x, int cycles) {
	return given_x + cycles * x_tot_change;
}

int req_y_after_cycles(int given_y, int cycles) {
	return given_y + cycles * y_tot_change;
}

// int check(int cur_x, int cur_y, int cycles, int days) {
// 	int new_req_x = req_x_after_cycles(cur_x, cycles);
// 	int new_req_y = req_y_after_cycles(cur_y, cycles);
	
// 	printf("pos after cycles: x: %lld, y: %lld\n", new_req_x, new_req_y);

// 	int pos_req = new_req_x + new_req_y;
// 	if(pos_req <= days) return 1;
// 	return 0;
// }

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int find_min_cycles(int cur_x, int cur_y) {
	int ans = -1;

	int x1 = 0, y1 = 0;

	printf("received x: %lld, y: %lld\n", cur_x, cur_y);

	if(x_tot_change != 0) x1 = cur_x / x_tot_change;
	if(y_tot_change != 0) y1 = cur_y / y_tot_change;
	
	if(x1 == 0 && y1 == 0) {
		int c1 = x1;
		int c2 = y1;
		ans = c1 * c2;
		ans = ans / gcd(c1, c2);
	}

	return ans;
}



int compute(int n) {
	int ans = -1, fans;

	for(int i = 0; i <= n; i++) {
		int cur_req_x = req_x + x_change[i];
		int cur_req_y = req_y + y_change[i];

		printf("this i: %lld, x: %lld, y: %lld\n", i, cur_req_x, cur_req_y);

		// fans = bsearch(cur_req_x, cur_req_y, i);
		// if(fans != -1) ans = fans;
		
		fans = find_min_cycles(cur_req_x, cur_req_y);

		if(fans != -1) {
			if(ans != -1) ans = fans;
			else ans = min(ans, fans);
		}
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
		
		int i_x, i_y, f_x, f_y, t, i, j, u, v;
		string s;

		cin >> i_x >> i_y >> f_x >> f_y;
		cin >> n >> s;

		req_x = f_x - i_x;
		req_y = f_y - i_y;

		for(i = 1; i <= n; i++) {
			if(s[i - 1] == 'U') x_change[i] = x_change[i - 1], y_change[i] = y_change[i - 1] + 1;	
			else if(s[i - 1] == 'D') x_change[i] = x_change[i - 1], y_change[i] = y_change[i - 1] - 1;
			else if(s[i - 1] == 'R') x_change[i] = x_change[i - 1] + 1, y_change[i] = y_change[i - 1];
			else x_change[i] = x_change[i - 1] - 1, y_change[i] = y_change[i - 1];			
		}

		x_tot_change = x_change[n]; y_tot_change = y_change[n];

		cout << compute(n) << endl;

		return 0;
	}