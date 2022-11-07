/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        // 放入每一段的线程ID，和对应的时间（开始时间，结束时间通用位置）
        // log的顺序必然符合栈调用的顺序，无需在做任何处理
        stack<pair<int, int>> stk;
        vector<int> res(n, 0);
        for (auto& log : logs) {
            vector<string> splitRes = Split(log);
            int id = stoi(splitRes[0]);
            int time = stoi(splitRes[2]);
            if ("start" == splitRes[1]) {
                stk.push({id, time});
            } else {
                auto pop = stk.top();
                stk.pop();
                int interval = time - pop.second + 1;
                // 有可能存在递归调用的情况，所以要+=
                res[pop.first] += interval;
                // 如果栈不空，这是处理那种中间被突然占用的函数的，由于最后一步算interval的方式都一样，所以在中间直接占用的直接减去就好，最后在加最后的总interval，那就是恰好是剩下的时间。
                if (!stk.empty()) {
                    res[stk.top().first] -= interval;
                }
            }
        }
        return res;
    }

    vector<string> Split(string& log)
    {
        vector<string> res;
        stringstream ss(log);
        string tmp = "";
        while (getline(ss, tmp, ':')) {
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end

