# 146. LRU Cache

[https://leetcode.com/problems/lru-cache/description/](https://leetcode.com/problems/lru-cache/description/)

## Keynote

- LinkedHashMap
  - HashMap (key, ListNode*)
  - DoubleList (ListNode*)
- LRUCache
  - `makeRecently`
  - `addRecently`
  - `deleteByKey`
  - `removeLeastRecently`

```cpp
typedef pair<int, int> pii;

class LRUCache {
private:
    int cap;
    list<pii> cache;
    unordered_map<int, list<pii>::iterator> mp;
    void makeRecently(int key) {
        pii x = *mp[key];
        cache.erase(mp[key]);
        cache.push_front(x);
        mp[key] = cache.begin();
    }
    void addRecently(int key, int val) {
        pii x = {key, val};
        cache.push_front(x);
        mp[key] = cache.begin();
    }
    void deleteByKey(int key) {
        cache.erase(mp[key]);
        mp.erase(key);
    }
    void removeLeastRecently() {
        pii tail = *(--cache.end());
        cache.pop_back();
        mp.erase(tail.first);
    }
public:
    LRUCache(int capacity): cap(capacity) {
        
    }
    
    int get(int key) {
        if (!mp.count(key))
            return -1;
        makeRecently(key);
        return (*mp[key]).second;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            deleteByKey(key);
            addRecently(key, value);
            return;
        }

        if (cap == cache.size())
            removeLeastRecently();
        addRecently(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
