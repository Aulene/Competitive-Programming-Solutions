#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;
		int t;
		string s;

		cin >> s;
		n = s.size();
		s += "X";

		int p = 1;

		for(i = 1; i <= n; i++)
			{	
				if(s[i] != s[i - 1]) {
					cout << s[i-1] << p;
					p = 1;
				}
				else p++;
			}
			cout << endl;

		return 0;
	}