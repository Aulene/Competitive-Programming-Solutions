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

const int N = 50007;

int a[N];

multiset <int> mx;
priority_queue <int, vi, less <int> > pq;

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

		for(i = 1; i <= n; i++) cin >> a[i], mx.insert(a[i]), pq.push(a[i]);

		while(true) {
			u = pq.top(); pq.pop();
			v = u;

			while(v) {
				if(mx.count(v) == 0) break;
				v = v / 2;
			}

			if(v == 0) break;

			// cout << u << " " << v << endl;

			mx.erase(u);
			mx.insert(v);
			pq.push(v);
		}

		for(auto it : mx) cout << it << " "; cout << endl;
		return 0;
	}