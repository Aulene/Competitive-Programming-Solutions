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

int sieve()
{
	for(int i = 2; i <= 1000000; i++) prime[i] = 1;
	for(int i = 2; i <= 1000000; i++)
		if(prime[i])
			for(int j = i * i; j <= 1000000; j += i) prime[j] = 0;
	return 0;
}

bool pc(int n)
{
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0) return 0;
	return 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		// sieve();
		int i;
		for(i = 100000;; i++)
			{
				// cout << i << endl;
				bool c = 1;
				for(int j = 1; j <= 20; j++)
					if(i % j)
						{
							c = 0; break;
						}
				if(c) {break;}
			}

		cout << i << endl;
		return 0;
	}