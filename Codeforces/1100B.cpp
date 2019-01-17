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

const int N = 1e5 + 7;

int a[N], cnt[N], need[N];

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
		
		int m, n, i, j, u, v;

		cin >> m >> n;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i < N; i++) need[i] = m;

		for(i = 1; i <= n; i++) {
			cnt[a[i]]++;
			need[cnt[a[i]]]--;
			if(need[cnt[a[i]]] == 0) cout << 1;
			else cout << 0;
		}

		return 0;
	}