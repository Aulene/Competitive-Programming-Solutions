#include <bits/stdc++.h>
#include <unordered_map>

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
#define vpi vector < pair <int, int> > 
#define mid (start + end) / 2
#define pi pair <int, int>
#define N 100007

vpi vs(100007);

int dp[5007][5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
        int n, m, i, j, u, v, w, h;

        cin >> n >> w >> h;

        for(i = 0; i < n; i++) {
            cin >> u >> v;
            vs.pb({u, v});
        }
		return 0;
	}