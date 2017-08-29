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

struct participant
{
	int rollno;
	int score;
	int rank;
	int solved;
};

int worth[2007];
int nums[2007][2007];
participant ps[2007];

bool compare(participant a, participant b)
{
	if(a.score!=b.score)
		return a.score > b.score;

	if(a.solved!=b.solved)
		return a.solved > b.solved;

	return a.rollno < b.rollno;
}

int main()
	{
		int n, t, p, i, j;

		cin >> n >> t >> p;

		for(i=0; i<n; i++)
			{
				ps[i].score=0;
				ps[i].solved=0;
			}

		for(i=0; i<n; i++)
			{
				ps[i].rollno=i;

				for(j=0; j<t; j++)
					{
						cin >> nums[i][j];

						if(!nums[i][j])
							worth[j]++;
					}
			}

		for(i=0; i<n; i++)
			{
				for(j=0; j<t; j++)
					if(nums[i][j])
						{
							ps[i].score+=worth[j];
							ps[i].solved++;
						}
			}

		sort(ps, ps+n, compare);

		for(i=0; i<n; i++)
			{
				//cout << ps[i].rollno << " " << ps[i].score << " " << ps[i].solved << endl;
				if(ps[i].rollno == p-1)
					cout << ps[i].score << " " << i+1 << endl;
			}
		
		return 0;
	}


