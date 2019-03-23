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

/*
	Easy mistakes to spot before submitting!
	1. Check const int N (1e5, 2e5).
	2. Check easy cases (n = 1, 2).
	3. Overflows! You'll fuck this up when binary searching.
	4. LONG LONGS! Alternatively, remove the int long long int sometimes.
	5. Check if you're dividing by 0 somewhere.
	6. Memory allocations, sometimes the vector is N^2.
*/

const int N = 500007;

char state[N];

int n; // number of vertices
vvi g(N); // adj list
vector <bool> visited(N);
vi topological_order;

void dfs(int v) {
    visited[v] = true;
    for(int u : g[v])
        if(!visited[u]) dfs(u);
    topological_order.pb(v);
}

void topological_sort() {
    visited.assign(n + 1, false);
    topological_order.clear();
    for(int i = 1; i <= n; i++)
        if(!visited[i]) dfs(i);
    reverse(topological_order.begin(), topological_order.end());
}

int balls[N];
char final_state[N];

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
		
		int m, i, j, u, v, l, r;
		char c;

		cin >> m >> n;

		for(i = 1; i <= n; i++) {
			cin >> c >> l >> r;
			g[i].pb(l); g[i].pb(r);
			state[i] = c;
		}

		topological_sort();

		balls[1] = m;

		for(auto it : topological_order) {

			if(it == 0) break;

			if(balls[it] % 2 == 1) {
				if(state[it] == 'R') final_state[it] = 'L';
				else final_state[it] = 'R';
			}
			else final_state[it] = state[it];

			int num_first = ceil((ld) balls[it] / 2.0);
			int num_second = floor((ld) balls[it] / 2.0);
			int fnode, snode;

			if(state[it] == 'R') {
				fnode = g[it][1];
				snode = g[it][0];
			}
			else {
				fnode = g[it][0];
				snode = g[it][1];
			}

			balls[fnode] += num_first;
			balls[snode] += num_second;
		}

		for(i = 1; i <= n; i++) cout << final_state[i]; cout << endl;

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
	9. Matrix Exponentiation - matrix
	10. Merge Sort Tree - mstree
	11. Modular Inverse - modinv
	12. Range Segment Tree (w/ Lazy) - segtree
	13. Range Segment Tree (w/out Lazy) - rstree
	14. Sieve of Eratosthenes - sieve
*/
