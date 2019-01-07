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

const int N = 200007;
const int M = 31;

struct node {
	int cnt = 0;
	node *ns[2] = {NULL};
};

node *trie = new node;

void insert(int n) {
	node *cur = trie;
	cur -> cnt++;

	for(int i = M; i >= 0; i--) {
		int u = n & (1 << i);
		u = (u > 0) ? 1 : 0;
		if(cur -> ns[u] == NULL) 
			cur -> ns[u] = new node;

		cur = cur -> ns[u];
		cur -> cnt++;
	}
}

void del(int n) {
	node *cur = trie;
	cur -> cnt--;

	for(int i = M; i >= 0; i--) {
		int u = n & (1 << i);
		u = (u > 0) ? 1 : 0;
		cur = cur -> ns[u];
		cur -> cnt--;
	}
}

int query(int n) {
	node *cur = trie;
	int ans = 0;

	for(int i = M; i >= 0; i--) {
		int u = n & (1 << i);
		u = (u > 0) ? 0 : 1;

		if(cur -> ns[u] != NULL && cur -> ns[u] -> cnt > 0) {
			cur = cur -> ns[u];
			ans = ans | (1 << i);
		}
		else cur = cur -> ns[!u];
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
		char x;

		insert(0);
		
		cin >> m;

		while(m--) {
			cin >> x >> n;

			if(x == '+') insert(n);
			else if(x == '-') del(n);
			else cout << query(n) << endl;
		}	
		return 0;
	}