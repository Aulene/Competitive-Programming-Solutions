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

int gcd(int a, int b)
{
	if(a == 0)
		return b;
	return gcd(b % a, a);
}	

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int a, b;

		cin >> a >> b;
		
		int lol = gcd(a, b);

		if(a == 1)
			cout << b << endl;
		// else if(lol == 1)
		// 	cout << min(a, b) << endl;
		else
			cout << (min(a, b)) / lol << endl;
		return 0;
	}