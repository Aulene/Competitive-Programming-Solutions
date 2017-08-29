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

int av[100007], av1[100007];

signed main()
{
	int n, prev = 0, t, ans = 1, m, i, u, initial;

	cin >> n >> m >> initial;

	av1[1] = 0, av[1] = 1, av[0] = 0;

	for(i = 2; i <= 100002; i++)
		{
			ans = ((n - 1) * ans) % mod;
			//cout << ans << " " << prev << endl;
			prev = (ans - prev + mod) % mod;
			av1[i] = prev;
		}
	
	prev = 0;

	for(i = 2; i <= 100002; i++)
		{
			av[i] = (av[i - 1] + ((n - 1) * av[i - 2]) % mod) % mod;
		}

	// for(i = 1; i <= 10; i++)
	// 	cout << av[i] << " ";
	// cout << endl;

	while(m--)
		{
			cin >> t >> u;

			if(n > 2)
				{
					if(u == initial)
						cout << av1[t] << endl;
					else
						cout << av[t] << endl;
				}
			else if(n == 2)
				{
					if(t % 2 == 1)
						{
							if(u == initial)
								cout << "0" << endl;
							else
								cout << "1" << endl;
						}
					else
						{
							if(u == initial)
								cout << "1" << endl;
							else
								cout << "0" << endl;
						}
				}
			else
				cout << "0" << endl;
		}
	return 0;
}