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

vector <item> vs;
vi ansv;
state dp[N][N]; // minspace reqd to install j apps out of first i

bool cmp(item a, item b) { return (a.s_sz - a.d_sz) < (b.s_sz - b.d_sz); }

void init() {
	for(int i = 0; i < N; i++)
		for(int j = 1; j < N; j++) dp[i][j].ans = INT_MAX;
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
		
		int n, phone_storage, i, j, u, v;
		int f_x, f_y = 0;

		init();

		cin >> n >> phone_storage;


		for(i = 1; i <= n; i++) {
			item p; p.idx = i; 
			cin >> p.d_sz >> p.s_sz; vs.pb(p);
		}

		sort(vs.begin(), vs.end(), cmp);

		// for(auto it : vs) cout << it.d_sz << " " << it.s_sz << endl;

		for(i = 1; i <= n; i++) {
				
			item cur = vs[i - 1];

			for(j = 1; j <= i; j++) {

				int install_space = dp[i - 1][j - 1].ans + cur.d_sz;

				if(install_space <= phone_storage) {
					dp[i][j].ans = dp[i - 1][j - 1].ans + cur.s_sz;
					dp[i][j].idx_bought = cur.idx;
					dp[i][j].par_x = i - 1;
					dp[i][j].par_y = j - 1;
				}	
				
				if(dp[i][j].ans > dp[i - 1][j].ans) {
					dp[i][j].ans = dp[i - 1][j].ans;
					dp[i][j].idx_bought = dp[i - 1][j].idx_bought;
					dp[i][j].par_x = i - 1;
					dp[i][j].par_y = j;
				} 
				
				if(dp[i][j].ans <= phone_storage && j > f_y)
					f_x = i, f_y = j, u = dp[i][j].ans;
			}
		}


		// for(i = 1; i <= n; i++) {
		// 	for(j = 0; j <= n; j++) cout << dp[i][j].ans << " "; cout << endl;
		// }

		// cout << u << " " << f_x << " " << f_y << endl;

		i = f_x, j = f_y;
		int lst = 0; 
		int new_i, new_j;

		while(j) {
			if(lst != dp[i][j].idx_bought) {
				ansv.pb(dp[i][j].idx_bought);
				lst = dp[i][j].idx_bought;
			}

			new_i = dp[i][j].par_x; new_j = dp[i][j].par_y;
			i = new_i, j = new_j;
		}

		reverse(ansv.begin(), ansv.end());
		cout << ansv.size() << endl;
		if(ansv.size() != 0) { for(auto it : ansv) cout << it << " "; cout << endl; }

		return 0;
	}