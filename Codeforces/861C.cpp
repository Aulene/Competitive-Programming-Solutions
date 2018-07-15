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

int vs[3007];

bool isvowel(char x)
{
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j, u, v, maxc = 0, prev = 0, morethanone;

		cin >> s;
		n = s.size();

		for(i = 0; i < n; i++)
			{
				if(!isvowel(s[i]))
					{
						if(vs[s[i]] == 0) maxc++;
						else if(vs[s[i]] > 0) morethanone = 1;
						vs[s[i]]++;
					}
				else
					{
						for(j = 'a'; j <= 'z'; j++) vs[j] = 0;
						maxc = 0;
					}

				// cout << i << " " << maxc << endl;

				if(maxc > 2 || (maxc == 2 && morethanone == 1))
					{
						for(j = prev; j < i; j++)
							{
								if(!isvowel(s[j]))
									{
										vs[s[j]]--;
										if(vs[s[j]] == 0) maxc--;
									}

								cout << s[j];
							}

						morethanone = 0;
						cout << " "; prev = i;
					}
			}

		if(prev <= n - 1)
			{
				for(i = prev; i < n; i++)
					cout << s[i];
			}
		cout << endl;

		return 0;
	}