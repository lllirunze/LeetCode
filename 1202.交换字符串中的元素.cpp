/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> p;
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    void merge(int x,int y){
        int p1=find(x),p2=find(y);
        if(p1==p2) return ;
        p[p1]=p2;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size(),length=pairs.size();
        p=vector<int>(n);
        for(int i=0;i<n;i++) p[i]=i;
        for(int i=0;i<length;i++){
            merge(pairs[i][0],pairs[i][1]);
        }
        map<int,vector<char>> m;
        for(int i=0;i<n;i++){
            if(m.count(find(i))==0){
                vector<char> tmp;
                m[find(i)]=tmp;
            }
            m[find(i)].push_back(s[i]);
        }
        for(auto it=m.begin();it!=m.end();it++){
            sort(it->second.begin(),it->second.end(),greater<char>());
        }
        for(int i=0;i<n;i++){
            s[i]=m[find(i)].back();
            m[find(i)].pop_back();
        }
        return s;
    }
};
// @lc code=end

