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

const int N = 2007;

int good[2007], bad[2007];
int goodpre[N], badpre[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;
		bool ansx = 1;
		string s;

		cin >> n;

		// if(n % 2 == 1) {
		// 	cout << "No\n";
		// 	return 0;
		// }

		for(i = 0; i < n; i++) {
			cin >> s;

			for(j = 0; j < n; j++) {
				if(s[j] == '(') good[j]++;
				else bad[j]++;
			}
		}

		goodpre[0] = good[0];
		for(i = 1; i < n; i++) 
			goodpre[i] = goodpre[i - 1] + good[i];
		badpre[n - 1] = bad[n - 1];
		for(i = n - 1; i >= 0; i--)
			badpre[i] = badpre[i + 1] + bad[i];

		int x = 0, y = n - 1;

		for(i = 0; i < n; i++) cout << goodpre[i] << " "; cout << endl;
		for(i = 0; i < n; i++) cout << badpre[i] << " "; cout << endl;
		
		while(x < y) {
			if(goodpre[x] != badpre[y]) ansx = 0;
			x++, y--;
		} 

		// if(good[0] != n || bad[n - 1] != n) ansx = 0;
		// for(i = 1; i < n - 1; i++) 
		// 	if(good[i] != bad[i]) ansx = 0;

		if(ansx) cout << "Yes\n";
		else cout << "No\n";

		return 0;
	}