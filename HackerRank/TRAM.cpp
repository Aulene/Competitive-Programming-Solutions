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

vector <int> ans;

int check(int n)
{
	int sumfirst = 0, sumlast = 0;
	int x = 3;

	while(x)
		{
			sumlast += n % 10;
			n /= 10;
			x--;
		}

	x = 3;

	while(x)
		{
			sumfirst += n % 10;
			n /= 10;
			x--;
		}

	if(sumlast == sumfirst)
		return 1;
	return 0;
}

int generate()
{
	for(int i = 100000; i <= 999999; i++)
		if(check(i))
			ans.pb(i);
	return 0;
}
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		vector <int> :: iterator it;
		generate();

		int n, i, m;

		cin >> n;

		it = lower_bound(ans.begin(), ans.end(), n);
		if(*it == n)
			it++;
		cout << *it << endl;

		return 0;
	}