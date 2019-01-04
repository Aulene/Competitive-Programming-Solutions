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
const int M = 100007;

int a[N], dp[N], c[N], nc[N];
vi sqs;
vpi cv, ncv;

bool cmp(pi a, pi b) 
{ return a.s < b.s; }

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
		
		int n, m, i, j, u, v, ans = 0, sq = 0, nsq = 0;

		for(i = 0; i <= M; i++) 
			sqs.pb(i * i);

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			u = *lower_bound(sqs.begin(), sqs.end(), a[i]);
			auto it = upper_bound(sqs.begin(), sqs.end(), a[i]);
			it--;
			v = *it;

			c[i] = min(abs(u - a[i]), abs(v - a[i]));
			
			if(c[i] == 0) {
				if(a[i] == 0) nc[i] = 2;
				else nc[i] = 1;
				sq++;
				cv.pb({i, nc[i]});
			} 
			else {
				nsq++;
				ncv.pb({i, c[i]});
			}
		}

		sort(cv.begin(), cv.end(), cmp);
		sort(ncv.begin(), ncv.end(), cmp);

		// cout << sq << " " << nsq << endl;

		if(sq > nsq) {
			u = (sq - nsq) / 2;
			int idx = 0;

			while(u) {
				ans += cv[idx].s;
				idx++;
				u--;
			}
		}
		else {
			u = (nsq - sq) / 2;
			int idx = 0;

			while(u) {
				ans += ncv[idx].s;
				idx++;
				u--;
			}
		}

		cout << ans << endl;

		return 0;
	}