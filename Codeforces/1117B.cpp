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
		
		int n, m, k, i, j, u, v;

		cin >> n >> m >> k;

		for(int i = 1; i <= n; i++) cin >> u, pq.p(u);
		int max1 = pq.top(); pq.pop();
		int max2 = pq.top(); pq.pop();

		int num_seq = floor((long double) m / (k + 1));
		int ans = num_seq * (k * max1 + max2);

		int num_left = m - (num_seq * (k + 1));
		ans += num_left * max1;

		cout << ans << endl;
		return 0;
	}