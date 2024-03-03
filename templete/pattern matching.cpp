#include <iostream>
#include <string>
#include <vector>

using namespace std;

//BF算法 brue force 即暴力
vector<int> match_bf(string s, string t, int n, int m) // s 待匹配串 t 模式串 n主串长度 m模式串长度;
{
    vector<int> ans;
    int i,j;
    for(i = 0; i < n - m + 1; i ++)
    {
        for(j = 0; j < m; j ++)
        {
            if(s[i + j] != t[j]) break;
        }
        if(j == m) ans.push_back(i);
    }
    return ans;
}


int main()
{
    
    return 0;
}