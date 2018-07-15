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

unordered_map <string, int> nums;
unordered_map <string, pair <string, string> > names;
vector <string> vs;

signed main()
	{
		ifstream cin ("lol.txt");
		ofstream cout ("ans.txt");

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;
		string s, s1, s2, s3, s4;

		cin >> t;

		while(t--)
			{
				cin >> n;

				while(n--)
					{
						cin >> s1 >> s2 >> s3 >> s4;
						cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
						if(nums[s3] == 0)
							vs.pb(s3);
						
						nums[s3]++;
						names[s3] = mp(s1, s2);
					}
			}

		for(j = 1; j <= 5; j++)
			{
				cout << j << " CLASSES -\n";

				for(i = 0; i < vs.size(); i++)
					{
						if(nums[vs[i]] == j)
						cout << names[vs[i]].f << " " << names[vs[i]].s << " " << vs[i] << endl;
					}
			}
		return 0;
	}