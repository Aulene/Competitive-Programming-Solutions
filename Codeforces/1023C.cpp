#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007];

int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, d = 1;
		string s, ans = "";
		stack < pair <int, int> > sq;
		pair <int, int> pz;

		cin >> n >> m >> s;

		for(i = 0; i < n; i++)
			{
				if(s[i] == '(') {
					sq.p(mp(1, i));
				}
				else {
					pz = sq.top();

					if(pz.f == 1) {
						if(!sq.empty())
							{
								sq.pop();
							
								if(m) {
									a[pz.s] = 1;
									a[i] = 1;
									m -= 2;
								}	
							}
					}

				}
			}

		for(i = 0; i < n; i++) 
			if(a[i]) 
				ans += s[i];

		cout << ans << endl;

		return 0;
	}