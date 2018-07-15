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

char lw(char x)
{
	if(x >= 'A' && x <= 'Z') return x - 'A' + 'a';
	return x;
}

string ret(char a)
{
	switch(a)
		{
			case 'a': return "@";
			case 'b': return "8";
			case 'c': return "(";
			case 'd': return "|)";
			case 'e': return "3";
			case 'f': return "#";
			case 'g': return "6";
			case 'h': return "[-]";
			case 'i': return "|";
			case 'j': return "_|";
			case 'k': return "|<";
			case 'l': return "1";
			case 'm': return "[]\\/[]";
			case 'n': return "[]\\[]";
			case 'o': return "0";
			case 'p': return "|D";
			case 'q': return "(,)";
			case 'r': return "|Z";
			case 's': return "$";
			case 't': return "']['";
			case 'u': return "|_|";
			case 'v': return "\\/";
			case 'w': return "\\/\\/";
			case 'x': return "}{";
			case 'y': return "`/";
			case 'z': return "2";
		}
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j;

		getline(cin, s);
		n = s.size();

		for(i = 0; i < n; i++)
			{
				if(s[i] >= 'A' && s[i] <= 'Z')
					cout << ret(lw(s[i]));
				else if(s[i] >= 'a' && s[i] <= 'z')
					cout << ret(s[i]);
				else cout << s[i];
			}

		return 0;
	}