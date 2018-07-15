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

bool a[1007];
unordered_map <char, char> mx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j;
		string s, ans = "";
		char lowest, highest;

		cin >> n >> m >> s;

		for(i = 0; i < n; i++)
			a[s[i]] = 1;

		for(i = 'a'; i <= 'z'; i++)
			{
				bool x = 0;

				for(j = i + 1; j <= 'z'; j++)
					{
						if(a[(char) j]) 
							{
								mx[(char) i] = (char) j;
								x = 1;
								break;
							} 
					}

				if(!x)
					{
						for(j = 'a'; j < i; j++)
							if(a[(char) j]) 
								{
									mx[(char) i] = (char) j;
									x = 1;
									break;
								} 
					}
			}

		// for(i = 'a'; i <= 'z'; i++)
		// 	if(a[i]) cout << (char) i << " " << mx[i] << endl;

		for(i = 'a'; i <= 'z'; i++)
			if(a[i])
				{
					lowest = char(i);
					break;
				}

		for(i = 'z'; i >= 'a'; i--)
			if(a[i])
				{
					highest = char(i);
					break;
				}
		
		if(m > n)
			{
				ans = s;
				for(i = n; i < m; i++)
					ans += lowest;

			}
		else if(m == n)
			{
				for(i = n - 1; i >= 0; i--)
					if(mx[s[i]] > s[i])
						{
							j = i;
							break;
						}

				for(i = 0; i < j; i++) ans += s[i];
				for(i = j; i < n; i++) ans += mx[s[i]];
			}
		else if(m < n)
			{
				for(i = m - 1; i >= 0; i--)
					if(mx[s[i]] > s[i])
						{
							j = i;
							break;
						}

				for(i = 0; i < j; i++) ans += s[i];
				for(i = j; i < m; i++) ans += mx[s[i]];
			}

		cout << ans << endl;

		return 0;
	}