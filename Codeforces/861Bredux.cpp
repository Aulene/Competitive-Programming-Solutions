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
 
int r[1000], f[1000];
 
 
int main()
{
	int who, m;
	scanf("%d %d", &who, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &r[i], &f[i]);
	}
	int kol = 0, ans = 0;
	for (int i = 1; i <= 100; i++)
	{
		bool fl = true;
		for (int j = 0; j < m; j++)
		{
			if ((r[j] + i - 1) / i != f[j])
			{
				fl = false;
				break;
			}
		}
		if (fl)
		{
			ans = i;
			kol++;
		}
	}
	if (kol > 1)
	{
		printf("-1");
	}
	else
	{
		printf("%d", (who + ans - 1) / ans);
	}
}