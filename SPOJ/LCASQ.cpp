#include <bits/stdc++.h>
#include <unordered_map>

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
#define mid (start + end) / 2
#define pi pair <int, int>

const int N = 10007;

vector < pair <int, int> > vs;
int firstapp[N];
vvi g(N);

struct node {

    pi val; // (node, depth)
    node *l, *r;

    pi merge(pi a, pi b) {
        if(a.s < b.s) return a;
        return b;
    }

    node *build(int start, int end) {

        if(start == end)
            val = vs[start];
        else {
            l = new node, r = new node;
            l = l -> build(start, mid), r = r -> build(mid + 1, end);
            val = merge(l -> val, r -> val);
        }
        return this;
    }

    pair <int, int> query(int start, int end, int a, int b) {
        if(start > b || end < a) return mp(INT_MAX, INT_MAX);
        else if(start >= a && end <= b) return val;
        else return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
    }

};

void dfs(int idx, int depth = 1) {
    vs.pb({idx, depth});
    if(firstapp[idx] == -1) firstapp[idx] = vs.size() - 1;

    for(auto it : g[idx]) {
        dfs(it, depth + 1);
        vs.pb({idx, depth});
    }
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
		
		int t, n, m, i, j, u, v, x, q;

        for(i = 0; i < N; i++) firstapp[i] = -1;

        cin >> n;

        for(i = 0; i < n; i++) {
            cin >> u;
            while(u--) {
                cin >> v;
                g[i].pb(v);
            }
        }

        dfs(0);

        node *root = new node;
        root = root -> build(0, vs.size() - 1);

        // for(auto it : vs) cout << it.f << " "; cout << endl;
        // for(auto it : vs) cout << it.s << " "; cout << endl;
        // for(i = 1; i <= n; i++) cout << firstapp[i] << " "; cout << endl;
        
        cin >> m;

        while(m--) {
            cin >> u >> v;
            int x = firstapp[u], y = firstapp[v];
            if(x > y) swap(x, y);

            printf("%lld\n", root -> query(0, vs.size() - 1, x, y).f);
            // cout << root -> query(0, vs.size() - 1, x, y).f << endl;
        }
        
		return 0;
	}