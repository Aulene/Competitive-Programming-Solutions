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

bool prime[1000007];
int pre[100007];
vector <int> vs;

int sieve(int b, int n)
{
	for(int i = 2; i < 1000007; i++) prime[i] = 1;
	for(int i = 2; i < 1000007; i++)
		for(int j = i * i; j < 1000007; j+=i) prime[j] = 0;
	for(int i = min(1000000 * 1LL, b * n); i >= 2; i--) 
		if(prime[i]) return i;
}

int hack(int N, int n, int b)
{
	for(int i = 1; i <= 100000; i++) pre[i] = pre[i - 1] + i;

	for(int i = 0; i <= b - n; i++)
		{
			int u = pre[n + i - 1] - pre[i];
			int v = N - u;

			if(v <= b && v > 0 && ((v > n + i - 1) || (v < i + 1)))
				{
					// cout << i << " " << N - u << endl;

					for(int j = 1; j < n; j++) vs.pb(i + j);
					vs.pb(N - u);
					break;
				}
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		int ans;
		bool ansx = 1;

		cin >> n >> m;

		u = sieve(m, n);
		
		cout << u << endl;

		hack(u, n, m);

		for(i = 0; i < vs.size(); i++) cout << vs[i] << " ";

		if(!vs.size()) cout << "impossible\n";
		else
			{
				for(i = 0; i < vs.size(); i++)
					{

					}
			}
		return 0;
	}