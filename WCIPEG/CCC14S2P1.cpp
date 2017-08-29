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

char a[2007][2007];
int dp[2007][2007];

int main()
    {
        int i, j, n;
        int ans=0;

        cin >> n;

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                cin >> a[i][j];

        for(i=n-1; i>=0; i--)
            for(j=0; j<n; j++)
                {
                    if(a[i][j]!='#')
                        dp[i][j]=0;
                    else if(i==n-1 || j==0 || j==n-1 || a[i+1][j]!='#')
                        dp[i][j]=1;
                    else 
                        dp[i][j]=1+min(dp[i+1][j-1], dp[i+1][j+1]);
                    ans+=dp[i][j];
                }

        /*
        for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                    cout << dp[i][j] << " ";
                cout << endl;
            }
        */

        cout << ans << endl;
        return 0;
    }