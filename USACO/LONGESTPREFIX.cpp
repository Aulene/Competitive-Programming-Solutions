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

vector<string> p;

int main()
	{
		string s;
		vector<string>::iterator it;

		s=" ";

		while(s!=".")
			{
				cin >> s;

				if(s==".")
					break;

				p.pb(s);
			}

		cin >> s;
		return 0;
	}