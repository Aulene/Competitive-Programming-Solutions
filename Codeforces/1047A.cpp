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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;

		if(n == 4) {
			cout << "2 1 1" << endl;
			return 0;
		}

		if(n % 3 == 0)
			{
				cout << n - 2 << " " << 1 << " " << 1 << endl;
			}
		else if(n % 3 == 1)
			{
				cout << n - 2 << " " << 1 << " " << 1 << endl;
			}
		else
			{
				cout << n - 3 << " 2 1" << endl;
			}
		return 0;
	}