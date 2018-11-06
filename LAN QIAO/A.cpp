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

int game(int x, int y) {
	if((x == 1 && y == 2) || (x == 0 && y == 1) || (x == 2 && y == 1)) return 1;
	if(x != y) return -1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, i, j, u, v, w;
		int a = 0,b = 0, c = 0;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> u >> v >> w;
			if(game(u, v) == 1) {
				a++;
				b--;
			}
			else if(game(u, v) == -1) {
				a--, b++;
			}

			if(game(u, w) == 1) {
				a++;
				c--;
			}
			else if(game(u, w) == -1) {
				a--, c++;
			}

			if(game(v, w) == 1) {
				b++, c--;
			}
			else if(game(v, w) == -1) {
				b--, c++;
			}
		}	

		cout << a << endl << b << endl << c << endl;

		return 0;
	}