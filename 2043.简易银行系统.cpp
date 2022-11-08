/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */

// @lc code=start
class Bank {
public:
    vector<long long> balance;
    int accountNum;
    Bank(vector<long long>& balance) {
        this->balance = balance;
        this->accountNum = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > accountNum || account2 > accountNum)
            return false;
        if(balance[account1 - 1] >= money){
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account > accountNum)
            return false;
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > accountNum)
            return false;
        if(balance[account - 1] >= money){
            balance[account - 1] -= money;
            return true;
        }
        return false;   
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end

