#include <iostream>
#include <fstream>
#include <iomanip>
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

		string s1, s2;
		int n, m, i, j;
		double ans;
		int p1 = 0, p2 = 0, m1 = 0, m2 = 0, q = 0; 
		cin >> s1 >> s2;

		n = s1.size();

		for(i = 0; i < n; i++)
			{
				if(s1[i] == '+')
					p1++;
				else
					m1++;

				if(s2[i] == '+')
					p2++;
				else if(s2[i] == '-')
					m2++;
				else
					q++;
			}

		ans = max(p1, p2) - min(p1, p2) + max(m1, m2) - min(m1, m2);
		ans = pow(0.5000000000, ans);
		
		cout << setprecision(10) << ans << endl;
		return 0;
	}