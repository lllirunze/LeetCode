/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    queue<int> q1;
    queue<int> q2;
    int compare(queue<int> q1, queue<int> q2){
        int c1, c2;
        // q1 q2还没有全空
        while(!(q1.empty() && q2.empty())){
            // q1已空，q2未空
            if(q1.empty()){
                if(q2.front() == 0) q2.pop();
                else return -1;
            }
            // q2已空，q1未空
            else if(q2.empty()){
                if(q1.front() == 0) q1.pop();
                else return 1;
            }
            // q1 q2均未空
            else{
                if(q1.front() > q2.front()) return 1;
                else if(q2.front() > q1.front()) return -1;
                else{
                    q1.pop();
                    q2.pop();
                }
            }
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        int tmp = 0;
        for(int i=0; i<version1.length(); i++){
            if(version1[i] == '.'){
                q1.push(tmp);
                tmp = 0;
            }
            else tmp = tmp*10 + (version1[i]-'0');
        }
        q1.push(tmp);
        tmp = 0;
        for(int i=0; i<version2.length(); i++){
            if(version2[i] == '.'){
                q2.push(tmp);
                tmp = 0;
            }
            else tmp = tmp*10 + (version2[i]-'0');
        }
        q2.push(tmp);
        return compare(q1, q2);
    }
};
// @lc code=end

