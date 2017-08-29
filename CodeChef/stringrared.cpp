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
 
int main()
{
    int t,i,j,k,l,o,p;
    cin >> t;
    for (i = 0 ; i < t ; i++)
    {
        int n,m;
        cin >> n >> m;
        vector<int> adjList[n + 1];
        for (j = 0 ; j < m ; j++)
        {
            int l,r;
            cin >> l >> r;
            adjList[l].push_back(r);
        }
        vector<int> ans(n + 1,0);
        int x = 1;
        for (j = 0 ; j <= n ; j++)
            sort(adjList[j].begin(),adjList[j].end());
        for (j = 0 ; j < adjList[0].size() ; j++)
        {
            ans[adjList[0][j]] = x;
            x++;
        }
        int flag = 0;
        for (j = 1 ; j < n ; j++)
        {
            if (adjList[j].size() == 1)
            {
                int temp=0,count=0;
                for (int k = adjList[j][0] ; k <= n ; k++)
                {
                    if (ans[k] != 0)
                    {
                        temp = ans[k];
                        count++;
                    }
                }
                if (count > 1)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    // cout << j << " " << temp << endl;
                    for (int k = adjList[j][0] ; k <= n ; k++)
                    {
                        if (ans[k] == 0)
                            ans[k] = temp;
                    }
                    // for (o = 1 ; o <= n ; o++)
                    //     cout << ans[o] << " ";
                    // cout << "\n";
                }
            }
            else
            {
                for (k = 1 ; k < adjList[j].size() ; k++)
                {
                    if (adjList[j][k] - adjList[j][k - 1] == 1)
                    { 
                        if (ans[adjList[j][k]]!= 0 && ans[adjList[j][k] - 1] != 0)
                        {
                            for (l = adjList[j][k - 1] + 1; l < adjList[j][k] ; l++)
                            {
                                // if (ans[l]!= 0 && ans[l - 1] != 0 && ans[l] != ans[l - 1])
                                // {
                                //     flag = 1;
                                //     break;
                                // }
                            }
                            if (flag == 1)
                                break;
                        }
                    }
                    else if ((adjList[j][k] - adjList[j][k - 1]) != 1)
                    {
                        for (l = adjList[j][k - 1] ; l < adjList[j][k] ; l++)
                        {
                            if (ans[l] == 0)
                                ans[l] = j;
                        }
                    }
                }
                //for (l = 1 ; l <= n ; l++)
                //  cout << ans[l] << " ";
                //cout << "\n";
                if (flag == 1)
                    break;
            }
        }

        cout << flag << endl;
        if (flag == 0)
        {
            int flag1 = 0;
            vector<int> f1(x + 1,0);
            //for (j = 1 ; j <= n ; j++)
                //cout << ans[j] << endl;
            //cout << "\n";
            for (j = 1 ; j <= n ; j++)
            {   
                cout << j << " " <<  flag1 << endl;
                if (f1[ans[j]] == 1)
                {
                    if (find(adjList[0].begin(),adjList[0].end(),j) != adjList[0].end())
                    {
                        cout << "-1\n";
                        flag1 = 1;
                        // break;
                    }
                }
                else 
                    f1[ans[j]] = 1;
            }

            if (flag1 == 0)
            {
                for (int l = 1 ; l <= n ; l++)
                    cout << ans[l] << " ";
                cout << "\n";
            }
        }
        else
            cout << "-1\n";
    }
    return 0;
}