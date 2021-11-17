/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (68.77%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    37.8K
 * Total Submissions: 51.8K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给定一个字符串数组 words，找到 length(word[i]) * length(word[j])
 * 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出: 16 
 * 解释: 这两个单词为 "abcw", "xtfn"。
 * 
 * 示例 2:
 * 
 * 
 * 输入: ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出: 4 
 * 解释: 这两个单词为 "ab", "cd"。
 * 
 * 示例 3:
 * 
 * 
 * 输入: ["a","aa","aaa","aaaa"]
 * 输出: 0 
 * 解释: 不存在这样的两个单词。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * 1 
 * words[i] 仅包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()==0) return 0;        
        int len=words.size();
        int *arr=new int[len]();
        for(int i=0;i<len;i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                int index=words[i][j]-'a';
                if(((sum>>index)&1)==0) sum=sum+(1<<index);                
            }
            arr[i]=sum;
        }
        int maxlen=0;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if((arr[i]&arr[j])==0){
                    int plen=words[i].size()*words[j].size();
                    maxlen=max(maxlen,plen);
                }
            }
        }
        return maxlen;
    }
};
// @lc code=end

