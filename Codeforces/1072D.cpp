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

int a[N][N];


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
		string s;

		cin >> n >> m;

		for(i = 0; i < n; i++) {
			cin >> s;

			for(j = 0; j < n; j++)
				a[i][j] = (int) s[j] - 'a';
		}

		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) cout << a[i][j] << " "; cout << endl;
		}


		return 0;
	}