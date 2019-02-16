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
int a[N];

priority_queue < int, vi > pq;
map <int, int> mx;
vi vs;

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
		
		int n, m, k, i, j, u, v, sum = 0;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++) cin >> a[i], pq.p(a[i]);
		u = m * k;

		while(u--) {
			// cout << pq.top() << " ";
			sum += pq.top(); 
			mx[pq.top()]++; pq.pop();
		}
		// cout << endl;
		
		int num = m;

		for(i = 1; i <= n; i++) {
			if(mx[a[i]]) {
				mx[a[i]]--;
				num--;

				if(num == 0) {
					num = m;
					vs.pb(i);
				}
			}
		}

		cout << sum << endl;
		for(i = 0; i < ((int) vs.size() - 1); i++) cout << vs[i] << " "; cout << endl;
		return 0;
	}