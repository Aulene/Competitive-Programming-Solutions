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
const int M = 40;

int a[N];

struct node {
	int cnt = 0;
	node *ns[2] = {NULL};
};

node *trie = new node;

void insert(int n) {
	node *rt = trie;
	rt -> cnt++;

	for(int i = M; i >= 0; i--) {
		int u = n & (1LL << i);
		u = (u > 0) ? 1 : 0;

		if(rt -> ns[u] == NULL) 
			rt -> ns[u] = new node;
		
		rt = rt -> ns[u];
		rt -> cnt++;
	}
}

int query(int n) {
	node *rt = trie;
	rt -> cnt++;

	int ans = 0LL;

	for(int i = M; i >= 0; i--) {
	
		int u = n & (1LL << i);
		u = (u > 0) ? 0 : 1;

		if(rt -> ns[u] != NULL && rt -> ns[u] -> cnt > 0) {
			rt = rt -> ns[u];
			ans = ans | (1LL << i);
		}
		else rt = rt -> ns[!u];
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
		
		int n, i, j, u = 0, v = 0, ans = 0;

		insert(0LL);

		cin >> n;

		for(i = 1; i <= n; i++) 
			cin >> a[i], u = u ^ a[i];

		for(i = n + 1; i >= 0; i--) {
			ans = max(ans, query(u));
			u = u ^ a[i];
			v = v ^ a[i];
			insert(v);
		}
		
		cout << ans << endl;
		return 0;
	}