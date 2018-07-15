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


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, m;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				int x = 0;

				for(int j = 0; j < 5; j++)
					{
						cin >> m;
						if(m) x++;
					}

				if(x == 0) cout << "Beginner\n";
				else if(x == 1) cout << "Junior Developer\n";
				else if(x == 2) cout << "Middle Developer\n";
				else if(x == 3) cout << "Senior Developer\n";
				else if(x == 4) cout << "Hacker\n";
				else cout << "Jeff Dean\n";
			}
			
		return 0;
	}