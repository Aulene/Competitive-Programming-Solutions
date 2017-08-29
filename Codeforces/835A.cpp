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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int s, v1, v2, t1, t2;

		cin >> s >> v1 >> v2 >> t1 >> t2;

		int fst = 2 * t1 + s * v1, scnd = 2 * t2 + s * v2;
		
		if(fst < scnd)
			cout << "First" << endl;
		else if(scnd < fst)
			cout << "Second" << endl;
		else
			cout << "Friendship" << endl;

		return 0;
	}