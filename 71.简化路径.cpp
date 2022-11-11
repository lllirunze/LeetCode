/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        istringstream iss(path);
        string buf;
        while (getline(iss, buf, '/')) {
            if (!buf.empty() && buf != "." && buf != "..") {
                v.push_back(buf);
            } else if (!v.empty() && buf == "..") {
                v.pop_back();
            }
        }
        if (v.empty()) {
            return "/";
        }

        buf.clear();
        for (string &s : v) {
            buf += "/";
            buf += s;
        }
        return buf;
    }
};
// @lc code=end

