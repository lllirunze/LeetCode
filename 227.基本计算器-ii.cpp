/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int act[4][4]={};
    void init()
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if((i==0||i==1)&&(j==2||j==3)) act[i][j]=0;
                else act[i][j]=1;
    }
    int f(char c){
        if(c=='+') return 0;
        if(c=='-') return 1;
        if(c=='*') return 2;
        return 3;
    };
    int calculate(string s) {
        init();
        stack<int> ns;
        stack<int> os;
        int temp_num=0;
        for(int i=0;i<s.length();i++)
        {
            //printf("%d\n",i);
            char c=s[i];
            if(c-'0'==-16) continue;
            if(c-'0'>=0)
            {
                temp_num*=10;
                temp_num+=c-'0';
                continue;
            }
            ns.push(temp_num);
            temp_num=0;
            int ope=f(c);
            if(os.empty()){
                os.push(ope);
                continue;
            }
            while(!os.empty()&&act[os.top()][ope])
            {
                int a=ns.top();
                ns.pop();
                int b=ns.top();
                ns.pop();
                if(os.top()==0) ns.push(b+a);
                if(os.top()==1) ns.push(b-a);
                if(os.top()==2) ns.push(b*a);
                if(os.top()==3) ns.push(int(b/a));
                os.pop();
            }
            os.push(ope);
        }
        ns.push(temp_num);
        while(!os.empty())
        {
            int a=ns.top();
            ns.pop();
            int b=ns.top();
            ns.pop();
            if(os.top()==0) ns.push(b+a);
            if(os.top()==1) ns.push(b-a);
            if(os.top()==2) ns.push(b*a);
            if(os.top()==3) ns.push(int(b/a));
            os.pop();
        }
        return ns.top();
    }
};
// @lc code=end

