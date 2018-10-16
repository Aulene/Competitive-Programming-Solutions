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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, u, v, i;
		stack <int> sx;
		sx.p(0);

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> v;
			if(v == 1) { cin >> u; sx.p(max(u, sx.top())); }
			else if(v == 2) sx.pop();
			else cout << sx.top() << endl;
		}
		
		return 0;
	}