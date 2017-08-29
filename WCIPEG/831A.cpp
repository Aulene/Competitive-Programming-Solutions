#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

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
		int i, j, n, prev, x;
		bool ans = 1;
		bool first = 1, second = 1, third = 1;

		cin >> n >> prev;

		for(i = 1; i < n; i++)
			{
				cin >> x;
				if(prev < x)
					{
						if(!first)
							ans = 0;
					}
				else if(prev == x)
					{
						first = 0;
						if(!second)
							ans = 0;
					}
				else if(prev > x)
					{
						second = 0;
						if(!third)
							ans = 0;
					}
			}

		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		return 0;
	}