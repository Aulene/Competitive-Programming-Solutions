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
#define zp mp(0, 0)

const int N = 100007;
int prime[N];
vvi divs(N);
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
		
		int n, m, i, j, k, u, v;

		cin >> n >> k;

		for(i = 2; i < N; i++) prime[i] = i;

		for(i = 2; i < N; i++) {
			if(prime[i] == i) {
				for(j = i * i; j < N; j += i) 
					if(prime[j] == j) prime[j] = i;
			}
		}

		// for(i = 2; i < N; i++) {
		// 	divs[i].pb(i);
		// 	for(j = 2 * i; j < N; j += i) divs[j].pb(i);
		// }

		while(true) {
			if(n == 1) break;
			vs.pb(prime[n]);
			n /= prime[n];
		}

		// if(divs[n].size() < k) cout << "-1" << endl;
		// else {
		// 	for(i = 0; i < divs[n].size(); i++)
		// 		cout << divs[n][i] << " "; cout << endl;

		// 	for(i = 0; i < k - 1; i++) cout << divs[n][i] << " ";
		// 	u = 1;
		// 	for(i = k; i < divs[n].size(); i++) u = u * divs[n][i];
		// 	cout << u << endl;

		// }
		
		if(vs.size() < k) cout << "-1" << endl;
		else {
			// for(i = 0; i < vs.size(); i++)
			// 	cout << vs[i] << " "; cout << endl;

			for(i = 0; i < k - 1; i++) cout << vs[i] << " ";
				
			u = 1;
			for(i = k - 1; i < vs.size(); i++) u = u * vs[i];
			cout << u << endl;

		}
		return 0;
	}