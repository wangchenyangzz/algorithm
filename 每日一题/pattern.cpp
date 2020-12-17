/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        if (pattern.size() == 0 && s.size() == 0)
        {
            return true;
        }
        map<char, int> map1;
        map<string, int> map2;
        vector<string> vector = split(s, " ");
        if (pattern.size() != vector.size())
        {
            return false;
        }
        map<char, int>::iterator iter1;
        map<string, int>::iterator iter2;  
        for (int i = 0; i < pattern.size(); i++)
        {
            iter1 = map1.find(pattern[i]);
            if (iter1 == map1.end())
            {
                map1.insert(pair<char, int>(pattern[i], i));
            }
            iter2 = map2.find(vector[i]);
            if (iter2 == map2.end())
            {
                map2.insert(pair<string, int>(vector[i], i));
            }
            if (iter1 == map1.end() && iter2 != map2.end())
            {
                return false;
            } else if(iter1 != map1.end() && iter2 == map2.end())
            {
                 return false;
            } else if (iter1 != map1.end() && iter2 != map2.end()) {
                if (iter1->second != iter2->second )
                {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> split(const string &str, const string &pattern)
    {
        vector<string> res;
        if (str == "")
            return res;
        //在字符串末尾也加入分隔符，方便截取最后一段
        string strs = str + pattern;
        size_t pos = strs.find(pattern);

        while (pos != strs.npos)
        {
            string temp = strs.substr(0, pos);
            res.push_back(temp);
            //去掉已分割的字符串,在剩下的字符串中进行分割
            strs = strs.substr(pos + 1, strs.size());
            pos = strs.find(pattern);
        }

        return res;
    }
};

int main()
{
    Solution solution;
    string in1;
    string in2;
    cin >> in1;
    cin >> in2;
    cout << solution.wordPattern(in1, in2) << endl;
    return 0;
}
