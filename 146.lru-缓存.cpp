/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
    int cap;
    class Page{
    public:
        Page(int k, int v) : key(k), value(v), next(nullptr) { }
        int key;
        int value;
        Page* next;
        Page* pre;
    };
    Page* head;
    unordered_map<int, Page*> hash;
    int size;
public:
    LRUCache(int capacity) : cap(capacity), size(0){
        head = new Page(-1, -1);
        head->next = head;
        head->pre = head;
    }
    
    int get(int key) {
        if(hash.find(key) != hash.end()){
            Page* page = hash[key];
            int value = page->value;
            page->next->pre = page->pre;
            page->pre->next = page->next;
            page->pre = head;
            page->next = head->next;
            head->next->pre = page;
            head->next = page;
            return value;
        } 
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        Page* page = nullptr;
        if(hash.find(key) != hash.end()){
            page = hash[key];
            page->value = value;
            page->next->pre = page->pre;
            page->pre->next = page->next;
        }
        else{
            if(size >= cap){
                Page* preNode = head->pre->pre;
                Page* node = head->pre;
                preNode->next = node->next;
                head->pre = preNode;
                node->next = nullptr;
                node->pre = nullptr;
                hash.erase(node->key);
                delete node;
                size--;
            }
            page = new Page(key, value);
            size++;
        }
        page->next = head->next;
        page->pre = head;
        head->next->pre = page;
        head->next = page;
        if(size == 1){
            head->pre = page;
        }
        hash[key] = page;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

