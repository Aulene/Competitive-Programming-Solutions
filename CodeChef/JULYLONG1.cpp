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

vector<string > v;

bool lowercase(char s)
{
	if(s >= 'a' && s <= 'z')
		return true;
	return false;
}

signed main()
	{
		int t, n, i, j;
		string s;

		cin >> t;
		t++;

		while(t--)
			{
				int spaces = 0;

				// cout << s << endl;

				getline(cin, s);
				n = s.size();

				for(i = 0; i < n; i++)
					if(s[i] == ' ')
						spaces++;

				for(i = 0; i < n; i++)
					{
						if(!spaces)
							{
								if(lowercase(s[i]))
									cout << char(s[i] - 32);
								else
									cout << s[i];
								i++;

								for(; i < n; i++)
									{
										if(!lowercase(s[i]))
											cout << char(s[i] + 32);
										else
											cout << s[i];
									}
							}
						else
							{
								if(lowercase(s[i]))
									cout << char(s[i] - 32);
								else
									cout << s[i];
								i++;
								cout << ". ";

								while(s[i] != ' ')
									i++;
								
								// cout << "FKIN WORK " << i << endl;
								spaces--;
							}
					}

				cout << endl;
			}	

		return 0;
	}