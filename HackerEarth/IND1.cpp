#include <iostream>
using namespace std;

int a[107];
int prefix[107], prefixMax[107];

int main()
{
    int n, i, x, ans = 0, numOnes = 0, maxSub = 0;
    
    cin >> n;
    
    for(i=1; i<=n; i++)
        {
            cin >> a[i];
            if(a[i])
                numOnes++;
        }
    
    for(i=1; i<=n; i++)
        if(a[i])
            prefix[i] = prefix[i-1] + 1;
        else
            prefix[i] = 0;


    for(i=n; i>=1; i--)
        if(prefix[i])
            {
                x = i;

                while(prefix[i])
                    {
                        prefixMax[i] = prefix[x];
                        i--;
                    }
            }

    for(i=1; i<=n; i++)
        maxSub = max(prefixMax[i], maxSub);

    for(i=1; i<=n; i++)
        {
            ans = max(ans, prefixMax[i]);

            if(a[i+1] == 0 && i+2 <= n)
                {
                    ans = max(ans, prefixMax[i] + prefixMax[i+2]);

                    if(numOnes > prefixMax[i] + prefixMax[i+2])
                        ans = max(ans, prefixMax[i] + prefix[i+2] + 1);
                }
        }

    for(i=n; i>=1; i--)
        {
            ans = max(ans, prefixMax[i]);

            if(a[i-1] == 0 && i-2 >= 1)
                {
                    ans = max(ans, prefixMax[i] + prefixMax[i-2]);

                    if(numOnes > prefixMax[i] + prefixMax[i-2])
                        ans = max(ans, prefixMax[i] + prefix[i-2] + 1);
                }
        }

    if(numOnes > maxSub)
        ans = max(ans, maxSub + 1);

    cout << ans << endl;

    return 0;
}
