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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[500007], b[500007];

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

		int n, i, j, sum, ans;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < n; i++)
			cin >> b[i];
		
		sort(a, a + n), sort(b, b + n);

		for(i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		for(i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				{
					cout << "OPEN" << endl;
					cout << a[i] << " " << a[j] << endl;
					cout << "GCD = " << gcd(a[i], a[j]) << " SUM = " << a[i] + a[j] << endl;
					cout << "CLOSE" << endl;
				}
		return 0;
	}