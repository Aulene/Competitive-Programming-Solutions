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

int a[N];

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
		int lt, rt;

		// a[1] = 1;
		// for(i = 2; i < N; i++) a[i] = a[i - 1] + i;

		while(cin >> n) {
			if(n == -1) break;

			for(i = sqrt(2 * n); i >= 1; i--) {
				int num = (2 * n) - (i * i) + i;
				int denom = 2 * i;

				if(num % denom == 0) {
					lt = num / denom;
					rt = i;
					break;
				}
			}

			printf("%lld = %lld + ... + %lld\n", n, lt, lt + rt - 1);
		}
		return 0;
	}