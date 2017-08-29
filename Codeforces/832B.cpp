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

bool good[26];

int main()
{
    string goodChars, S, s;
    int Q, N, M, i, j;
    bool ans;

    cin >> goodChars;

    for(int i = 0; i < goodChars.size(); i++)
		good[goodChars[i] - 'a'] = 1;
    
    cin >> S >> Q, N = S.size();

    while(Q--)
	    {
	        cin >> s, M = s.size();
	        ans = 1;

	        for(i = 0; i < S.size(); i++)
		        {
		            if(S[i] == s[i]) 
		            	continue;
		            else if(S[i] == '?')
			            {
			                if(good[s[i] - 'a']) 
			                	continue;
			                else
				                {
				                    ans = 0;
				                    break;
				                }
			            }
		            else if(S[i] == '*')
			            {
			                if(i == (N - 1))
				                {

				                    if(M < N) 
				                    	break;
				                    for(j = i; j < M; j++)
					                    {
					                        if(!good[s[j] - 'a']) 
					                        	continue;
					                        else
						                        {
						                            ans = 0;
						                            break;
						                        }
					                    }
				                }
			                else
				                {
				                    for(j = i; j < M; j++)
					                    {
					                        if(!good[s[j] - 'a'])
					                        	continue;
					                        else 
					                        	break;
					                    }
				                    i = j - 1;
								}
			            }
		            else if(S[i] != s[i])
			            {
			                ans = 0;
			                break;
			            }

		        }

	        if(!ans) cout << "NO" << endl;
			else cout << "YES" << endl;
	    }

	   return 0;
}
