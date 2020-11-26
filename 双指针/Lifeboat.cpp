/**
 * 救生艇问题
 * [https://leetcode-cn.com/problems/boats-to-save-people/]
 **/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int p = 0;
        int q = people.size() - 1;
        int num = 0;
        while (p < q)
        {
            if (people[p] + people[q] <= limit)
            {
                num++;
                p++;
                q--;
            }
            else
            {
                num++;
                q--;
            }
            if (p == q)
            {
                num++;
            }
            
        }
        return num;
    }
};

int main()
{
    Solution solution;
    vector<int> list;
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(1);
    cout << solution.numRescueBoats(list, 3) << endl;
    return 0;
}