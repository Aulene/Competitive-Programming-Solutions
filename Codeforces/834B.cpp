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

map <int, char> charForThis;
map <char, int> lastForChar;
map <int, bool> openForThisChar;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, open = 0;
		bool ans = 1;
		string s;

		cin >> n >> m >> s;

		for(i = 0; i < n; i++)
			{
				lastForChar[s[i]] = i;
				charForThis[i] = s[i];
			}

		for(i = 0; i < n; i++)
			{
				if(openForThisChar[s[i]])
					{
						if(lastForChar[s[i]] == i)
							{
								openForThisChar[i] = 0;
								open--;
							}
					}
				else
					{
						if(open == m)
							ans = 0;
						else
							{
								open++;
								openForThisChar[s[i]] = 1;
								
								if(lastForChar[s[i]] == i)
									{
										openForThisChar[i] = 0;
										open--;
									}
							}
					}
			}

		if(ans) cout << "NO" << endl;
		else cout << "YES" << endl;
		return 0;
	}