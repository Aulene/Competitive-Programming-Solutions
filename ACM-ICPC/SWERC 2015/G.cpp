#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ld long double
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
	Easy mistakes to spot before submitting!
	1. Check const int N (1e5, 2e5).
	2. Check easy cases (n = 1, 2).
	3. Overflows! You'll fuck this up when binary searching.
	4. LONG LONGS! Alternatively, remove the int long long int sometimes.
	5. Check if you're dividing by 0 somewhere.
	6. Memory allocations, sometimes the vector is N^2.
*/

const int N = 107;
const int M = 1007;

int n, m;
int a[N][M], sz[N];

vi find_nums(int i, int j) {
	vi nums;
	int cur_num;

	for(int k = 0; k <= m; k++) {
		cur_num = j - k;
		if(cur_num < 1) break;
		cur_num -= a[i][cur_num];
		if(cur_num < 0) continue;
		nums.pb(cur_num);
	}

	return nums;
}

int solve() {
	int ans = 0;
	int game_nums[M];

	for(int i = 0; i < M; i++) game_nums[i] = 0;

	vi grundy_nums, new_nums;

	for(int i = 1; i <= n; i++) {
		game_nums[0] = 0;
		for(int j = 1; j <= sz[i]; j++) {
			grundy_nums = find_nums(i, j);
			game_nums[j] = 0;
			new_nums.clear();
			
			// for(auto it : grundy_nums) cout << it << " "; cout << endl;
			
			for(auto it : grundy_nums)
				new_nums.pb(game_nums[it]);
			sort(new_nums.begin(), new_nums.end());

			// for(auto it : new_nums);
				
			for(auto it : new_nums) {
				if(it > game_nums[j]) break;
				if(it == game_nums[j]) game_nums[j]++;
			}
		}
		ans ^= game_nums[sz[i]];
	}

	return ans != 0;
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
		
		int i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++)  {
			cin >> sz[i];
			for(j = 1; j <= sz[i]; j++) cin >> a[i][j];
		}

		if(solve()) cout << "Alice can win." << endl;
		else cout << "Bob will win." << endl;
		return 0;
	}

/*
	Snippet Guide - 
	1. Base Conversion - baseconv
	2. Binary Exponentiation (a ^ b % m) - powmod 
	3. Centroid Decomposition - centroid
	4. Code Jam Input - jam
	5. Disjoint Set Union - dsu
	6. Factorial Method - factorials
	7. Factorization O(SqrtN) - factors
	8. Greatest Common Divisor - gcd
	9. Line Template - line
	10. Matrix Exponentiation - matrix
	11. Merge Sort Tree - mstree
	12. Modular Inverse - modinv
	13. Point Template - point
	14. Range Segment Tree (w/ Lazy) - segtree
	15. Range Segment Tree (w/out Lazy) - rstree
	16. Sieve of Eratosthenes - sieve
	17. Topological Sort - toposort
*/
