/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
/*
我们很容易想到先上截止日期近，持续时间短的课，但是当两者冲突的时候，如何取舍就成了最为关键的问题
我们可以给截止日期和持续时间做一个优先级排序，肯定是截止日期近的优先级更高
所以我们先把课程按照截止日期排序，如果截至日期相同，持续时间短的课程排在前面
然后我们一门一门地上课
突然有一天发现前面上的课加上手上要上的这一门课超时了！
这个时候我们肯定要舍弃掉一门课，舍弃掉哪一门课呢？当然是时间最长的那一门啊！
我们观看了一下手上的课和前面上的所有的课，丢掉了最长的课，然后头也不回的走向了下一门课
终于，课全部上光了
看了一看课表，我们露出了充实的笑容 (￣▽￣)""(●ˇ∀ˇ●)
*/
class BigHeap {
public:
    bool empty() {
        return m_arr.empty();
    }
    unsigned int size() {
        return m_arr.size();
    }
    int pop() {
        int temp = m_arr[0];
        swap(0, m_arr.size() - 1);
        m_arr.pop_back();
        heapify(0);
        return temp;
    }
    int front() {
        return m_arr[0];
    }
    void emplace(int& index, int& a) {
        if (index >= m_arr.size())return;
        m_arr[index] = a;
        heapInsert(index);
        heapify(index);
    }
    void emplace_back(int& a) {
        m_arr.emplace_back(a);
        heapInsert(m_arr.size() - 1);
    }
private:
    vector<int> m_arr;
    void heapInsert(int index) {
        while (m_arr[index] > m_arr[(index - 1) / 2]) {//如果孩子比父大
            swap(index, (index - 1) / 2);//交换父与孩子的位置
            index = (index - 1) / 2;//更新孩子的位置
        }
    }
    void heapify(int index) {
        int size = m_arr.size();
        int left = 2 * index + 1;//左孩子下标
        while (left < size) {//如果左孩子的下标没有越界
            int largest = left + 1 < size && m_arr[left + 1] > m_arr[left] ? left + 1 : left;//如果存在右孩子且右孩子比左孩子大，两个孩子种较大的是右孩子
            largest = m_arr[index] > m_arr[largest] ? index : largest;//求父与两个孩子中的最大值
            if (largest == index)break;//如果父比孩子都大，结束循环
            swap(index, largest);//交换父与大孩子的位置
            index = largest;//更新父的坐标
            left = 2 * index + 1;//更新父的左孩子坐标重复循环
        }
    }
    void swap(int i, int j) {
        int tmp = m_arr[i];
        m_arr[i] = m_arr[j];
        m_arr[j] = tmp;
    }
};
class Solution {
public:
    static bool cmp(const vector<int> a,const vector<int> b){
        if(a[1]==b[1])return a[0]<b[0];
        else return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        BigHeap big;
        sort(courses.begin(),courses.end(),cmp);
        int sum=0;
        for(auto a:courses){
            if(a[0]+sum<=a[1]){
                big.emplace_back(a[0]);
                sum+=a[0];
            }else{
                if(!big.empty()){
                    if(a[0]<big.front()){
                        sum-=big.pop()-a[0];
                        big.emplace_back(a[0]);
                    }
                }
            }
        }
        return big.size();
    }
};
// @lc code=end

