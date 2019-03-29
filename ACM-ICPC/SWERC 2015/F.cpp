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

const int N = 2507;
const int INF = INT_MAX;

vvi capacity(N, vi(N, 0));
vvi adj(N);
int n;

vi sml, lrg;

map < pi, int > mx;

int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
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
		
		int n, m, a, b, i, j, k, u, v, num = 1;
		char c;

		cin >> n >> m >> a >> b;

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				cin >> c;
				mx[{i, j}] = num++;
				if(c == '.') sml.pb(mx[{i, j}]);
				else lrg.pb(mx[{i, j}]);
			}
		}

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				for(k = 0; k < 4; k++)
					if(mx[{i + x[k], j + y[k]}] != 0) {
						adj[mx[{i, j}]].pb(mx[{i + x[k], j + y[k]}]);
						capacity[mx[{i, j}]][mx[{i + x[k], j + y[k]}]] = a;	
					}
			}
		}

		int src = num++;

		for(auto it : sml) {
			adj[src].pb(it); adj[it].pb(src);
			capacity[src][it] = capacity[it][src] = b;
		}

		int sink = num;
		for(auto it : lrg) {
			adj[sink].pb(it); adj[it].pb(sink);
			capacity[sink][it] = capacity[it][sink]= b;
		}

		::n = num + 1;

		cout << maxflow(src, sink) << endl;

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
