#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, d, n, i, j, k, swaps, ans, power, str, maxswaps;
		string s;

		cin >> t;

		for(int T = 1; T <= t; T++)
			{
				ans = -1;

				cin >> d >> s;
				n = s.size();

				maxswaps = n * (n - 1) / 2;

				for(swaps = 0; swaps <= maxswaps; swaps++)
					{
						str = 1, power = 0;
						bool swapped = 0;

						if(swaps)
							{
								for(i = n - 2; i >= 0; i--) {

									if(s[i] == 'C' && s[i + 1] == 'S') {
										s[i] = 'S';
										s[i + 1] = 'C';
										swapped = 1;
										break;
									}

								}

								if(!swapped) break;
							}

						for(i = 0; i < n; i++) {
								if(s[i] == 'S') power += str;
								else str = str * 2;
							}

						// cout << swaps << " " << power << endl;

						if(power <= d) {
							ans = swaps;
							break;
						}

					}

				if(ans != -1) cout << "Case #" << T << ": " << ans << endl;
				else cout << "Case #" << T << ": IMPOSSIBLE" << endl;
			}

		return 0;
	}