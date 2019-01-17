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
const int M = 207;

int a[N];
int h1[M], h2[M], fidx[M];

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
		
		string s1, s2;
		int n, m, i, j, u, v, ans;

		cin >> s1 >> s2;
		n = s1.size(), m = s2.size();

		for(i = 0; i < M; i++) fidx[i] = -1;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < m; i++) h2[s2[i]]++;

		int idx = 0;

		for(i = 0; i < n; i++) {
			if(s1[i] == s2[idx] && fidx[s1[i]] == -1) {
				fidx[s1[i]] = i;
				idx++;
			}
		}

		for(i = 0; i < n; i++) 
			if(i >= fidx[s1[i]]) h1[s1[i]]++;

		cout << ans << endl;
		return 0;
	}