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

int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n;	

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < n - 1; i++) {
			if(a[i] % 2 || a[i + 1] % 2) {
				u = a[i] - a[i + 1];
				v = a[i] + a[i + 1];
				a[i] = u, a[i + 1] = v;
				ans++;
			}
		}

		cout << "YES" << endl << ans << endl;
		
		return 0;
	}