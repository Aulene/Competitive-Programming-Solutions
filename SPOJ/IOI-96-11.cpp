#include<iostream>
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

int n;
int a[107];
int p1ans=0, p2ans=1000001;

int recur(int player, int L, int R, int player1, int player2)
{
	if(L==R)
		{
			if(player==1)
				player1+=a[L];
			else
				player2+=a[L];

			if(abs(player1-player2)<abs(p2ans-p1ans))
				{
					p1ans=player1;
					p2ans=player2;
				}

			if(player1 > player2)
				return 1;
			else if(player2 > player1)
				return 2;
			else
				{
					if(player==1)
						return 2;
					else
						return 1;
				}
		}

	int ans1, ans2, ans;
	if(player==1)
		{
			ans1=recur(2, L+1, R, player1+a[L], player2);
			ans2=recur(2, L, R-1, player1+a[R], player2);
		
			if(ans1==ans2)
				return ans1;
			else
				return player;
		}
	else
		{
			ans1=recur(1, L+1, R, player1, player2+a[L]);
			ans2=recur(1, L, R-1, player1, player2+a[R]);

			if(ans1==ans2)
				return ans1;
			else
				return player;
		}
}

int main()
	{
		int i;
		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		int ans=recur(1, 0, n-1, 0, 0);
		cout << ans << endl;
		cout << p1ans << " " << p2ans << endl;
		return 0;
	}