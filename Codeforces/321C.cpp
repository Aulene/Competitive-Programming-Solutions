#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

const int N = 1e5 + 7;

vector<int> tree[N];
vector<int> cent[N]; // centroid tree
bool centroidMarked[N];
int subtree_size[N];

void dfs(int u, int p) {
	subtree_size[u] = 1;
	for(auto v : tree[u]){
		if(v != p && !centroidMarked[v]){
			dfs(v, u);
			subtree_size[u] += subtree_size[v];
		}
	}
}

int getCentroid(int u, int p, int n){
	bool is_centroid = true;
	int heaviest_child = -1;

	for(auto v : tree[u]){
		if(v != p && !centroidMarked[v]){
			if(subtree_size[v] > n / 2)
				is_centroid = false;
			if(heaviest_child == -1 || subtree_size[v] > subtree_size[heaviest_child])
				heaviest_child = v;
		}
	}
	if(is_centroid && n - subtree_size[u] <= n / 2){
		return u;
	}
	return getCentroid(heaviest_child, u, n);
}

int getCentroid(int u){
	dfs(u, -1);
	int centroid = getCentroid(u, -1, subtree_size[u]);
	centroidMarked[centroid] = true;
	return centroid;
}

int centroidDecomp(int root){
	int centroid = getCentroid(root);
	for(auto v : tree[centroid]){
		if(!centroidMarked[v]){
			int centroidsub = centroidDecomp(v);
			cent[centroid].pb(centroidsub);
			cent[centroidsub].pb(centroid);
		}
	}
	return centroid;
}

void addEdge(int a, int b) {
	tree[a].pb(b);
	tree[b].pb(a);
}

/*
	// in main

	int root = centroidDecomp(1);
	for(auto x : cent[c]){
		cout << x << endl;
	}
*/

int ans[N];

void build_ans(int idx, int p = -1, int depth = 0) {
	ans[idx] = depth;
	for(auto it : cent[idx])
		if(it != p) build_ans(it, idx, depth + 1);
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

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			addEdge(u, v);
		}

		int root = centroidDecomp(1);
		build_ans(root);

		for(i = 1; i <= n; i++) cout << (char) ('A' + ans[i]) << " "; cout << endl;

		return 0;
	}