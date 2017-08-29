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

map <char, char> m;

bool isupper(char a)
{
	if(a >= 'A' && a <= 'Z')
		return 1;
	return 0;
}

signed main()
	{
		string s1, s2;
		string s, ans = "";
		int i, j, n, x;

		cin >> s1 >> s2 >> s;
		n = s1.size();

		for(i = 0; i < n; i++)
			m[s1[i]] = s2[i];

		x = s.size();

		for(i = 0; i < x; i++)
			{
				if(isupper(s[i]))
					{
						char f = s[i] + 32;
						f = m[f];
						f = f - 32;
						ans += char(f);
					}
				else if(s[i] >= 'a' && s[i] <= 'z') 
					{
						ans += m[s[i]];
					}
				else
					ans += s[i];
			}

		cout << ans << endl;
		return 0;
	}