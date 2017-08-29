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
		ifstream fin ("cowcode.in");
		ofstream fout ("cowcode.out");

		string s;
		lli n, i, pos, copy;

		fin >> s >> pos;

		while(s.size()<pos)
			{
				n=s.size();
				string x (s, 0, n-1);
				cout << x << endl;
				x=s[n-1]+x;
				s=s+x;
				//cout << x << " " << s << endl;
			}

		fout << s[pos-1] << endl;
		return 0;
	}