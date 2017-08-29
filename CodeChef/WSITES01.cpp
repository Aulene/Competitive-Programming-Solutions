// Used Tries template from http://www.geeksforgeeks.org/trie-insert-and-search/

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

struct node
{
	struct node *child[107];
	bool leaf;
};

struct node *createNodes(void)
{
	int i;
	struct node *parentNode = (struct node *)malloc(sizeof(struct node));

	parentNode -> leaf = 0;

	for(i=0; i<107; i++)
		parentNode -> child[i] = NULL; 

	return parentNode;
}

int addNode(struct node *rt, string s)
{
	int l = s.size(), i, childN;
	struct node *parentTravel = rt;
	
	for(i=0; i<l; i++)
		{
			childN = s[i] - 'a';

			if(!parentTravel -> child[childN])
				parentTravel -> child[childN] = createNodes();
			parentTravel = parentTravel -> child[childN];
		}

	parentTravel -> leaf = 1;
	return 0;
}

int findAns(struct node *rt, string s)
{
	int l = s.size(), i, childN;
	struct node *parentTravel = rt;

	for(i=0; i<l; i++)
		{
			childN = s[i] - 'a';

			if(!parentTravel -> child[childN])
				return i;

			parentTravel = parentTravel -> child[childN];
		}

	return l;
}

vector <string> allow, block, answers;
map <string, int> m;
struct node *tree = createNodes();

int main()
	{
		int n, i, j, length;
		char op;
		string s;

		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> op >> s;

				if(op == '-')
					block.pb(s);
				else
					{
						allow.pb(s);
						addNode(tree, s);
					}
			}

		for(i=0; i<block.size(); i++)
			{
				length = findAns(tree, block[i]);

				if(length == block[i].size())
					{
						cout << "-1" << endl;
						exit(0);
					}
				else
					{
						length++;

						if(m.find(block[i].substr(0, length)) == m.end())
							{
								m[block[i].substr(0, length)] = 1;
								answers.pb(block[i].substr(0, length));
							}
					}
			}

		sort(answers.begin(), answers.end());

		cout << answers.size() << endl;

		for(i=0; i<answers.size(); i++)
			cout << answers[i] << endl;

 		return 0;
	}