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

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

int main()
	{
		int t, n, i;
		char prev, next;
		string s;
		bool ans;

		cin >> t;

		while(t--)
			{
				ans=1;

				cin >> n >> s;
				next = 'H';

				for(i=0; i<n; i++)
					{
						if(s[i] != '.')
							{
								if(next == 'T' && s[i] == 'T')
									next = 'H';
								else if (next == 'H' && s[i] == 'H')
									next = 'T';
								else
									ans = 0;
							}
					}

				if(next == 'T')
					ans=0;
				
				if(ans)
					cout << "Valid" << endl;
				else
					cout << "Invalid" << endl;
			}

		return 0;
	}