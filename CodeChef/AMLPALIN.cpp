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
#define pb push_back

map<string, int> occ;

int main()
	{
		int t, n, i;
		string s;

		
		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i=0; i<n; i++)
					{
						cin >> s;
						occ[s]++;
					}


			}

		return 0;
	}