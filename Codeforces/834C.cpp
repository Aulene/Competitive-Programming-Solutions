#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a, b;
bool prime[1000007];
vector <int> primes;

void sieve()
{
	for(int i = 2; i < 100001; i++)
		prime[i] = 0;

    for(int i = 2; i < 100001; i++)
        if(!prime[i])
            {
                primes.pb(i);
                for(int j = 1LL * i * i; j < 100001; j += i)
                    prime[j] = i;
            }
}

signed main()
	{
		sieve();

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, u, v, x, y;
		
		cin >> t;

		while(t--)
			{
				cin >> a >> b;
				bool ans = 1;
				bool lol;

				for(i = 0; i < primes.size(); i++)
					{
						lol = 1;
						x = y = 0;

						while(a % primes[i] == 0)
							{
								a /= primes[i];
								x++;
							}

						while(b % primes[i] == 0)
							{
								b /= primes[i];
								y++;
							}

						if(2 * x >= y && 2 * y >= x && (2 * x - y) % 3 == 0 && (2 * y - x) % 3 == 0) 
							lol = 0;

						if(lol)
							{
								ans = 0;
								break;
							}
					}

					

				if(ans) cout << "Yes" << endl;
				else cout << "No" << endl;
			}

		return 0;
	}