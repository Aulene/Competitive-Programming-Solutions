#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp ans2ke_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, k, u = 0, v = 1;

		cin >> n >> m;

		int minx = n - m * 2;
    	if(minx < 0) minx = 0;
    	k = (1 + sqrt(1 + 8 * m)) / 2;
    	if(((k - 1) * k) / 2 > m) k = k - 1;
    	if(((k - 1) * k) / 2 < m) k = k + 1;
    	if(k == 1) k = 0;

		cout << minx << " " << n - k << endl;

		return 0;
	}