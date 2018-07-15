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

// vector < pair <string, int> > vs;
unordered_map <string, int> m;
unordered_map <string, bool> def;
unordered_map <int, string> M;
unordered_map <int, bool> def2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s, s1, s2, op, op2;
		int num, ansx;
		bool ans;

		while(cin >> s)
			{	
				if(s == "def")
					{
						cin >> s1 >> num;
						// vs.pb(mp(s1, num));
						m[s1] = num;
						def[s1] = 1;
						def2[num] = 1;
						M[num] = s1;
					}
				else if(s == "calc")
					{
						ansx = 1;
						int ans = 0;

						cin >> s1 >> op;

						if(def[s1] == 0) ansx = 0;
						ans += m[s1];

						cout << s1 << " " << op;

						while(cin >> s2 >> op2)
							{
								cout << " " << s2 << " " << op2;
								if(def[s2] == 0) ansx = 0;
								
								if(op == "+") ans += m[s2];
								else ans -= m[s2];

								op = op2;
								if(op == "=") break;
							}

						if(ansx == 0 || def2[ans] == 0) cout << " unknown" << endl;
						else cout << " " << M[ans] << endl; 
					}
				else
					{
						m.clear();
						M.clear();
						def.clear();
						def2.clear();
					}
			}
		return 0;
	}