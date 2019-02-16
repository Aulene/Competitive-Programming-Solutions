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

vi factors(int n) {
	vi fax;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0) {
			if(i == sqrt(n)) fax.pb(i);
			else fax.pb(i), fax.pb(n / i);
		}
	fax.pb(n);
	sort(fax.begin(), fax.end());
	return fax;
}

vi fx;

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
		
		int n, m, i, j, u, v, b;
		int mval = LLONG_MAX;

		cin >> n >> b;
		
		fx = factors(b);

		int fuckN = n;

		// for(auto it : fx) cout << it << " "; cout << endl;

		for(auto i : fx) {

			if(b % i != 0) continue;

			int cnt = 0;

			while(b % i == 0) {
				cnt++;
				b /= i;
			}

			int pz = i, sum = 0;

			// while(pz <= fuckN) {
			// 	sum += (fuckN / pz);
			// 	pz *= i;
			// }

			while(pz <= n) {
				sum += n / pz;
				if (pz > n / i)
					break;
				pz *= i;
			}

			// cout << i << " " << sum << " " << cnt << endl;

			sum = ((long double) sum / cnt);
			mval = min(mval, sum);
		}

		cout << mval << endl;

		return 0;
	}