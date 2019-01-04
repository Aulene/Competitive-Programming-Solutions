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
#define zp mp(0, 0)

const int N = 200007;
const int M = 1000007;

int a[N], d[M];

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
		
		int n, m, k, i, j, u, v, ans = 0;
		priority_queue <int, vi, less <int> > pq;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++) 
			cin >> a[i], d[a[i]]++;

		int l = 1, r = 1, sum = 0;

		while(r <= m) {

			if(d[r]) {
				sum++;
				pq.p(r);
			}

			if(sum == k) {
				u = pq.top(); pq.pop();
				d[u]--; sum--; ans++;
			}

			r++;

			// cout << l << " " << r << " " << sum << " " << ans << endl;
		}

		while(r < M) {
			if(d[r]) {
				sum++;
				pq.p(r);
			}

			if(d[l]) sum--;

			if(sum == k) {
				u = pq.top(); pq.pop();
				d[u]--; sum--; ans++;
			}

			l++, r++;
			// cout << l << " " << r << " " << sum << " " << ans << endl;
		}


		cout << ans << endl;

		return 0;
	}