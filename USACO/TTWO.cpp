/*
ID: aussyle1
PROG: concom
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

pair < pair <int, int>, int> c, f;
map < pair < pair <int, int>, int>, int > vis;
int a[17][17];

void moveForward(pair < pair <int, int>, int > &x)
{
	if(x.s == 0)
		{
			if(a[x.f.f - 1][x.f.s]) x.f.f--;
			else x.s = (x.s + 1) % 4;
		}
	else if(x.s == 1)
		{
			if(a[x.f.f][x.f.s + 1]) x.f.s++;
			else x.s = (x.s + 1) % 4;
		}
	else if(x.s == 2)
		{
			if(a[x.f.f + 1][x.f.s]) x.f.f++;
			else x.s = (x.s + 1) % 4;
		}
	else if(x.s == 3)
		{
			if(a[x.f.f][x.f.s - 1]) x.f.s--;
			else x.s = (x.s + 1) % 4;
		}
}

int solve()
{
	int ans = 0;

	while(c.f != f.f)
		{
			if(vis[c] && vis[f]) 
				return 0;
			
			a[f.f.f][f.f.s] = 1;
			a[c.f.f][c.f.s] = 1;

			vis[c] = 1;
			vis[f] = 1;

			moveForward(c);
			moveForward(f);

			a[f.f.f][f.f.s] = 3;
			a[c.f.f][c.f.s] = 2;

			cout << ans << endl;
			cout << f.f.f << " " << f.f.s << " " << f.s << endl;
			cout << c.f.f << " " << c.f.s << " " << c.s << endl;
			cout << endl;

			for(int i = 1; i <= 10; i++) { 
					for(int j = 1; j <= 10; j++) 
						if(a[i][j] == 0) cout << "*";
						else if(a[i][j] == 2) cout << "C";
						else if(a[i][j] == 3) cout << "F";
						else cout << ".";
					cout << endl; 
				}

			ans++;
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		// ifstream cin ("concom.in");
		// ofstream cout ("concom.out");

		string s;
		int n, i, j, u, v;
		char x;

		for(i = 1; i <= 10; i++)
			{
				for(j = 1; j <= 10; j++) {
					cin >> x;
					if(x == 'F') f = mp(mp(i, j), 0), a[i][j] = 3;
					else if (x == 'C') c = mp(mp(i, j), 0), a[i][j] = 2;
					else if (x == '*') a[i][j] = 0;
					else a[i][j] = 1;
				}
 			}

 		cout << endl;

 		solve();

 		cout << solve() << endl;

		return 0;
	}