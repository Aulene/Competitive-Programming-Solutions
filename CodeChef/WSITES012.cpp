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
struct TrieNode
{
    struct TrieNode *children[26];
    bool isLeaf;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    pNode->isLeaf = false;
    for(int i=0;i<26;i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    int length = key.length();
    struct TrieNode *pCrawl = root;
 
    for (int level = 0; level < length; level++)
    {
        int index = (int)key[level] - (int)'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isLeaf = true;
}
 
int search(struct TrieNode *root, string key)
{
    int level;
    int length = key.length();
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = (int)key[level] - (int)'a';
 
        if (!pCrawl->children[index])
            return level;
 
        pCrawl = pCrawl->children[index];
    }
 
    return level;
}

int answ(struct TrieNode *rt, string s)
{
    int l = s.size(), i, childN;
    struct TrieNode *parentTravel = rt;

    for(i=0; i<l; i++)
        {
            childN = s[i] - 'a';

            if(!parentTravel -> children[childN])
                return childN;
            parentTravel = parentTravel -> children[childN];
        }

    return l;
}

int main()
{
    struct TrieNode *rootAllowed = getNode();
    int n;
    cin>>n;
    vector<string> allowed;
    vector<string> blocked;
    for(int i=0;i<n;i++)
    {
        char ch;
        cin>>ch;
        string s;
        cin>>s;
        if(ch=='-')
        {
            blocked.push_back(s);
        }
        else
        {
            allowed.push_back(s);
            insert(rootAllowed, s);
        }
    }
    
    vector<string> ans;
    map<string,int> m;
    for(int i=0;i<blocked.size();i++)
    {
        int len = answ(rootAllowed, blocked[i]);
        if(len == blocked[i].length())
        {
            cout<<-1;
            return 0;
        }
        else
        {
            len++;
            if(m.find(blocked[i].substr(0,len))==m.end())
            {
                m[blocked[i].substr(0,len)]=1;
                ans.push_back(blocked[i].substr(0,len));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"\n"; 
    return 0;
}