/**
 * 爬楼梯问题
 * [https://leetcode-cn.com/problems/climbing-stairs/]
 **/
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2)
        {
            return 1;
        }
        
        int num[n+1];
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            num[i] = num[i-1] + num[i-2];
        }
        return num[n];
    }
};

int main() {
    Solution solution;
    cout << solution.climbStairs(44);
}   